#include<stdio.h>

void swap(int *a,int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}


//子集划分
int partation(int a[],int left,int right)
{
	int i = left;
	int j = right;
	int pivot = a[j];

	while(i != j) {
		while(i<j && a[i]<=pivot) {		//从左往右扫
			i++;
		}
		swap(&a[i],&a[j]);
		while(i<j && a[j]>=pivot) {		//从右往左扫
			j--;
		}
		swap(&a[i],&a[j]);
	}

	return i;
}

//寻找第K大数
int select(int a[],int left,int right,int k)
{
	int vIndex = partation(a,left,right);	//pivot下标
	int sLLen = vIndex-left+1;				//左半边的长度

	if(k == sLLen) {						//正是要找的第K大数
		return vIndex;
	} else if (k > sLLen) {					//k在右半边，需要继续在右半边寻找
		return select(a,vIndex+1,right,k-sLLen);
	} else if (k < sLLen) {					//k在左半边，需要继续在左半边寻找
		return select(a,left,vIndex-1,k);
	}
}

int main()
{
	int a[] = {9,3,2,1,4,7,8,6,5};
	int index;
	int k = (sizeof(a)/sizeof(a[0])+1)/2;

	index = select(a,0,sizeof(a)/sizeof(a[0])-1,k);
	printf("%dth..%d\n",k,a[index]);

	return 0;
}
