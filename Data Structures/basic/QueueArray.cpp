#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define EmptyTOS -1

typedef int NodeType;
typedef struct QNode{
	int front;
	int rear;
	int capacity;			//初始化后再也不能改变
	NodeType* data;
}Queue;

Queue *initQueue(int capacity)
{
	Queue *q;

	q = (Queue *)malloc(sizeof(struct QNode));
	q->front = q->rear = EmptyTOS;
	q->capacity = capacity;
	q->data = (NodeType *)malloc(sizeof(NodeType)*capacity);

	return q;
}

void makeEmpty(Queue *q)
{
	q->front = q->rear = EmptyTOS;
	q->capacity = 0;
}

void destroyQueue(Queue *q)
{
	if(q) {
		free(q->data);
		free(q);
		printf("Queue has been destroyed!\n");
	} else 
		printf("Queue doesn't exist!\n");
}

//获得队列长度
int getLength(Queue *q)		
{
	return (q->rear-q->front+q->capacity)%q->capacity;
}

bool isFull(Queue *q)
{
	if( (q->rear+1)%q->capacity==q->front ) {	//如果队满
		return true;
	} else {
		return false;
	}
}

bool isEmpty(Queue *q) 
{
	if( q->front== q->rear ) {		//如果队空					
		return true;
	} else {
		return false;
	}
}

void EnQueue(Queue *q,NodeType item)
{
	if(isFull(q)) {
		printf("Queue is full!\n");
		return;
	} else {
		q->rear = (q->rear+1)%q->capacity;
		q->data[q->rear] = item;
	}
}

NodeType DeQueue(Queue *q)
{
	NodeType tmpCell;

	if(isEmpty(q)) {
		printf("Queue is empty!\n");
		return NULL;
	} else {
		q->front = (q->front+1)%q->capacity;
		tmpCell = q->data[q->front];
		return tmpCell;
	}
}

//输入进队列
void scanIntoQueue(Queue *q,int n)
{
	NodeType tmp;
	for(int i=1; i<n; i++) {
		scanf("%d",&tmp);
		EnQueue(q,tmp);
	}
}

//顺序遍历队列
void traversal_Queue(Queue *q) 
{
    int idx = q->front;

    while(1) {
        if(idx == q->rear) {        //如果指针已到末尾
            break;
        } else {
            idx = (idx+1)%q->capacity;
            printf("%d ",q->data[idx]);
        }
    }
}

int main()
{
	Queue *q;

	int n;
	scanf("%d",&n);

	q = initQueue(n);
	scanIntoQueue(q,n);
	traversal_Queue(q);

	return 0;
}









