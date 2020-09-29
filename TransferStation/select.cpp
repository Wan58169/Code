#include "select.h"

//寻找该点到垃圾中转站dist最小者
int __find_all_min_dist(AdjList *adjList, int dist[], int n)
{
    int min, minIdx;

    min = INFINITE;
    minIdx = -1;

    //遍历
    for(int i=1; i<=n; i++) {
        //是垃圾中转站 && 目前最小
        if(__is_transferStation(adjList, i) && min>dist[i]) {
            min = dist[i];
            minIdx = i;
        }
    }

    return minIdx;
}

//未被收录的dist最小者
int __find_min_dist(int collected[], int dist[], int n) 
{
    int min, minIdx;

    min = INFINITE;
    minIdx = -1;

    //遍历
    for(int i=1; i<=n; i++) {
        //未被收录 && 目前最小
        if(!collected[i] && min>dist[i]) {
            min = dist[i];
            minIdx = i;
        }
    }

    return minIdx;
}

//最短路径算法，返回最佳挂载点 @newArray in heap 
int __dijkstra(AdjList *adjList, int src, int dest)
{
    //下标从1开始
    //收录集合 dist path
    int *collected = new int[adjList->numV+1];
    int *dist = new int[adjList->numV+1];
    int *path = new int[adjList->numV+1];

    //初始化collected dist path
    for(int i=1; i<=adjList->numV; i++) {
        collected[i] = 0;       //未收录
        dist[i] = INFINITE;     //无穷大
        path[i] = -1;           //默认为根节点
    }
    //设置src信息
    collected[src] = 1;
    dist[src] = 0;
    //更新src的邻接点
    for(ENode *e=adjList->list[src].firstArc; e; e=e->next) {
        dist[e->vertex] = e->cost;
        path[e->vertex] = src;
    }

    int v;
    while(true) {
        //未被收录的dist最小者
        v = __find_min_dist(collected, dist, adjList->numV);
        collected[v] = 1;
        //不存在，则跳出循环
        if(v == -1) {
            break;
        }
        //更新v的邻接点
        for(ENode *e=adjList->list[v].firstArc; e; e=e->next) {
            //如果没被收录 
            if(!collected[e->vertex]) {
                //“大于”的情况下距离需要更新 
                if(dist[e->vertex] > dist[v]+e->cost) {
                    dist[e->vertex] = dist[v]+e->cost;
                    path[e->vertex] = v;
                } 
            }
        }
    }
    //选出代价最小的挂载点
    v = __find_all_min_dist(adjList ,dist, adjList->numV);

    //free掉 收录集合 dist path
    delete[] collected;
    delete[] dist;
    delete[] path;

    return v;
}

// 为每个社区选择挂载点
void select_mountPoint(AdjList *adjList)
{
    for(int i=1; i<=adjList->numV; i++) {
        // 如果是社区，则选择挂载点
        if(adjList->list[i].isTransferStation == false) {
            //src和dest不能为同一个点 @小聪明
            int src=i, dest;
            dest = (src!=adjList->numV)? src+1: 1;
            //获得最佳挂载点
            int vertex = __dijkstra(adjList, src, dest);
            //设置该点的挂载点
            adjList->list[i].mountPoint = vertex;
        }
    }
}