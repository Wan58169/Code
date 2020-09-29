//图的广度优先搜索
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

void bfs_LGraph(LGraph *L,Vertex v,int visited[])
{
	AdjNode p;
    Queue q;

	visitVertex(v);
	visited[v] = 1;
	EnQueue(q,v);
	while(!isEmpty_Queue(q)) {
		v = DeQueue(q);
		for(p=L->adjList[v].next; p; p=p->next)
			if(!visited[p->v]) {
				visitVertex(p->v);
				visited[p->v] = 1;
				EnQueue(q,p->v);
			}
	}
}