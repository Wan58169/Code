//模拟程序型计算器，依次输入指令，可能包含的指令有
//
//1. 数字：'NUM X'，X为一个只包含大写字母和数字的字符串，表示一个当前进制的数
//2. 运算指令：'ADD','SUB','MUL','DIV','MOD'，分别表示加减乘，除法取商，除法取余
//3. 进制转换指令：'CHANGE K'，将当前进制转换为K进制(2≤K≤36)
//4. 输出指令：'EQUAL'，以当前进制输出结果
//5. 重置指令：'CLEAR'，清除当前数字
//
//
//指令按照以下规则给出：
//数字，运算指令不会连续给出，进制转换指令，输出指令，重置指令有可能连续给出
//运算指令后出现的第一个数字，表示参与运算的数字。且在该运算指令和该数字中间不会出现运算指令和输出指令
//重置指令后出现的第一个数字，表示基础值。且在重置指令和第一个数字中间不会出现运算指令和输出指令
//进制转换指令可能出现在任何地方
//
//运算过程中中间变量均为非负整数，且小于2^63。
//以大写的'A'~'Z'表示10~35

//输入格式
//　　第1行：1个n，表示指令数量
//　　第2..n+1行：每行给出一条指令。指令序列一定以'CLEAR'作为开始，并且满足指令规则
//输出格式
//　　依次给出每一次'EQUAL'得到的结果
//样例输入
//7
//CLEAR
//NUM 1024
//CHANGE 2
//ADD
//NUM 100000
//CHANGE 8
//EQUAL
//样例输出
//2040
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

int radix = 10;						//默认十进制
string operCode = "";				//操作码,ADD SUM MUL DIV MOD
long long  operNumA=0,operNumB=0;	//操作数,A主B辅 

//算数运算
void cal_AB()
{
	if(operCode == "ADD") {
		operNumA += operNumB;
	} else if(operCode == "SUB") {
		operNumA -= operNumB;
	} else if(operCode == "MUL") {
		operNumA *= operNumB;
	} else if(operCode == "DIV") {
		operNumA /= operNumB;
	} else if(operCode == "MOD") {
		operNumA %= operNumB;
	}
} 
//将操作数转换为十进制再进行计算
long long radix_to_ten(string num)
{
	long long ret = 0;
	int x = 0;				//幂次方 
	
	for(int i=num.length()-1; i>=0; i--) {		//位权法累加求和 
		if(num[i]>='A' && num[i]<='Z') {
			ret += (num[i]-'A')*pow(radix,x);
			x++;
		} else if(isdigit(num[i])) {
			ret += (num[i]-'0')*pow(radix,x);
			x++;
		}
	}
	return ret;
} 
//将十进制的结果转换为规定进制的字符串 
void radix_to_now()
{
	char buf[128];
	int t = operNumA;
	int k = 0;
	
	while(t) {
		if(t%radix>=10 && t%radix<=35) {
			sprintf(buf+k,"%c",t%radix+'A');			//将A~Z写入buf中 
		} else {
			sprintf(buf+k,"%d",t%radix);				//将0~9写入buf中 
		}
		k++;
		t /= radix;
	}
	for(int i=k-1; i>=0; i--) {							//打印结果 
		cout << buf[i];
	}
}
//处理命令 
void solve_order(string order,string num)
{
	if(order == "NUM") {
		if(operCode == "") {				//没有暂存的指令
			operNumA = radix_to_ten(num);
		} else {
			operNumB = radix_to_ten(num);
			cal_AB();						//算数运算 
			operCode = "";
		}
	} else if(order == "CHANGE") {			//转化进制 
		radix = atoi(num.c_str());
	} else if(order == "CLEAR") {		
		operNumA = 0;
		operCode = "";
	} else if(order == "EQUAL") {			//输出结果 
		radix_to_now();						//按规定进制输出 
	} else {								
		operCode = order;						
	}
}

int main()
{
	freopen("55.txt","r",stdin);
	int N;				//指令条数 
	int radix = 10;		//进制 
	
	cin >> N;
	getchar();			//读掉空白字符 
	for(int i=0; i<N; i++) {
		string buf;
		getline(cin,buf); 						//读命令 
		int index = buf.find(" ");				//判断命令是否带参数 
		if(index < 0) {							//如果不带参数,比如ADD 
			solve_order(buf,"");
		} else {								//命令带参数,比如 NUM 1024 
			solve_order(buf.substr(0,index),buf.substr(index+1));
		}
	} 
	return 0;
}
