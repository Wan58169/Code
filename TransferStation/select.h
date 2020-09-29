#ifndef __SELECT_H__
#define __SELECT_H__

#include "adjList.h"

//寻找该点到垃圾中转站dist最小者
int __find_all_min_dist(AdjList *adjList, int dist[], int n);

//未被收录的dist最小者
int __find_min_dist(int collected[], int dist[], int n); 

//最短路径算法，返回最佳挂载点 @newArray in heap 
int __dijkstra(AdjList *adjList, int src, int dest);

// 为每个社区选择挂载点
void select_mountPoint(AdjList *adjList);

#endif