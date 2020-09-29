#include "adjList.h"
#include "select.h"
#include "test.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    AdjList *adjList;
    
    //初始化图
    adjList = init_adjList();

    //为每个社区选择挂载点
    select_mountPoint(adjList);

    //打印邻接表 @test
    print_adjList(adjList);

    return 0;
}
