//�����������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20��
//��Ҫ�����д���򣬼�������������е�������к͡�?
//
//������?:
//
//�����?1�и���������K (��100000)����2�и���K������������Կո�ָ�
//
//������?:
//
//��һ�������������к͡��������������������Ϊ�����������0��
//
//��������:
//6
//-2 11 -4 13 -5 -2
// 
//�������?:
//20
#include<iostream>
using namespace std;

int f(int *a,int len)
{
	int sum = 0;
	int maxSum = 0;				//����	
	
	for(int i=0; i<len; i++) {
		sum += a[i];
		if(sum < 0) {			//����Ϊ������ʼ�� 
			sum = 0;
			continue;
		} else {
			if(sum > maxSum) 
				maxSum = sum;	
		}
	}
	return maxSum;
}
int main()
{
	int N;
	int *a;
	
	cin >> N;
	a = new int[N];
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	cout << f(a,N) << endl;
	return 0;
}
