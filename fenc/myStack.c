#include "myStack.h"

//初始化堆栈
Stack *init_Stack(int capacity)
{
	Stack *s = (Stack *)malloc(sizeof(struct SNode));
	for(int i=0; i<capacity; i++) {
		s->array[i] = (char *)malloc(4);		//默认为4
	}
	s->top = -1;
	s->capacity = capacity;
	return s;
}

//判断堆栈是否为空
int isEmpty_Stack(Stack *s)
{
	return (s->top == -1);
}

//判断堆栈是否已满
int isFull_Stack(Stack *s)
{
	return (s->top == s->capacity);
}

//置空
void makeEmpty(Stack *s)
{
	s->top = -1;
}

//释放堆栈
void destroyStack(Stack *s)
{
	if(s) {
		free(s->array);
		free(s);
	} else 
		printf("This Stack doesn't exist!\n");
}

//压栈
void push(Stack *s,char *item)
{
	if(isFull_Stack(s)) {
		printf("Stack is Full!\n");
		return;
	}
	s->top++;
	for(int i=0; i<4; i++) {
		s->array[s->top][i] = item[i];
	}
}

//出栈
char *pop(Stack *s)
{
	if(isEmpty_Stack(s)) {
		printf("Stack is Empty!\n");
		return NULL;
	}
	return s->array[s->top--];
}

//去栈顶元素
char *top(Stack *s)
{
	if(isEmpty_Stack(s)) {
		printf("Stack is Empty!\n");
		return NULL;
	} else 
		return s->array[s->top];
}

//获得堆栈元素个数
int getSize_Stack(Stack *s)
{
	return s->top+1;
}
