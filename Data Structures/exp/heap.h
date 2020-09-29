#ifndef HEAP_H
#define HEAP_H

#include "WordCount.h"

struct HeapStruct {
	Cell *data;
	int size;
	int capacity;
};
typedef struct HeapStruct *MinHeap;

MinHeap init_MinHeap(const int capacity);
int isFull_MinHeap(MinHeap H);
int isEmpty_MinHeap(MinHeap H);
void insert_MinHeap(MinHeap H,const Cell x);
Cell delete_MinHeap(MinHeap H);
void perDown(MinHeap H,int p);
int calculateSize(Table t);
void insertIntoBuf(Cell buf[],Table t);
void insertIntoMinHeap(MinHeap H,Cell buf[],int bufSize);

#endif
