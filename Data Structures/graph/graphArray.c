#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

struct ENode {
	Vertex v1,v2;
	WeightType weight;
};
typedef struct ENode *Edge;

struct GNode {
	int numV;
	int numE;
	WeightType g[MaxVertexNum][MaxVertexNum];
	DataType data[MaxVertexNum];
};
typedef struct GNode *MGraph;

MGraph init_MGraph(int vertexNum)
{
	MGraph mGraph;

	mGraph = malloc(sizeof(struct GNode));
	mGraph->numV = vertexNum;
	mGraph->numE = 0;
	for(int i=0; i<vertexNum; i++) 
		for(int j=0; j<vertexNum; j++)
			mGraph->g[i][j] = 0;

	return mGraph;
}

void insertIntoMGraph(MGraph m,Edge e)
{
	m->g[e->v1][e->v2] = e->weight;
	m->g[e->v2][e->v1] = e->weight;
	m->numE++;
}

void traversalMGraph(MGraph m)
{
	for(int i=0; i<m->numV; i++) {
		for(int j=0; j<m->numV; j++) 
			printf("%d ",m->g[i][j]);
		printf("\n");
	}
}

int main(int argc,char *argv[])
{
	freopen("graphArray.txt","r",stdin);
	MGraph mGraph;
	int vertexNum,edgeNum;

	scanf("%d",&vertexNum);
	mGraph = init_MGraph(vertexNum);
	scanf("%d",&edgeNum);

	DataType buf[vertexNum];
	scanf("%s",buf);
//	printf("%s\n",buf);
	for(int i=0; i<vertexNum; i++)
		mGraph->data[i] = buf[i];
	Edge x = malloc(sizeof(struct ENode));
	for(int i=0; i<edgeNum; i++) {
		scanf("%d %d %d",&x->v1,&x->v2,&x->weight);
//		printf("%d %d %d\n",x->v1,x->v2,x->weight);
		insertIntoMGraph(mGraph,x);
	}
	traversalMGraph(mGraph);
	
	return 0;
}















