#include<iostream>
using namespace std;

//��һ��������,ȡһ������,ʹ���Ǻ�Ϊsum 
int sum = 6;
int a[] = {3,2,4,3,1};	//һ���� 
int len = sizeof(a)/sizeof(a[0]);
int *b = new int[len];	//��¼ȡ�� 0Ϊ�� 1Ϊȡ 

//k:��ǰλ��,cur_sum:��ǰ�ܺ� 
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
	//���ȡ 
	b[k] = 0;
	f(k+1,cur_sum);
	//ȡ����
	b[k] = 1;
	f(k+1,cur_sum+a[k]);
	b[k] = 0; 	//����!!!! 
}
int main()
{
	f(0,0);	
	return 0;
}
