#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	freopen("1030.txt","r",stdin);
	int N,p;
	
	scanf("%d %d",&N,&p);
	int a[N];
	for(int i=0; i<N; i++)
		scanf("%d",&a[i]);
	qsort(a,N,sizeof(a[0]),cmp);
	int M,m;
	int len = 0;
	for(int i=0; i<N; i++) {
		m = a[i];
		int j = i;
		while(a[j]<=m*p && j<N)
			j++;
		if(len < j-i)
			len = j-i;
	}
	printf("%d",len);
	
	return 0;
}
