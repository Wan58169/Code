#include<stdio.h>
#include<string.h>

#define CAPACITY 101

int main()
{
	freopen("1038.txt","r",stdin);
	int N;
	
	scanf("%d",&N);
	int a[CAPACITY];
	int tmp;
	memset(a,0,sizeof(a));
	for(int i=0; i<N; i++) {
		scanf("%d",&tmp);
		a[tmp] += 1;
	}
	int M;
	scanf("%d",&M);
	int ret[M];
	for(int i=0; i<M; i++) {
		scanf("%d",&tmp);
		ret[i] = a[tmp];
	}
	for(int i=0; i<M-1; i++)
		printf("%d ",ret[i]);
	printf("%d",ret[M-1]);
	
	return 0;
}
