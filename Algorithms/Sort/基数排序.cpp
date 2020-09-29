#include<iostream>
#include<queue>
using namespace std;

const int radix = 10;		//基数 
const int digit = 4;		//位数 
queue<int> q[radix];

void  radix_sort(int data[],int n)
{
	int i,j,k;
	int factor = 1;
	
	//最大数是几位数就做几次循环 
	for(i=0; i<digit; factor*=radix,i++) {
		for(j=0; j<n; j++) {	//扫描每个元素 
			q[(data[j]/factor)%radix].push(data[j]);
		}
		for(j=k=0; j<radix; j++) {	//将10个桶串起来 
			while(!q[j].empty()) {
				data[k++] = q[j].front();
				q[j].pop();
			}
		}
	}
}
int main()
{
	int data[] = {10,1234,9,7234,67,9181,733,197,7,3};
	int n = sizeof(data)/sizeof(data[0]);
	
	radix_sort(data,n);
	//打印排序好的序列 
	for(int i=0; i<n; i++) {
		cout << data[i] << " ";
	}
	cout << " " << endl;
	return 0;  
}
