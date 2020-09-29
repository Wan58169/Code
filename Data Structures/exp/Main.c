#include<stdio.h>
#include<stdlib.h>
#include "WordCount.h"
#include "heap.h"

int main(int argc,char *argv[])
{
	Table t;
	int byteCnt;
	//建表 统计个数和频率
	t = init_Table(256);
	byteCnt = read_File(argv[1],t);
	//计算有效字符
	int bufSize = calculateSize(t);
	Cell buf[bufSize];
	insertIntoBuf(buf,t);
	destroy_Table(t);
	//建最小堆
	MinHeap minHeap;
	minHeap	= init_MinHeap(bufSize);
	insertIntoMinHeap(minHeap,buf,bufSize);
	for(int i = bufSize/2; i > 0; i--) 
		perDown(minHeap,i);
	Cell min = delete_MinHeap(minHeap);
	printf("min=%c %d\n",min.key,min.cnt);
	
	return 0;
}
