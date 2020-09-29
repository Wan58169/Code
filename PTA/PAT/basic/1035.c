#include<stdio.h>
#include<stdlib.h>

int curLen = 0;

int isSame(int a[],int b[],int n)
{
	for(int i=0; i<n; i++) {
		if(a[i] != b[i])
			return 0;
	}
	return 1;
}

void merge(int a[],int left,int center,int right,int tmpA[],int b[],int n,int len)
{
	int leftIndex = left;
	int rightIndex = center+1;
	int tmpIndex = left;

	while(leftIndex<=center && rightIndex<=right) {
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

	if(isSame(a,b,n) && curLen==0) { 
		curLen = len*2;
		printf("Merge Sort\n");
	}
}

void mergeSort(int a[],int tmpA[],int b[],int n,int len)
{
	int i;

	for(i=0; i<=n-2*len; i+=2*len) {
	//	printf("a[%d] ..%d\n",i,a[i]);
		merge(a,i,i+len-1,i+2*len-1,tmpA,b,n,len);
	}
	if(i+len <= n) {
	//	printf("a[%d] ..%d\n",i,a[i]);
		merge(a,i,i+len-1,n-1,tmpA,b,n,len);
	}
}

void mergeInterface(int a[],int b[],int n)
{
	int *tmpA = malloc(sizeof(int)*n);
	int len = 1;

	while(len < n) {
//		printf("len ..%d\n",len);
		mergeSort(a,tmpA,b,n,len);
		if(curLen == len) {
//			printf("curLen ..%d,len ..%d\n",curLen,len);
			for(int i=0; i<n-1; i++)
				printf("%d ",a[i]);
			printf("%d",a[n-1]);
			printf("\n");
		}
		len *= 2;
	}
	free(tmpA);
}
int isInsert(int a[],int b[],int len)
{
	int i,j;
	int tmp;
	int flag = 0;

	for(i=1; i<len; i++) {
		tmp = a[i];
		for(j=i; j>0 && a[j-1]>tmp; j--)
			a[j] = a[j-1];
		a[j] = tmp;
		if(isSame(a,b,len)) {
			len = i+2;
			flag = 1;
		}
	}
	return flag;
}

int isMerge(int a[],int b[],int len)
{
	mergeInterface(a,b,len);
}

int main()
{
//	freopen("1035.txt","r",stdin);
	int n;
	
	scanf("%d",&n);
	int a[n],b[n];
	int tmpA[n],tmpB[n];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<n; i++)
		scanf("%d",&b[i]);
	for(int i=0; i<n; i++) {
		tmpA[i] = a[i];
		tmpB[i] = b[i];
	}
	if(isInsert(a,b,n)) {
		printf("Insertion Sort\n");
		for(int i=0; i<n-1; i++)
			printf("%d ",a[i]);
		printf("%d",a[n-1]);
		printf("\n");
	} else {
		isMerge(tmpA,tmpB,n);
	}

	return 0;
}
