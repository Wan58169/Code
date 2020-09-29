#include<stdio.h>
#include<stdlib.h>

void traversal(int a[],int size)
{
	for(int i=0; i<size; i++)
		printf("%d ",a[i]);
	printf("\n");
}

//快速排序cmp
int cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int a[] = {4,7,1,2,5,3,9,6,10,8};

	traversal(a,sizeof(a)/sizeof(a[0]));
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),cmp);
	traversal(a,sizeof(a)/sizeof(a[0]));

	return 0;
}
