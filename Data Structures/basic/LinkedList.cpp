#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct LNode
{
	ElementType item;
	struct LNode *next;
}*List;

//初始化单链表
List init()
{
	List L = new struct LNode;
	L->item = 0;
	L->next = NULL;

	return L;
}

//插入数据
void add(List L,ElementType item)
{
    List p = L;             //尾指针
    List newCell = new struct LNode;
    
    //定位到链表最后一个结点
    while(p->next != NULL) {
        p = p->next;
    }
    newCell->item = item;
    newCell->next = NULL;
    p->next = newCell;
}

//打印单链表
void print(List L)
{
    List p = L->next;

    while(p) {
        cout << p->item << " ";
        p = p->next;
    }
    cout << " " << endl; 
}

//合并链表
List merge(List L1,List L2)
{
    List p,q;               
    List newList;       

    p = L1->next;       //L1的首元素
    q = L2->next;       //L2的首元素
    newList = init();

    while(p && q) {
        if(p->item < q->item) {
            add(newList,p->item);
            p = p->next;
        } else {
            add(newList,q->item);
            q = q->next;
        }
    }
    if(p) {
        while(p) {
            add(newList,p->item);
            p = p->next;
        }
    } else if(q) {
        while(q) {
            add(newList,q->item);
            q = q->next;
        }
    }
    return newList;
}

int main(int argc, char const *argv[])
{
    List LA,LB;

    LA = init();
    LB = init();
    
    add(LA,1);
    add(LB,2);
    add(LA,3);
    add(LB,4);
    add(LA,5);
    add(LB,6);
    add(LA,7);
    add(LB,8);
    add(LA,9);
    add(LB,10);
    
    print(LA);
    print(LB);
    
    print(merge(LA,LB));

    return 0;
}
