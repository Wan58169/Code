//问题描述
//幸运数是波兰数学家乌拉姆命名的。它采用与生成素数类似的“筛法”生成
//
//。
//首先从1开始写出自然数1,2,3,4,5,6,....
//
//1 就是第一个幸运数。
//
//我们从2这个数开始。把所有序号能被2整除的项删除，变为：
//
//1 _ 3 _ 5 _ 7 _ 9 ....
//
//把它们缩紧，重新记序，为：
//
//1 3 5 7 9 .... 。这时，3为第2个幸运数，然后把所有能被3整除的序号位置的数删去。
//注意，是序号位置，不是那个数本身能否被3整除!! 删除的应该是5，11, 17, ...
//
//此时7为第3个幸运数，然后再删去序号位置能被7整除的(19,39,...)
//
//最后剩下的序列类似：
//
//1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, ...
//
//输入格式
//输入两个正整数m n, 用空格分开 (m < n < 1000*1000)
//输出格式
//程序输出 位于m和n之间的幸运数的个数（不包含m和n）。
//样例输入1
//1 20
//样例输出1
//5
//样例输入2
//30 69
//样例输出2
//8
#include<iostream>
using namespace std;

int M,N;			//左右两端点 

int main()
{
	cin >> M >> N;
	
	int aLen = N;
	int *a = new int[aLen+1];	//a为主,b为辅	
	//初始化数组a
	for(int i=1; i<=N; i++) 
	{
		a[i] = i;			//自然数序列 
	} 
	//从2开始 
	int cnt_del = 0;
	for(int i=1; i<=N; i++) 
	{
		if(i%2 == 0) 
		{
			a[i] = 0;
			cnt_del++;
		}	
	}
	int bLen = aLen-cnt_del;
	int *b = new int[bLen+1];
	for(int i=1,j=1; i<=aLen; i++)
	{
		if(a[i] != 0) 
		{
			b[j++] = a[i];
		}
	}
	//把数组b中的数据倒回到数组a中
	aLen = bLen;
	delete a;
	a = new int[aLen+1];
	for(int i=1; i<=aLen; i++)
	{	
		a[i] = b[i];
	} 
	//从3开始 
	int luckNum = 3;
	int luckId = 2;
	while(1) 
	{
		cnt_del = 0;
		for(int i=1; i<=aLen; i++) 
		{
			if(i%luckNum == 0)
			{
				a[i] = 0;
				cnt_del++;
			}
		}
		bLen = aLen-cnt_del;
		delete b;
		b = new int[bLen+1];
		for(int i=1,j=1; i<=aLen; i++)
		{
			if(a[i] != 0)
			{
				b[j++] = a[i];
			}
		}
		//把数组b中的数据倒回到数组a中
		aLen = bLen;
		delete a;
		a = new int[aLen+1];
		for(int i=1; i<=aLen; i++)
		{	
			a[i] = b[i];
		}  
		luckId++;
		luckNum = a[luckId];
		if(luckNum > aLen) break;
	}
//	//打印数组a
	int cnt = 0;
	for(int i=1; i<=aLen; i++) 
	{
		if(a[i]<N && a[i]>M)
		{
			cnt++;
		}
	} 
	cout << cnt << endl;
	return 0;
}
