#include<stdio.h>

const int maxCol = 510;

void scanIntoMatrix(int a[],int aLen)
{
	int i;

	for(i=0; i<aLen; i++) {
		scanf("%d",&a[i]);
	}
}

void f(int a[],int M,int N,int A,int B,int T)
{
	int i,j;

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			if(a[i*N+j]<=B && a[i*N+j]>=A) {
				a[i*N+j] = T;
			}
		}
	}
}

void print(int a[],int M,int N)
{
	int i,j;

	for(i=0; i<M; i++) {
		for(j=0; j<N-1; j++) {
			printf("%03d ",a[i*N+j]);
		}
		printf("%03d\n",a[i*N+j]);
	}
}

int main()
{
	freopen("1066.txt","r",stdin);
	int M,N;
	int A,B,T;
	int aLen;

	scanf("%d %d %d %d %d",&M,&N,&A,&B,&T);
	aLen = M*N;
	int a[aLen];
	scanIntoMatrix(a,aLen);
	f(a,M,N,A,B,T);
	print(a,M,N);

	return 0;
}
