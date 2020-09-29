#include<iostream>
using namespace std;

//n个球中取m个球,有多少种取法 
int f(int n,int m)
{
	if(n < m) return 0;
	if(n == m) return 1;
	if(m == 0) return 1;
	
	return f(n-1,m-1) + f(n-1,m);
}
int main()
{
	cout << f(10,3) << endl;
	return 0;
}
