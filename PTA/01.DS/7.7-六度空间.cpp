/*
“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。
这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，也就是说，最多通过五个人你就能够认识任何一个陌生人。”

假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

输入格式:
输入第1行给出两个正整数，分别表示社交网络图的结点数N（1<N≤10^3​​，表示人数）、边数M（≤33×N，表示社交关系数）。
随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。

输出格式:
对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

输入样例:
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

输出样例:
1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%
*/

#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 1000
#define INFINITE -1
#define CONNECTED 1
#define LOOPBACK 0

typedef struct {
    int numV;
    int numE;
    char matrix[MAX][MAX];
}LGraph;

float bfs(LGraph g, int v)
{
    queue<int> q;
    //dist两个作用：标记是否已访问 & 距离
    int dist[g.numV];       

    //初始化dist 
    for(int i=0; i<g.numV; i++) {
        dist[i] = INFINITE;
    }
    
    //访问结点v
    dist[v] = 0;
    q.push(v);

    while(!q.empty()) {
        v = q.front();
        q.pop();
        //访问v的未被访问的邻接点
        for(int i=0; i<g.numV; i++) {
            if(g.matrix[v][i]==CONNECTED && dist[i]==INFINITE) {
                dist[i] = dist[v]+1;
                q.push(i);
            }
        }
    }
    
    //数一数有多少个满足六度空间的顶点（注）非连通图
    int cnt = 0;
    for(int i=0; i<g.numV; i++) {
        if(dist[i]<=6 && dist[i]!=INFINITE) {
            cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    freopen("7.7-六度空间.txt", "r", stdin);
    //N为结点数 M为边数
    int N, M;
    LGraph g;

    scanf("%d %d", &N, &M);
    
    //初始化Graph
    g.numV = N;
    g.numE = M;
    for(int row=0; row<N; row++) {
        for(int col=0; col<N; col++) {
            if(row == col) {
                g.matrix[row][col] = LOOPBACK;
            } else {
                g.matrix[row][col] = INFINITE;
            }
        }
    }

    //读入各边信息
    for(int i=0; i<M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        g.matrix[v1-1][v2-1] = CONNECTED;
        g.matrix[v2-1][v1-1] = CONNECTED;
    }

    int ret;
    //对每个顶点都BFS
    for(int i=0; i<N; i++) {
        ret = bfs(g, i);
        float t = (ret*1.0/N)*100;
        printf("%d: %.2f%%\n", i+1, t);
    }

    return 0;
}