#include<stdio.h>

struct Node {
	char zkz[15];
	int tryNum;
	int sitNum;
};
typedef struct Node A;

void f(A a[],int helpNum[],int aLen,int helpLen)
{
	for(int i=0; i<helpLen; i++) {
		for(int j=0; j<aLen; j++) {
			if(helpNum[i] == a[j].tryNum) 
				printf("%s %d\n",a[j].zkz,a[j].sitNum);
		}
	}
}

int main()
{
	freopen("1041.txt","r",stdin);
	int n;

	scanf("%d",&n);
	A a[n];
	for(int i=0; i<n; i++)
		scanf("%s %d %d",a[i].zkz,&a[i].tryNum,&a[i].sitNum);
	int helpCnt;
	scanf("%d",&helpCnt);
	int helpNum[helpCnt];
	for(int i=0; i<helpCnt; i++)
		scanf("%d",&helpNum[i]);
	f(a,helpNum,n,helpCnt);

	return 0;
}
