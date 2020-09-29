//判断带头结点的双循环链表是否对称

typedef int ElementType;
typedef struct DNode {
    ElementType data;
    struct DNode *next;
    struct DNode *prior;
}DList;

void isSysmmetry(DList *L)
{
    DList *p = L->next;
    DList *q = L->prior;
    int flag = 1;                   //默认链表是对称的
    
    //链表个数为偶数或奇数
    while(p->prior!=q && p!=q) {       
        if(p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            flag = 0;
            break;
        }
    }
    if(flag == 1)   
        //该链表对称
    else
        //该链表不对称
}

