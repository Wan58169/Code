//计算每个顶点的出度和入度
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

//计算每个顶点的出度和入度
void cal_Degree(LGraph *L)
{
    int outDegree = 0;
    
    for(int i=0; i<L->numV; i++) {          //遍历每个顶点的拉链表
        AdjNode *p = L->adjList[i].next;    //定位到拉链表的表头
        for(; p; p=p->next) { 
            outDegree++;                    //出度+1
            L->adjList[p->v].inDegree++;    //累加入度
        }    
        L->adjList[i].outDegree = outDegree;
    }
}
