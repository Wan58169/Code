#include <stdio.h>
#include <queue>
#include "Linked.h"

using namespace std;

#define INFINITE 1000

//初始化adjList @newAdjList in heap
AdjList *init_AdjList(int n, int m)
{
    AdjList *newList;

    newList = new AdjList;
    newList->numV = n;
    newList->numE = m;
    newList->list = new AdjNode[n];
    for(int i=0; i<n; i++) {
        newList->list[i].v = i;
        newList->list[i].firstArc =NULL;
    }

    return newList;
}

//释放adjList & ENode
void free_AdjList(AdjList *adjList)
{
    ENode *p, *q;

    //释放边结点
    for(int i=0; i<adjList->numV; i++) {
        p = adjList->list[i].firstArc;
        q = NULL;
        while(p) {
            q = p->next;
            adjList->list[i].firstArc = q;
            delete p;
            p = q; 
        }
    }
    //释放邻接表
    delete[] adjList->list;
    delete adjList;
}

//插入边 @newENode in heap
void insertIntoAdjList(AdjList *adjList, int src, int dest, int weight)
{
    ENode *newENode;

    newENode = new ENode;
    newENode->v = dest;
    newENode->next = adjList->list[src].firstArc;
    adjList->list[src].firstArc = newENode;
}

//dfs
void dfs(AdjList *adjList, int v, int visited[])
{
	ENode *p;

	printf("%d ", v);
	visited[v] = 1;
	for(p=adjList->list[v].firstArc; p; p = p->next) {
        if(!visited[p->v]) {
            dfs(adjList, p->v, visited);
        }
    }
}

//bfs
void bfs(AdjList *adjList, int v)
{
    queue<int> q;
    //visited作用：标记是否已访问
    int *visited;

    visited = new int[adjList->numV];
    
    //访问结点v
    visited[v] = 1;
    q.push(v);

    while(!q.empty()) {
        v = q.front();
        q.pop();
        //访问v的未被访问的邻接点
        for(ENode *p=adjList->list[v].firstArc; p; p=p->next) {
            if(!visited[p->v]) {
                visited[p->v] = 1;
                q.push(p->v);
            }
        }
    }
}

//未被收录的dist最小者
int findMinDist(int collected[], int dist[], int n) 
{
    int min, minIdx;

    min = INFINITE;
    minIdx = -1;

    //遍历
    for(int i=0; i<n; i++) {
        //未被收录 & 目前最小
        if(!collected[i] && min>dist[i]) {
            min = dist[i];
            minIdx = i;
        }
    }

    return minIdx;
}

//最短路径算法 @newArray in heap
void dijkstra(AdjList *adjList, int src, int dest)
{
    //收录集合 dist cost path
    int *collected = new int[adjList->numV];
    int *dist = new int[adjList->numV];
    int *path = new int[adjList->numV];

    //初始化collected dist path
    for(int i=0; i<adjList->numV; i++) {
        dist[i] = INFINITE;
        path[i] = -1;
    }
    collected[src] = 1;
    dist[src] = 0;
    //更新src的邻接点
    for(ENode *p=adjList->list[src].firstArc; p; p=p->next) {
        dist[p->v] = p->weight;
        path[p->v] = src;
    }

    int v;
    while(1) {
        //未被收录的dist最小者
        v = findMinDist(collected, dist, adjList->numV);
        collected[v] = 1;
        //不存在
        if(v == -1) {
            break;
        }
        //更新v的邻接点
        for(ENode *p=adjList->list[v].firstArc; p; p=p->next) {
            //如果没被收录 
            if(!collected[p->v]) {
                if(dist[v]+p->weight < dist[p->v]) {
                    dist[p->v] = dist[v]+p->weight;
                    path[p->v] = v;
                }
            }
        }
    }
    free_dijkstra(collected, dist, path);
}

//释放 @newArray in heap
void free_dijkstra(int *collected, int *dist, int *path, int *cost)
{
    delete[] collected;
    delete[] dist;
    delete[] path;
}
