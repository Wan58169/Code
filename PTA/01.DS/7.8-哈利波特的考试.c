/*
哈利·波特要考试了，他需要你的帮助。这门课学的是用魔咒将一种动物变成另一种动物的本事。例如将猫变成老鼠的魔咒是haha，将老鼠变成鱼的魔咒是hehe等等。
反方向变化的魔咒就是简单地将原来的魔咒倒过来念，例如ahah可以将老鼠变成猫。另外，如果想把猫变成鱼，可以通过念一个直接魔咒lalala，也可以将猫变老鼠、
老鼠变鱼的魔咒连起来念：hahahehe。

现在哈利·波特的手里有一本教材，里面列出了所有的变形魔咒和能变的动物。老师允许他自己带一只动物去考场，要考察他把这只动物变成任意一只指定动物的本事。
于是他来问你：带什么动物去可以让最难变的那种动物（即该动物变为哈利·波特自己带去的动物所需要的魔咒最长）需要的魔咒最短？例如：如果只有猫、鼠、鱼，
则显然哈利·波特应该带鼠去，因为鼠变成另外两种动物都只需要念4个字符；而如果带猫去，则至少需要念6个字符才能把猫变成鱼；同理，带鱼去也不是最好的选择。

输入格式:
输入说明：输入第1行给出两个正整数N (≤100)和M，其中N是考试涉及的动物总数，M是用于直接变形的魔咒条数。为简单起见，我们将动物按1~N编号。随后M行，
每行给出了3个正整数，分别是两种动物的编号、以及它们之间变形需要的魔咒的长度(≤100)，数字之间用空格分隔。

输出格式:
输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，中间以空格分隔。如果只带1只动物是不可能完成所有变形要求的，则输出0。
如果有若干只动物都可以备选，则输出编号最小的那只。

输入样例:
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
    
输出样例:
4 70
*/

#include <stdio.h>

#define MAX 100
#define INFINITE 1000

typedef struct {
    int numV;
    int numE;
    int g[MAX][MAX];
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


void dijkstra(LGraph graph, int src, int dist[], int path[])
{
    int collected[graph.numV];
    int v;

    //初始化集合
    for(int i=0; i<graph.numV; i++) 
        collected[i] = 0;
    collected[src] = 1;

    while(1) {
        //未收录顶点中dist最小者
        v = findMinDist(graph, dist, collected);
        if(v == -1)
            break;
        collected[v] = 1;
        for(int i=0; i<graph.numV; i++) {
            //更新有效邻接点
            if(i!=v && collected[i]==0) {
                if(dist[v]+graph.g[v][i] < dist[i]) {
                    dist[i] = dist[v]+graph.g[v][i];
                    path[i] = v;
                }
            }
        }
    }
}

int main()
{
    freopen("7.8-哈利波特的考试.txt", "r", stdin);
    int N, M;
    LGraph graph;

    scanf("%d %d", &N, &M);

    //初始化LGraph
    graph.numV = N;
    graph.numE = M;
    for(int row=0; row<N; row++) {
        for(int col=0; col<N; col++) {
            if(row == col) {
                graph.g[row][col] = 0;    
            } else {
                graph.g[row][col] = INFINITE;
            }
            
        }
    }

    //输入各边信息
    for(int i=0; i<M; i++) {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        graph.g[v1-1][v2-1] = weight;
        graph.g[v2-1][v1-1] = weight;    
    }

    //存放各顶点到其他顶点最短路径
    int ret[graph.numV];
    //二重循环-dijkstra
    for(int src=0; src<graph.numV; src++) {
        int dist[graph.numV];
        int path[graph.numV];
        //初始化dist和path
        for(int i=0; i<graph.numV; i++) 
            dist[i] = INFINITE;
        dist[src] = 0; 
        for(int i=0; i<graph.numV; i++)
            path[i] = -1;
        //更新源点的邻接点信息
        for(int i=0; i<graph.numV; i++) {
            if(graph.g[src][i]!=0 && graph.g[src][i]!=INFINITE) {
                dist[i] = graph.g[src][i];
                path[i] = src;   
            }
        }

        //调用dijkstra
        dijkstra(graph, src, dist, path);

        //选择最大的dist
        int max = -1;
        for(int i=0; i<graph.numV; i++) {
            if(dist[i] > max) {
                max = dist[i];
            }
        }
        //将最大的dist存到ret中
        ret[src] = max;
    }

    //选择到所有顶点路径最短的顶点
    int minV, minDist=INFINITE;
    for(int i=0; i<graph.numV; i++) {
        if(ret[i] == INFINITE) {
            printf("0");
            return 0;
        }
        if(ret[i] < minDist) {
            minDist = ret[i];
            minV = i;
        }
    }
    printf("%d %d", minV+1, minDist);

    return 0;
}