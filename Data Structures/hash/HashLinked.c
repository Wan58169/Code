#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define TABLE_SIZE 11

typedef char ElementType;
typedef int Index;

struct LNode {
	ElementType data[256];
	struct LNode* next;
};

typedef struct LNode *List;
typedef struct LNode *Position;

struct HashTbl {
	int tableSize;
	List head;
};

typedef struct HashTbl *H;

H init() 
{
	H h;

	h = malloc(sizeof(struct HashTbl));
	h->tableSize = TABLE_SIZE;
	h->head = malloc(sizeof(struct LNode)*h->tableSize);
	for(int i=0; i<h->tableSize; i++) 
		h->head[i].next = NULL;

	return h;
}


Index hash(ElementType *key)
{
	unsigned int h = 0;
	
	while(*key != '\0')
		h = (h<<5) + *key++;

	return h%TABLE_SIZE;
}

Position find(H h,ElementType *x)
{
	Index i = hash(x);
	Position p = h->head[i].next;
	
	while(p && strcmp(p->data,x)!=0)
		p = p->next;
	
	return p;
}

void insert(H h,ElementType *x)
{
	Position p = find(h,x);

	if(!p) {
		Index i = hash(x);
		Position newCell = malloc(sizeof(struct LNode));
		strcpy(newCell->data,x);
		newCell->next = h->head[i].next;
		h->head[i].next = newCell;
	}
	// else {
	//	printf("The element exists! %d\n",p->data);
	//}
}

void traversal(H h)
{
	Position p;

	for(int i=0; i<TABLE_SIZE; i++) {
		p = h->head[i].next;
		printf("%d ",i);
		while(p) {
			printf("%s ",p->data);
			p = p->next;
		}
		printf("\n");
	}
}

int main(int argc,char *argv[])
{
	freopen("data.txt","r",stdin);
	
	H h;
	int n;
	ElementType buf[256];
	h = init();

	scanf("%d",&n);
	fgets(buf,256,stdin);
	for(int i=0; i<n; i++) {
		fgets(buf,256,stdin);
		buf[strlen(buf)-1] = '\0';
		insert(h,buf);
	}
	traversal(h);

	return 0;
}





