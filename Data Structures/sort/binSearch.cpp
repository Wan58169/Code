#include<iostream>
using namespace std;

//数组a为待排序列，length为数组长度，key为关键字 
int binSearch(int a[],int length,int key)
{
	int left = 0;
	int right = length-1;
	int ret = -1;
	
	while(left <= right) {
		int mid = (left+right)/2;
		if(a[mid] == key) {
			ret = mid;
			break;
		} else if(a[mid] < key) {
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	return ret;
}

int main()
{ 
	//待排数组a下标从0开始
	int a[] = {2,4,7,11,13,16,21,24,27,32,36,40,46};
	
	int index = binSearch(a,sizeof(a)/sizeof(a[0]),37);
	cout << index << endl;
	return 0;
}
