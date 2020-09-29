#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}

void printArray(int a[],int n)
{
	for(int i=0; i<n-1; i++) 
		printf("%d ",a[i]);
	printf("%d",a[n-1]);
}

void f(int a[],int n)
{
	int ret[n];
	int rLen = 0;
	int tmpA[n];
	/* 对原数组排序 */
	for(int i=0; i<n; i++)
		tmpA[i] = a[i];
	qsort(tmpA,sizeof(tmpA)/sizeof(tmpA[0]),sizeof(tmpA[0]),cmp);
	/* 判断是否能作为pivot */
	int max = 0;
	for(int i=0; i<n; i++) {
		if(a[i] > max) {
			max = a[i];
			if(a[i] == tmpA[i])
				ret[rLen++] = a[i];
		}
		/*
		if(max==a[i] && a[i]==tmpA[i])
			ret[rLen++] = a[i];
		*/
	}
	qsort(ret,rLen,sizeof(ret[0]),cmp);
	printf("%d\n",rLen);
	printArray(ret,rLen);
}

int main()
{
	int n;

	scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	f(a,n);

	return 0;
}
