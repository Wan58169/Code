/*
现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，求使每个村落都有公路连通所需要的最低成本。

输入格式:
输入数据包括城镇数目正整数N（≤1000）和候选道路数目M（≤3N）；随后的M行对应M条道路，每行给出3个正整数，分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。
为简单起见，城镇从1到N编号。

输出格式:
输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出−1，表示需要建设更多公路。

输入样例:
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3

输出样例:
12
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
#define INFINITE 1000

typedef struct {
    int numV;
    int numE;
    int *(matrix[MAX]);         
}LGraph;

int findMinDist(LGraph graph, int dist[], int collected[])
{
    int minV = 0;
    int minDist = INFINITE;

    //扫描出dist最小且没被收录的顶点
    for(int i=0; i<graph.numV; i++) {
        if(dist[i]<minDist && collected[i]==0) {
            minDist = dist[i];
            minV = i;
        }
    }
    //如果存在，则返回顶点编号；如果不存在，则返回-1
    if(minDist < INFINITE)
        return minV;
    else 
        return -1;
}

int prim(LGraph srcG, LGraph *destG,int src, int dist[], int path[])
{
    int collected[srcG.numV];
    int v, totalWeight, vCnt;
    
    totalWeight = 0;        //总权值为0
    vCnt = 0;               //收录顶点数为0

    //初始化集合
    for(int i=0; i<srcG.numV; i++) 
        collected[i] = 0;
    collected[src] = 1;
    vCnt++;

    while(1) {
        //未被收录顶点中dist最小者
        v = findMinDist(srcG, dist, collected);
        //如果这样顶点不存在
        if(v == -1) 
            break;
        
        //将(v, path[v])收录进destG
        destG->matrix[v][path[v]] = dist[v];
        destG->matrix[path[v]][v] = dist[v];
        destG->numE += 2;
        collected[v] = 1;
        totalWeight += dist[v];
        vCnt++;

        //更新未被收录的邻接点信息
        for(int i=0; i<srcG.numV; i++) {
            //判断是否为有效邻接点
            if(i!=v && collected[i]==0) {
                //比原来的dist要小
                if(srcG.matrix[v][i] < dist[i]) {
                    dist[i] = srcG.matrix[v][i];
                    path[i] = v;
                }
            }
        }
    }

    if(vCnt == srcG.numV)
        return totalWeight;
    else 
        return -1;
}

int main()
{
    // freopen("7.10-公路村村通.txt", "r", stdin);
    int N, M;
    LGraph srcG, destG;

    scanf("%d %d", &N, &M);

    //初始化srcG
    srcG.numV = N;
    srcG.numE = M;
    for(int row=0; row<N; row++) {
        srcG.matrix[row] = (int *)malloc(N*sizeof(int));
        for(int col=0; col<N; col++) {
            if(row == col) {
                srcG.matrix[row][col] = 0;    
            } else {
                srcG.matrix[row][col] = INFINITE;
            }
            
        }
    }

    //初始化destG
    destG.numV = N;
    destG.numE = 0;
    for(int row=0; row<N; row++) {
        destG.matrix[row] = (int *)malloc(N*sizeof(int));
        for(int col=0; col<N; col++) {
            if(row == col) {
                destG.matrix[row][col] = 0;    
            } else {
                destG.matrix[row][col] = INFINITE;
            }
            
        }
    }
    
    int src;  //记录源点
    //输入各边信息
    for(int i=0; i<M; i++) {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        srcG.matrix[v1-1][v2-1] = weight;
        srcG.matrix[v2-1][v1-1] = weight;   
        src = v1-1; 
    }

    //prim准备工作
    int dist[srcG.numV];
    int path[srcG.numV];
    //初始化dist和path
    for(int i=0; i<srcG.numV; i++) 
        dist[i] = INFINITE;
    dist[src] = 0; 
    for(int i=0; i<srcG.numV; i++)
        path[i] = -1;
    //更新源点的邻接点信息
    for(int i=0; i<srcG.numV; i++) {
        if(srcG.matrix[src][i]!=0 && srcG.matrix[src][i]!=INFINITE) {
            dist[i] = srcG.matrix[src][i];
            path[i] = src;   
        }
    }

    //调用prim
    int totalWeight;
    totalWeight = prim(srcG, &destG, src, dist, path);

    //打印destG
    // for(int row=0; row<N; row++) {
    //     for(int col=0; col<N; col++) {
    //        printf("%4d ", destG.matrix[row][col]);
    //     }
    //     printf("\n");
    // }
    printf("%d", totalWeight);

    return 0;
}