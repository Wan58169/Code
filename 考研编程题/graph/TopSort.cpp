//拓扑排序
#include<iostream>
#include<queue>
using namespace std;

typedef int Vertex;
typedef char DataType;
typedef int WeightType;

typedef struct AdjNode {        //邻接点
	Vertex v;
	DataType key;
	WeightType weight;
	struct AdjNode *next;
}AdjNode;

typedef struct GNode {          //每个顶点的信息
	DataType key;
    int outDegree = 0;
    int inDegree = 0;
	struct AdjNode *next;       //邻接表
}AdjList;

typedef struct List {           //总表
	int numV;                   //图中的顶点数
	int numE;                   //图中的边数
	struct GNode *adjList;      //开辟用来存储邻接表的数组
}LGraph;

queue<int> q;

//拓扑排序
void topSort(LGraph *L)
{
    int cnt = 0;                  //用来记录参加排序的顶点数

    //将入度为0的顶点入队
    for(int i=0; i<L->numV; i++) {
        if(L->adjList[i].inDegree == 0) {
              q.push(i);
        }
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        //输出顶点V
        cnt++;                     //输出一个顶点就+1
        //修改该结点的邻接点信息
        for(AdjNode *p=L->adjList[v].next; p; p=p->next) {
            if(--L->adjList[p->v].inDegree == 0) {
                q.push(p->v);
            }
        }
    }
    //判断是否有回路
    if(cnt != L->numV) {
        //Error("图中有回路")
    }
}