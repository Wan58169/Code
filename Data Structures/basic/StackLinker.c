#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElementType;
typedef struct SNode
{
	ElementType item;
	struct SNode *next;
}*Stack;

Stack init()
{
	Stack s = malloc(sizeof(Stack));
	s->item = 0;
	s->next = NULL;

	return s;
}

int isEmpty(Stack s)
{
	return (s->next == NULL);
}

void push(Stack s,ElementType item)
{
	Stack TmpCell;

	TmpCell = malloc(sizeof(Stack));
	TmpCell->item = item;
	TmpCell->next = s->next;
	s->next = TmpCell;
}

ElementType pop(Stack s)
{
	Stack FirstCell;
	ElementType item;

	if(isEmpty(s)) {
		printf("Stack is Empty!\n");
		return -1;
	} else {
		FirstCell = s->next;
		s->next = FirstCell->next;
		item = FirstCell->item;
		free(FirstCell);
		return item;
	}
	
}

void makeEmpty(Stack s)
{
	if(s == NULL) 
		printf("Must init() first!\n");
	else {
		while(!isEmpty(s)) 
			pop(s);
	}
}

int main(int argc,char *argv[])
{
	Stack s;
	ElementType item;

	s = init();
	push(s,1);
	push(s,2);
	printf("isEmpty? %d\n",isEmpty(s));
	makeEmpty(s);
	printf("isEmpty? %d\n",isEmpty(s));
	return 0;
}







