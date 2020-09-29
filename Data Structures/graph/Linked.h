#ifndef LINKED_H
#define LINKED_H

//边结点
typedef struct ENode {
	int v;
	int weight;
    struct ENode *next;
}ENode;

//邻接节点
typedef struct {
	int v;
	ENode *firstArc;
}AdjNode;

//邻接表
typedef struct {
	int numV;
    int numE;
    AdjNode *list;
}AdjList;

//初始化adjList @newAdjList in heap
AdjList *init_AdjList(int n,int m);

//释放adjList & ENode
void free_AdjList(AdjList *adjList);

//插入边 @newENode in heap
void insertIntoAdjList(AdjList *adjList, int src, int dest, int weight);

//dfs
void dfs(AdjList *adjList, int v, int visited[]);

//bfs
void bfs(AdjList *adjList, int v);

//未被收录的dist最小者
int findMinDist(int collected[], int dist[], int n);

//最短路径算法 @newArray in heap
void dijkstra(AdjList *adjList, int src, int dest);

//释放 @newArray in heap
void free_dijkstra(int *collected, int *dist, int *path);

#endif
