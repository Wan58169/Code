//二分查找
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
		if(a[mid] == key) {             //找到了！
			ret = mid;
			break;
		} else if(a[mid] < key) {       //key > a[mid]，向右search
			left = mid+1;
		} else {                        //key < a[mid]，向左search
			right = mid-1;
		}
	}
	return ret;
}
