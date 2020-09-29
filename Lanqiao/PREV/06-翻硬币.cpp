#include<iostream>
using namespace std;

//小明正在玩一个“翻硬币”的游戏。
//桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。
//比如，可能情形是：**oo***oooo
//如果同时翻转左边的两个硬币，则变为：oooo***oooo
//现在的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,
//那么对特定的局面，最少要翻动多少次呢？
//我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求：
//
//输入格式
//两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000
//
//输出格式
//一个整数，表示最小操作步数。
//
//样例输入1
//**********
//o****o****
//样例输出1
//5
//样例输入2
//*o**o***o***
//*o***o**o***
//样例输出2
//1

//找状态不同的硬币位置 
int different_index(string s1,string s2)
{
	//如果存在状态不同的位置，则返回下标 
	for(int i=0; i<s1.length(); i++) {
		if(s1[i] != s2[i]) {
			return i;
		}	
	}
	//否则返回最后一个硬币的下标 
	return s1.length()-1;
}
//翻硬币
int main()
{
	string s1,s2;
	int i;	//状态不同的硬币下标 
	int cnt = 0;
	
	cin >> s1 >> s2;
	i = different_index(s1,s2);
	while(1) {
		if(i == s1.length()-1) break;
		if(s1 == s2) break;
		if(s1[i] != s2[i]){
			if(s1[i] == '*') {
				s1[i] = 'o';
			} else if(s1[i] == 'o') {
				s1[i] = '*';
			}
			if(s1[i+1] == '*') {
				s1[i+1] = 'o';
			} else if(s1[i+1] == 'o') {
				s1[i+1] = '*';
			}
			cnt++;
		}
		i++;
	}
	cout << cnt << endl;
	return 0;
} 
