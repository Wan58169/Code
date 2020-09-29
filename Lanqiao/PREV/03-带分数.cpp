//100 可以表示为带分数的形式：100 = 3 + 69258 / 714。
//
//还可以表示为：100 = 82 + 3546 / 197。
//
//注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。
//
//类似这样的带分数，100 有 11 种表示法。
//
//输入格式
//从标准输入读入一个正整数N (N<1000*1000)
//
//输出格式
//程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
//
//注意：不要求输出每个表示，只统计有多少表示法！
//
//样例输入1
//100
//样例输出1
//11
//样例输入2
//105
//样例输出2
//6
#include<iostream>
using namespace std;

int N;	//正整数N 
int NLen;	//正整数N的长度
int cnt = 0;	//计数共有多少个带分数
 
//算出正整数N的长度 
int getNLen()
{
	int len = 0;
	int t = N;
	
	while(t != 0) {	
		len++;
		t /= 10;	
	}
	return len;
}
//将字符串变成数字 
int getNum(int list[],int f,int r)
{
	int num = 0;
	
	for(int i=f; i<=r; i++) {
		num = list[i] + num*10;	//进位 
	}
	return num;
}
//list为全排列数组,k为起始位置,len为数组长度 
void f(int list[],int k,int len)
{
	if(k == len) {
		int a,b,c;						// N = a+(b/c)
		int bLast;				  		//bLast为b的最后一位数 
		//从a入手 
		for(int i=0; i<NLen; i++) {
			a = getNum(list,0,i);		//计算a 
			bLast = ((N-a)*list[8])%10;	//计算b的最后一位数 
			for(int j=i+1; j<8; j++) {	//计算b和C 
				if(list[j] == bLast) {
					b = getNum(list,i+1,j);
					c = getNum(list,j+1,8);
					if(b%c==0 && N==a+b/c) {
//						cout << a << "+" << b << "/" << c << endl; 
						cnt++;
					}
					break;
				}
			}
		} 
		return;
	}
	for(int i=k; i<len; i++) {
		{int t = list[k]; list[k] = list[i]; list[i] = t;}
		f(list,k+1,len);
		{int t = list[k]; list[k] = list[i]; list[i] = t;}
	}
}
int main()
{
	int list[] = {1,2,3,4,5,6,7,8,9};
	cin >> N;
	
	NLen = getNLen();
	f(list,0,sizeof(list)/sizeof(list[0]));
	cout << cnt << endl;
	return 0;
}
