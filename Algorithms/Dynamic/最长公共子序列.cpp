#include<iostream>
#include<cmath>
using namespace std;

//求最长公共子序列的长度
string s1,s2;
int N,M;
int MaxLen[100][100];
int Max = -1;

int main()
{
	cin >> s1 >> s2;
	//初始化 
	N = s1.length();
	M = s2.length();
	//维护表
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(s1[i] == s2[j]) {	//如果两串末尾字符相同,则有资格纳入公共子序列中 
				MaxLen[i][j] = MaxLen[i-1][j-1]+1;
			} else {	//不相同,则选择之前最长的公共子序列 
				MaxLen[i][j] = max(MaxLen[i-1][j],MaxLen[i][j-1]);
			}
		}
	} 
	//输出结果 
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(Max < MaxLen[i][j]) {
				Max = MaxLen[i][j];
			}
		}
	}
	cout << Max << endl;
	return 0;
} 
