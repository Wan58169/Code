#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List ReadInput()
{
	int n;
	List myList = malloc(sizeof(struct LNode));
	
	scanf("%d",&n);
	myList->Last = n;
	for(int i=1; i<=n; i++) {
		scanf("%d",&myList->Data[i]);
	}
	return myList;
}

Position BinarySearch( List L, ElementType X )
{
	int idx = NotFound;
	int left = 1,right = L->Last;
	
	while(left <= right) {
		int mid = (left+right)/2;
		if(L->Data[mid] < X) {
			left = mid+1;
		} else if(L->Data[mid] > X) {
			right = mid-1;
		} else {
			idx = mid;
			break;
		}
	}
	return idx;
}
