//合并单链表

typedef int ElementType;
typedef struct LNode {
    ElementType data;
    struct LNode *next;
}List;

void merge_LinkedList(List *L1,List *L2)
{
    List *p1 = L1->next;
    List *p2 = L2->next;
    List *newList = L1->next;

    while(p1 && p2) {
        if(p1->data < p2->data) {           //选中p1
            newList->next = p1;             //将p1连到新表中
            p1 = p1->next;                  //p1后搓
            newList = newList->next;        //newList也后搓
        } else {
            newList->next = p2;
            p2 = p2->next;
            newList = newList->next;
        }
    }
    if(p1)                                  //将剩余的p1接到newList后面
        newList->next = p1;
    if(p2)
        newList->next = p2;
}