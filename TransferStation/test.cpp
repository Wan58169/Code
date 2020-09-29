#include "test.h"

//打印adjNode相关信息
void __print_adjNode(AdjList *adjList, int idx)
{
    //如果是社区，则打印该顶点的下标 社区名 挂载点
    if(adjList->list[idx].isTransferStation == false) {
        cout << "[" << adjList->list[idx].vertex << ", " << adjList->list[idx].description << ", "
             << adjList->list[idx].isTransferStation << ", "  
             << adjList->list[adjList->list[idx].mountPoint].description << "]->";   
    } 
    //如果是垃圾中转战，则不打印挂载点
    else {
        cout << "[" << adjList->list[idx].vertex << ", " << adjList->list[idx].description << ", "
            << adjList->list[idx].isTransferStation << ", "  << "]->";
    }   
}

//打印顶点的firstArc链接的链表 @test
void __print_enode(AdjList *adjList, int idx)
{
    //顶点编号 顶点描述 与之的代价
    for(ENode *e=adjList->list[idx].firstArc; e; e=e->next) {
        cout << "{" << e->vertex << ", " <<  adjList->list[e->vertex].description << ", " <<  e->cost << "} ";
    }
    cout << " " << endl;
}

//打印adjList @test
void print_adjList(AdjList *adjList)
{
    for(int i=1; i<=adjList->numV; i++) {
        //打印该顶点信息
        __print_adjNode(adjList, i);
        //打印该顶点的firstArc链接的链表
        __print_enode(adjList, i);
    }
}