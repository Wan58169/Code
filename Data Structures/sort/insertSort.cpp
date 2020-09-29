#include<iostream>
using namespace std;

void insert_sort(int a[],int aLen)
{
	//手里已经拿着第一张牌了
	for(int i=1; i<aLen; i++) {
		int tmp = a[i];
		//向前寻找空位
		int j;
		for(j=i; j>0 && a[j-1]>tmp; j--)
			a[j] = a[j-1];
		//新牌落位
		a[j] = tmp;
	}
}

int main()
{
	int a[] = {4,7,1,2,5,3,9,6,10,8};
	int aLen = sizeof(a)/sizeof(a[0]);
    
	//打印待排数组a
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl;

    insert_sort(a,aLen);

    //打印排序好的数组
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl; 

	return 0;
}
