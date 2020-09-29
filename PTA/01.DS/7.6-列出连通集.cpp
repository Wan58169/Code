/*
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
按照"{ v1 v2 ... vk}"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5   
    
输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define MAX 10

typedef struct {
    int v1;
    int v2;
}Edge;

typedef struct {
	int numV;
	int numE;
	int g[MAX][MAX];
}LGraph;

void dfs(LGraph *Graph, int vertex, int visited[])
{
    //访问该顶点
    printf("%d ",vertex);
    visited[vertex] = 1;

    for(int i=0; i<Graph->numV; i++) {
        if(!visited[i] && Graph->g[vertex][i]) {
            dfs(Graph, i, visited);
        }
    }
}

int dfs_LGraph(LGraph *Graph)
{
    int visited[Graph->numV];
    int cnt = 0;        //连通集个数

    //初始化visited 默认没被访问过
    for(int i=0; i<Graph->numV; i++) {
        visited[i] = 0;
    }

    //全图dfs
    for(int i=0; i<Graph->numV; i++) {
        if(!visited[i]) {
            cnt++;
            printf("{ ");
            dfs(Graph, i, visited);
            printf("}\n");
        }
    }
    
    return cnt;
}

void bfs(LGraph *Graph, int vertex, int visited[])
{
    queue<int> queue;

    //访问该顶点
    printf("%d ", vertex);
    visited[vertex] = 1;
    queue.push(vertex);

    while(!queue.empty()) {
        vertex = queue.front();
        queue.pop();
        for(int i=0; i<Graph->numV; i++) {
            if(!visited[i] && Graph->g[vertex][i]) {
                //访问该顶点
                printf("%d ", i);
                visited[i] = 1;
                queue.push(i);
            }
        }
    }
}

int bfs_LGraph(LGraph *Graph)
{
    int visited[Graph->numV];
    int cnt = 0;        //连通集个数

    //初始化visited 默认没被访问过
    for(int i=0; i<Graph->numV; i++) {
        visited[i] = 0;
    }

    //全图bfs
    for(int i=0; i<Graph->numV; i++) {
        if(!visited[i]) {
            cnt++;
            printf("{ ");
            bfs(Graph, i, visited);
            printf("}\n");
        }
    }
    
    return cnt;
}

int main()
{
    // freopen("7.6-列出连通集.txt", "r", stdin);

    int numV, numE;
    LGraph *Graph;
    scanf("%d %d", &numV, &numE);
   
    Graph = (LGraph *)malloc(sizeof(LGraph));
    //初始化矩阵
    Graph->numV = numV;
    Graph->numE = numE;
    for(int i=0; i<numV; i++) {
        for(int j=0; j<numV; j++) {
            Graph->g[i][j] = 0;
        }
    }

    //插入边
    for(int i=0; i<numE; i++) {
        Edge e;
        scanf("%d %d", &e.v1, &e.v2);
        Graph->g[e.v1][e.v2] = 1;
        Graph->g[e.v2][e.v1] = 1;
    }

    //dfs
    int setsNum = dfs_LGraph(Graph);

    //bfs
    bfs_LGraph(Graph);


    // printf("%d\n", setsNum);

    return 0;
}