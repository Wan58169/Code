#ifndef __ADJLIST_H__
#define __ADJLIST_H__

const int INFINITE = INT_MAX;

//定义邻接表结构
//Edge结构
typedef struct ENode{
    int vertex;
    int cost;
    struct ENode *next;
}ENode;

//顶点信息
typedef struct {
    int vertex;             //顶点编号
    string description;     //顶点对应的社区名 称之为描述信息（description）
    bool isTransferStation; //是否为垃圾中转站
    int mountPoint;         //该顶点的挂载点
    ENode *firstArc;
}AdjNode;

//邻接表
typedef struct {
    int numV;
    int numE;
    AdjNode *list;
}AdjList;

//为对应顶点编号设置社区名
void __assignment_community_name(AdjList *adjList);

//初始化adjList，返回adjList @newAdjList in heap
AdjList* __create_adjList(int n, int m);

//向adjList中插入边 @newENode in heap
void __insert_into_adjList(AdjList *adjList, int src, int dest, int cost);

//读入各边，返回adjList
AdjList *init_adjList();

//判断该点是否为垃圾中转站
bool __is_transferStation(AdjList *adjList, int idx);

#endif