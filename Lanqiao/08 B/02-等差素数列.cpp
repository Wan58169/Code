#include<iostream>
#include<vector>
using namespace std;
//标题：等差素数列
//
//2,3,5,7,11,13,....是素数序列。
//类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
//上边的数列公差为30，长度为6。
//
//2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
//这是数论领域一项惊人的成果！
//
//有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：
//
//长度为10的等差素数列，其公差最小值是多少？
//
//注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。

const int MAX = 110000;
int a[MAX+1];
//生成素数表 
void generate_map()
{
	//置1
	for(int i=1; i<=MAX; i++) {
		a[i] = 1;
	}
	//1是素数 0不是素数 
	for(int i=2; 2*i<=MAX; i++) {
		a[2*i] = 0;
	}
	for(int i=3; i*i<=MAX; i++) {
		if(a[i] == 1) {
			for(int j=i*i; j<=MAX; j+=i) {
				a[j] = 0;
			}
		}
	}
}
int main()
{
	//生成素数表
	generate_map();
	for(int x=2; x<=MAX; x++) {	//首项 
		for(int d=1; d<=MAX/9; d++) { //公差 
			int cnt;
			for(cnt=0; cnt<10; cnt++) {
				if(a[x+cnt*d] == 0) break;
			}
			if(cnt == 10) {
				cout << d << endl;
				return 0;
			}
		}
	}
	return 0;
}
