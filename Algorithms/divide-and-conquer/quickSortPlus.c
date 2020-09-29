#include<stdio.h>

void traversal(int a[],int size)
{
	for(int i=0; i<size; i++)
		printf("%d ",a[i]);
	printf("\n");
}

void swap(int *a,int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
//选主元
int medium(int a[],int left,int right)
{
	int center = (left+right)/2;

	if(a[left] > a[center])
		swap(&a[left],&a[center]);
	if(a[left] > a[right])
		swap(&a[left],&a[right]);
	if(a[center] > a[right])
		swap(&a[center],&a[right]);
	//a[left] <= a[center] <= a[right]
	swap(&a[center],&a[right]); //把pivot藏到右边
	
	return a[right];
}
void quickSort(int a[],int left,int right)
{	
	if(left >= right)
		return;
	int i = left;
	int j = right;						//					 pivot
	int pivot = medium(a,left,right);	//a[left]...........a[right]

	
	//i>pivot
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
}
void quick_Sort(int a[],int n)
{
	quickSort(a,0,n-1);
}

int main()
{
	int a[] = {4,7,1,2,5,3,9,6,10,8};

	traversal(a,sizeof(a)/sizeof(a[0]));
	quick_Sort(a,sizeof(a)/sizeof(a[0]));
	traversal(a,sizeof(a)/sizeof(a[0]));

	return 0;
}
