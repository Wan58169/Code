#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int cmp(const void *a,const void *b)
{
	return *(double*)a - *(double*)b;	
}

void f(double buf[],int bufLen)
{
	int i;

	qsort(buf,bufLen,sizeof(double),cmp);		
	for(i=0; bufLen != 1; i++) {
		buf[i+1] = (buf[i]+buf[i+1])/2;
		bufLen--;
	}
	int j;
	for(j=0; j <= buf[i]; j++) 
		;
	cout << j-1 << endl;
}

int main()
{
	int N;

	cin >> N;
	double buf[N];
	for(int i=0; i<N; i++) {
		cin >> buf[i];
	}
	f(buf,N);

	return 0;
}
