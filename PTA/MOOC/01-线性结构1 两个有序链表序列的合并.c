#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */
List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
//List Read()
//{
//	List myList,tail;					//首结点 尾指针 
//	int n;
//	
//	scanf("%d",&n);
//	myList = malloc(sizeof(struct Node));
//	myList->Next = NULL;
//	tail = myList;
//	for(int i=0; i<n; i++) {
//		List newList = malloc(sizeof(struct Node));
//		scanf("%d",&newList->Data);
//		newList->Next = NULL;
//		tail->Next = newList;
//		tail = newList;
//	}
//	return myList;
//}
//void Print( List L )
//{
//	List p;
//	
//	p = L->Next;
//	if(p == NULL) {
//		printf("NULL\n");
//	} else {
//		while(p) {
//			printf("%d ",p->Data);
//			p = p->Next;
//		}
//	}
//	printf("\n");
//} 
List Merge( List L1, List L2 )
{
	List L,tail,p1,p2;
	
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	tail = L;
	p1 = L1->Next;
	p2 = L2->Next;
	while(p1 && p2) {
		if(p1->Data <= p2->Data) {
			tail->Next = p1;
			tail = tail->Next;
			p1 = p1->Next;
		} else {
			tail->Next = p2;
			tail = tail->Next;
			p2 = p2->Next;
		}
	}
	if(p1) {
		tail->Next = p1;
	} else if(p2) {
		tail->Next = p2;
	}
	L1->Next = L2->Next = NULL;
	return L;
}
