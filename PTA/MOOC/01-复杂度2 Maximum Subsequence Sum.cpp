#include<iostream>
using namespace std;

int f(int *a,int len,int &first,int &last)
{
	int sum = 0;
	int maxSum = 0;				//����	
	
	for(int i=0; i<len; i++) {
		sum += a[i];
		if(sum <= 0) {			//����Ϊ������ʼ�� 
			sum = 0;
			continue;
		} else {
			if(sum > maxSum) {
				maxSum = sum;
				last = i;
			}
		}
	}
	//�Ӻ���ǰȷ��first 
	sum = 0;
	for(int i=last; sum<maxSum; i--) {
		sum += a[i];
		first = i;
	}
	return maxSum;
}
int main()
{
//	freopen("01-2.txt","r",stdin);
	int N;
	int *a;
	int first = 0,last = 0;				//���������ͷ��β 
	
	cin >> N;
	a = new int[N];
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	cout << f(a,N,first,last) << " ";
	cout << a[first] << " " << a[last] << endl;
	
	return 0;
}
