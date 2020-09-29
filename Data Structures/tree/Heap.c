#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElementType;
typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	ElementType *data;
	int size;
	int capacity;
};

MaxHeap init(int capacity)
{
	MaxHeap maxHeap;

	maxHeap = malloc(sizeof(struct HeapStruct));
	maxHeap->data = malloc(sizeof(ElementType)*(capacity+1));
	maxHeap->size = 0;
	maxHeap->capacity = capacity;
	maxHeap->data[0] = 2000;

	return maxHeap;
}

int isFull(MaxHeap H)
{
	return (H->size == H->capacity);
}

int isEmpty(MaxHeap H)
{
	return (H->size == 0);
}

void insert(MaxHeap H,ElementType x)
{
	int i;

	if(isFull(H)) {
		printf("Heap is full!\n");
		return;
	}

	i = ++H->size;
	for(; H->data[i/2] < x; i/=2) 
		H->data[i] = H->data[i/2];
	H->data[i] = x;
}

ElementType delete(MaxHeap H)
{
	int parent,child;
	ElementType maxCell,tmpCell;

	if(isEmpty(H)) {
		printf("Heap is empty!\n");
		return -1;
	}

	//记录根结点
	maxCell = H->data[1];
	//用最后一个结点替代根结点
	tmpCell = H->data[H->size--];
	
	//寻找插入位置
	for(parent=1; parent*2<=H->size; parent=child) {
		child = parent*2;
		//选择最大的孩子
		if(child!=H->size && H->data[child+1]>H->data[child])
			child++;
		//与最大的孩子比较，如果比最大的孩子还大，则找到了所属位置；否则继续迭代
		if(tmpCell > H->data[child]) break;
		else 
			H->data[parent] = H->data[child];
	}
	//新牌落位
	H->data[parent] = tmpCell;

	return maxCell;
}

void perDown(MaxHeap H,int p)
{
	int parent,child;
	ElementType x;

	x = H->data[p];
	for(parent=p; parent*2<=H->size; parent=child) {
		child = parent*2;
		//选出最大的孩子
		if(child!=H->size && H->data[child+1]>H->data[child])
			child++;
		if(x > H->data[child]) break;
		else 
			H->data[parent] = H->data[child];
	}
	H->data[parent] = x;
}

int main()
{
	freopen("Heap.txt","r",stdin);
	MaxHeap maxHeap;
	int capacity;

	scanf("%d",&capacity);

	maxHeap = init(capacity);
	ElementType newCell;
	//读入数据
	for(int i=1; i<=capacity; i++) {
		scanf("%d",&newCell);
		maxHeap->data[i] = newCell;
		maxHeap->size++;
	}
	//建堆
	for(int p=capacity/2; p>=1; p--) {
		perDown(maxHeap,p);
	}
	for(int i=1; i<=capacity; i++)
		printf("%d ",maxHeap->data[i]);

	return 0;
}







