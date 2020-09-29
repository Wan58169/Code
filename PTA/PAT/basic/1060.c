#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	freopen("1060.txt","r",stdin);
	int N;

	scanf("%d",&N);
	int value[N+1];
	//读入N天数据
	for(int i=1; i<=N; i++) {
		scanf("%d",&value[i]);
	}
	//排序
	qsort(value+1,N,sizeof(int),cmp);
	for(int i=1; i<=N; i++) {
		if(value[i] <= i) {
			printf("%d",i-1);
			break;
		}
	}
	return 0;
}
