#include<iostream>
#include<math.h>
using namespace std;
//斐波那契数列大家都非常熟悉。它的定义是：
//
//　　f(x) = 1 .... (x=1,2)
//　　f(x) = f(x-1) + f(x-2) .... (x>2)
//
//　　对于给定的整数 n 和 m，我们希望求出：
//　　f(1) + f(2) + ... + f(n) 的值。但这个值可能非常大，所以我们把它对 f(m) 取模。
//　　公式如下
//
//
//　　但这个数字依然很大，所以需要再对 p 求模。
//输入格式
//　　输入为一行用空格分开的整数 n m p (0 < n, m, p < 10^18)
//输出格式
//　　输出为1个整数，表示答案
//样例输入
//2 3 5
//样例输出
//0
//样例输入
//15 11 29
//样例输出
//25

//斐波拉契 
int main()
{
	long long n,m,p;
	long long a[1000] = {0};
	int maxLen;	//斐波拉契要求的最大项 
	long long sum;
	int ret;
	
	//设初值
	a[1] = 1;
	a[2] = 1;
	//读n,m,p
	cin >> n >> m >> p;
	maxLen = max(n,m); 
	//填值 
	for(int i=3; i<=maxLen; i++) {
		a[i] = a[i-1]+a[i-2];
	}
	//求sum 
	sum = 2*a[n];
	for(int i=1; i<=n-3; i++) {
		sum += a[i];
	}
	//求结果 
	ret = (sum%a[m])%p;
	cout << ret << endl;
	return 0;
}
