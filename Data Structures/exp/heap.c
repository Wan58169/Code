#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

MinHeap init_MinHeap(int capacity)
{
	MinHeap minHeap;

	minHeap = malloc(sizeof(struct HeapStruct));
	minHeap->data = malloc(sizeof(Cell)*(capacity+1));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->data[0].cnt = -1;

	return minHeap;
}

int isFull_MinHeap(MinHeap H)
{
	return (H->size == H->capacity);
}

int isEmpty_MinHeap(MinHeap H)
{
	return (H->size == 0);
}

void insert_MinHeap(MinHeap H,Cell x)
{
	int i;
	if(!isFull_MinHeap(H)) {
		i = ++H->size;
		for(; H->data[i/2].cnt > x.cnt; i/=2) {
			H->data[i].key = H->data[i/2].key;
			H->data[i].cnt = H->data[i/2].cnt;
		}
		H->data[i].key = x.key;
		H->data[i].cnt = x.cnt;
	} else {
		printf("MinHeap is full!\n");
		exit(0);
	}
}

Cell delete_MinHeap(MinHeap H)
{
	Cell minCell,tmpCell;
	int parent,child;
	
	if(isEmpty_MinHeap(H)) {
		printf("MinHeap is empty!\n");
		exit(0);
	}
	minCell.key = H->data[1].key;
	minCell.cnt = H->data[1].cnt;
	tmpCell.key = H->data[H->size].key;
	tmpCell.cnt = H->data[H->size].cnt;
	H->size--;
	for(parent=1; parent*2 <= H->size; parent=child) {
		child = 2*parent;
		if(child<H->size && H->data[child+1].cnt<H->data[child].cnt)
			child++;
		if(tmpCell.cnt < H->data[child].cnt) break;
		else if(tmpCell.cnt > H->data[child].cnt) {
			H->data[parent].key = H->data[child].key;
			H->data[parent].cnt = H->data[child].cnt;
		}
	}
	H->data[parent].key = tmpCell.key;
	H->data[parent].cnt = tmpCell.cnt;

	return minCell;
}

void perDown(MinHeap H,int p)
{
	int parent,child;
	Cell tmpCell;

	tmpCell.key = H->data[p].key;
	tmpCell.cnt = H->data[p].cnt;
	for(parent=p; parent*2 <= H->size; parent=child) {
		child = 2*parent;
		if(child<H->size && H->data[child+1].cnt<H->data[child].cnt)
			child++;
		if(H->data[child].cnt > H->data[parent].cnt) break;
		else if(H->data[child].cnt < H->data[parent].cnt) {
			H->data[parent].key = H->data[child].key;
			H->data[parent].cnt = H->data[child].cnt;
		}
	}
	H->data[parent].key = tmpCell.key;
	H->data[parent].cnt = tmpCell.cnt;
}

int calculateSize(Table t)
{
	int size = 0;

	for(int i=0; i<t->tableSize; i++)
		if(t->cells[i].cnt != 0)
			size++;
	
	return size;
}

void insertIntoBuf(Cell buf[],Table t)
{
	for(int i=0,j=0; i<t->tableSize; i++) {
		if(t->cells[i].cnt != 0) {
			buf[j].key = t->cells[i].key;
			buf[j].cnt = t->cells[i].cnt;
			j++;
		}
	}
}

void insertIntoMinHeap(MinHeap H,Cell buf[],int bufSize)
{
	for(int i=0; i<bufSize; i++) {
		H->data[i+1].key = buf[i].key;
		H->data[i+1].cnt = buf[i].cnt;
		H->size++;
	}
}

