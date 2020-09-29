#include "adjList.h"
#include <fstream>
#include <iostream>

using namespace std;

//为对应顶点编号设置社区名
void __assignment_community_name(AdjList *adjList)
{
    ifstream readStream;
    //打开读流
    readStream.open("community.txt", ios::in);

    //顶点数
    int N;
    readStream >> N;

    //读入&解析各个顶点
    for(int i=0; i<N; i++) {
        int idx, isTransferStation;     //编号 是否为中转站
        string description;             //描述信息（社区名 or 中转站名）
        //读入
        readStream >> idx >> description >> isTransferStation; 
        //赋值
        adjList->list[idx].vertex = idx;
        adjList->list[idx].description = description;
        //int转换为bool
        adjList->list[idx].isTransferStation = (isTransferStation==1)? true: false;
    }
    //关闭读流
    readStream.close();
}

//初始化adjList，返回adjList @newAdjList in heap
AdjList* __create_adjList(int n, int m)
{
    AdjList *newList;
    //创建邻接表
    newList = new AdjList;
    newList->numV = n;
    newList->numE = m;
    newList->list = new AdjNode[n+1];   //下标从1开始
    //将每个顶点的firstArc置为NULL
    for(int i=1; i<=n; i++) {
        newList->list[i].firstArc =NULL;
    }

    return newList;
}

//向adjList中插入边 @newENode in heap
void __insert_into_adjList(AdjList *adjList, int src, int dest, int cost)
{
    ENode *newENode;

    newENode = new ENode;
    newENode->vertex = dest;
    newENode->cost = cost;
    //头插法
    newENode->next = adjList->list[src].firstArc;
    adjList->list[src].firstArc = newENode;
}

//读入各边，返回adjList
AdjList *init_adjList()
{
    ifstream readStream;
    
    readStream.open("data.txt", ios::in);
    //顶点数 边数
    int N, M;

    readStream >> N >> M;
    //初始化adjList
    AdjList *adjList = __create_adjList(N, M);

    //为对应顶点编号设置社区名
    __assignment_community_name(adjList);
    
    //读入各边
    for(int i=0; i<M; i++) {
        int src, dest, cost;
        //读入源点 目的点 代价 
        readStream >> src >> dest >> cost;
        //双向插入
        __insert_into_adjList(adjList, src, dest, cost);
        __insert_into_adjList(adjList, dest, src, cost);
    }
    //关闭读流
    readStream.close();
    
    return adjList;
}

//判断该点是否为垃圾中转站
bool __is_transferStation(AdjList *adjList, int idx)
{
    return adjList->list[idx].isTransferStation;
}