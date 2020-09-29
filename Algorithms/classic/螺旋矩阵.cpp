#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//21 22......
//20 07 08 09 10
//19 06 01 02 11
//18 05 04 03 12
//17 16 15 14 13
//规律:1的坐标(0,0),x方向向右为正,y方向向下为正.
//例如,
//7的坐标为(-1,-1),
//2的坐标为(0,1),3的坐标为(1,1).
//编程实现:输入任意一点,输出对应的数字

int foo(int x,int y)
{
	int t = max(abs(x),abs(y));
	int MIN = (2*t-1)*(2*t-1)+1;
	int v;

	if(y == -t)
		v = MIN+7*t-1+x;
	else if(y == t)
		v = MIN+3*t-1-x;
	else if(x == t)
		v = MIN+t-1+y;
	else if(x == -t)
		v = MIN+5*t-1-y;
	return v;
}

int main()
{
	int N = 5;

	//打印矩阵 
	for(int y=-N; y<=N; y++) {
		for(int x=-N; x<=N; x++) {
			cout.width(3);
			cout << foo(x,y) << " ";
		}
		cout << " " << endl;
	}
	//获取坐标(x,y)的值 
	int x,y;
	cin >> x >> y;
	cout << foo(x,y) << endl;

	return 0;
}

