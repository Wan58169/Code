#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	int *a;
	
	cin >> N;
	a = new int[N];
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	sort(a,a+N);
	//���
	for(int i=0; i<N-1; i++) {
		cout << a[i] << " ";
	} 
	cout << a[N-1];
}
