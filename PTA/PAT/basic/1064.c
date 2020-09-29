#include<stdio.h>
#include<stdlib.h>

void summator(int n,int sum[],int index)
{
	int summator = 0;

	while(n != 0) {
		summator += n%10;
		n /= 10;
	}
	sum[index] = summator;
}

void printSum(int sum[],int N)
{
	for(int i=0; i<N; i++)
		printf("%d ",sum[i]);
	printf("\n");
}

int cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

void f(int sum[],int N)
{
	int i = 0;
	int j = 0;
	int ret[N];

	for(i=1; i<N; i++) {
		if(sum[i-1] != sum[i])
			ret[j++] = sum[i-1];
	}
	printf("%d\n",j);
	for(i=0; i<j-1; i++)
		printf("%d ",ret[i]);
	printf("%d",ret[j-1]);
}

int main()
{
	freopen("1064.txt","r",stdin);
	int N;

	scanf("%d",&N);
	int sum[N+1];
	int tmp;
	for(int i=0; i<N; i++) {
		scanf("%d",&tmp);
		summator(tmp,sum,i);
	}
	sum[N] = -1;
	qsort(sum,sizeof(sum)/sizeof(sum[0])-1,sizeof(sum[0]),cmp);
	f(sum,N+1);
//	printSum(sum,N);

	return 0;
}
