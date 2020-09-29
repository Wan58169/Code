#include<iostream>
using namespace std;

//在一堆数字中,取一个或多个,使它们和为sum 
int sum = 6;
int a[] = {3,2,4,3,1};	//一堆数 
int len = sizeof(a)/sizeof(a[0]);
int *b = new int[len];	//记录取舍 0为舍 1为取 

//k:当前位置,cur_sum:当前总和 
void f(int k,int cur_sum)
{
	if(cur_sum > sum) return;
	if(cur_sum == sum) {
		for(int i=0; i<len; i++) {
			if(b[i] == 1) {
				cout << a[i] << " ";
			}
		}
		cout << " " << endl;
		return;
	}
	if(k == len) return;
	//该项不取 
	b[k] = 0;
	f(k+1,cur_sum);
	//取该项
	b[k] = 1;
	f(k+1,cur_sum+a[k]);
	b[k] = 0; 	//回溯!!!! 
}
int main()
{
	f(0,0);	
	return 0;
}
