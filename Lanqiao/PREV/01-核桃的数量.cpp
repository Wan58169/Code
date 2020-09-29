//小张是软件项目经理，他带领3个开发组。小张打算给每个组发一袋核桃（据传言能补脑）。
//他的要求是：
//
//1. 各组的核桃数量必须相同
//
//2. 各组内必须能平分核桃（当然是不能打碎的）
//
//3. 尽量提供满足1,2条件的最小数量（节约闹革命嘛）
//
//输入格式
//输入包含三个正整数a, b, c，表示每个组正在加班的人数，用空格分开（a,b,c<30）
//输出格式
//输出一个正整数，表示每袋核桃的数量。

//样例输入1
//2 4 5
//样例输出1
//20
//样例输入2
//3 1 1
//样例输出2
//3

#include<iostream>
using namespace std;

//求a和b的公倍数 
int cm(int a,int b)
{
	int ret;
	//找最大
	if(a > b) { 
		ret = a;
	} else { 
		ret = b;
	}
	//找最小公倍数 
	while(1) {
		if(ret%a==0 && ret%b==0) {
			return ret;
		} else {
			ret++;
		}
	}
}
int main()
{
	int a,b,c;
	int t; //a和b的公倍数
	 
	cin >> a >> b >> c;
	
	t = cm(a,b);
	
	cout << cm(t,c) << endl;
	return 0;
} 











