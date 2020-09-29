#include<stdio.h>
#include<stdlib.h>

void traversal(int a[],int size)
{
	for(int i=0; i<size; i++)
		printf("%d ",a[i]);
	printf("\n");
}

void merge(int a[],int left,int center,int right,int tmpA[])
{
	int leftIndex = left;
	int rightIndex = center+1;
	int tmpIndex = left;

	while(leftIndex<=center && rightIndex<=right) { /* 归并 */
		if(a[leftIndex] < a[rightIndex])
			tmpA[tmpIndex++] = a[leftIndex++];
		else 
			tmpA[tmpIndex++] = a[rightIndex++];
	}
	while(leftIndex <= center) {	/* 左剩余 */
		tmpA[tmpIndex++] = a[leftIndex++];
	}
	while(rightIndex <= right) {	/* 右剩余 */
		tmpA[tmpIndex++] = a[rightIndex++];
	}
	for(int i=left; i<=right; i++)
		a[i] = tmpA[i];
}
/*
//递归
void mergeSort(int a[],int left,int right,int tmpA[])
{
	if(left < right) {
		int center = (left+right)/2;
		mergeSort(a,left,center,tmpA);
		mergeSort(a,center+1,right,tmpA);
		merge(a,left,center,right,tmpA);
	}
}
void merge_Sort(int a[],int n)
{
	int *tmpA = malloc(sizeof(int)*n);
	mergeSort(a,0,n-1,tmpA);
	free(tmpA);
}
*/

void mergeSort(int a[],int tmpA[],int n,int len)
{
	int i;

	/* 子序列排序 */
	for(i=0; i<=n-2*len; i+=2*len)
		merge(a,i,i+len-1,i+2*len-1,tmpA);
	/* 处理尾巴 */
	merge(a,i,i+len-1,n-1,tmpA);
}
void merge_Sort(int a[],int n)
{
	int *tmpA = malloc(sizeof(int)*n);
	int len; /* len为当前子序列的长度 */

	/*											  n=10
	 *	4   7  1   2  5   3  9   6  10    8  	len=1
	 *   4 7    1 2    3 5    6 9     8 10		len=2
	 *     1 2 4 7      3 5 6 9       8 10		len=4
	 *		  1 2 3 4 5 6 7 9	      8 10      len=8
	 *			1 2 3 4 5 6 7 8 9 10 
	*/
	for(len=1; len<n; len*=2) {
		mergeSort(a,tmpA,n,len);
	}
}

int main()
{
	freopen("mergeSort.txt","r",stdin);
//	int a[] = {4,7,1,2,5,3,9,6,10,8};
	int N;

	scanf("%d",&N);
	int a[N];
	for(int i=0; i<N; i++) {
		scanf("%d",&a[i]);
	}
	traversal(a,sizeof(a)/sizeof(a[0]));
	merge_Sort(a,sizeof(a)/sizeof(a[0]));
	traversal(a,sizeof(a)/sizeof(a[0]));

	return 0;
}
