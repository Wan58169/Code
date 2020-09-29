#include "myAdjList.h"

int main(int argc, char const *argv[])
{
    freopen("7.11-data.txt", "r", stdin);

    // 顶点数 边数
    int N, M;

    cin >> N >> M;

    AdjList adjList(N, M);

    //读入M条数据 边的信息
    for(int i=0; i<M; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        adjList.insert_into_dirAdjList(src, dest, cost);
    }

    // 判断是否有回路
    if(!adjList.top_sort()) {
        cout << "0" << endl;
        return 0;
    }

    // 关键路径法
    adjList.critical_path_method();

    

    // 输出关键路径
    adjList.print_critical_path();
    

    // 打印正向adjList @test
    adjList.print_adjList(adjList.get_list());
    cout << "---------------------------" << endl;
    // 打印逆向adjList @test
    adjList.print_adjList(adjList.get_verList());

    return 0;
}