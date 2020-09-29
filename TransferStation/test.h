#ifndef __TEST_H__
#define __TEST_H__

#include "adjList.h"

//打印adjNode相关信息
void __print_adjNode(AdjList *adjList, int idx);

//打印顶点的firstArc链接的链表 @test
void __print_enode(AdjList *adjList, int idx);

//打印adjList @test
void print_adjList(AdjList *adjList);

#endif