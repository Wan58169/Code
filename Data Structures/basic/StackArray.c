#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElementType;

typedef struct SNode {
	int top;
	int capacity;
	ElementType *array;
}Stack;

Stack *init(int capacity)
{
	Stack *s = malloc(sizeof(struct SNode));
	s->array = malloc(sizeof(ElementType)*capacity);
	s->top = -1;
	s->capacity = capacity;
}

int isEmpty_Stack(Stack *s)
{
	return (s->top == -1);
}

int isFull_Stack(Stack *s)
{
	return (s->top == s->capacity);
}

void destroyStack(Stack *s)
{
	if(s) {
		free(s->array);
		free(s);
	} else 
		printf("This Stack doesn't exist!\n");
}

void push(Stack *s,ElementType item)
{
	if(isFull_Stack(s)) {
		printf("Stack is Full!\n");
		return;
	}
	s->array[++s->top] = item;
}

ElementType pop(Stack *s)
{
	if(isEmpty_Stack(s)) {
		printf("Stack is Empty!\n");
		return -1;
	}
	return s->array[s->top--];
}

void makeEmpty(Stack *s)
{
	s->top = -1;
}

ElementType top(Stack *s)
{
	if(isEmpty_Stack(s)) {
		printf("Stack is Empty!\n");
		return -1;
	} else 
		return s->array[s->top];
}

int main(int argc,char *argv[])
{
	Stack *s;
	int _isEmpty;
	int _pop;

	s = init(30);
	_isEmpty = isEmpty(s);
	printf("isEmpty? %d\n",_isEmpty);
	push(s,1);
	_isEmpty = isEmpty(s);
	printf("isEmpty? %d\n",_isEmpty);
	top(s);
	pop(s);
	top(s);
	return 0;
}

