//反转单链表
typedef int ElementType;
typedef struct LNode
{
	ElementType data;
	struct LNode *next;
}List;

void reverse(List *L1,List *L2)
{
    List *p = L1->next;
    List *q;                 //辅助指针

    while(p) {
        q = p->next;              //保存p->next
        p->next = L2->next;
        L2->next = p;
        p = q;
    }
}