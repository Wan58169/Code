#ifndef MYSTACK_H
#define MYSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct SNode {
	int top;
	int capacity;
	char *array[];
}Stack;

//初始化堆栈
Stack *init_Stack(int capacity);

//判断堆栈是否为空
int isEmpty_Stack(Stack *s);

//判断堆栈是否已满
int isFull_Stack(Stack *s);

//置空
void makeEmpty(Stack *s);

//释放堆栈
void destroyStack(Stack *s);

//压栈
void push(Stack *s,char *item);

//出栈
char *pop(Stack *s);

//去栈顶元素
char *top(Stack *s);

//获得堆栈元素个数
int getSize_Stack(Stack *s);

#endif