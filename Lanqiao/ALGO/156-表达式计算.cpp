//问题描述
//　　输入一个只包含加减乖除和括号的合法表达式，求表达式的值。其中除表示整除。
//输入格式
//　　输入一行，包含一个表达式。
//输出格式
//　　输出这个表达式的值。
//样例输入
//1-2+3*(4-5)
//样例输出
//-4
//数据规模和约定
//　　表达式长度不超过100，表达式运算合法且运算过程都在int内进行。
#include<iostream>
#include<cctype>
#include<stack>
using namespace std;

stack<char> s_char;
stack<int> s_int;
//表达式计算
 
//弹栈并计算 
void push_and_cal(char x)
{
	int n,m;
	int ret;
	
	n = s_int.top();
	s_int.pop();
	m = s_int.top();
	s_int.pop();
	if(x == '*') {
		ret = m*n;
	} else if(x == '/') {
		ret = m/n;
	} else if(x == '+') {
		ret = m+n;
	} else if(x == '-') {
		ret = m-n;
	}
	s_int.push(ret);
	s_char.pop();
}

int main()
{
	string buf,buff;
	//给表达式首尾加括号 
	buf = "(";
	cin >> buff;
	buf += buff;
	buf += ')';
	//扫描
	for(int i=0; i<buf.length(); i++) {
		if(buf[i] == '(') {
			s_char.push('(');		
		} else if(isdigit(buf[i])) {
			//将表示数字的字符变成整数 
			int ret = 0;
			while(isdigit(buf[i])) {
				ret *= 10;
				ret += buf[i]-'0';
				i++;
			}
			i--;
			s_int.push(ret);
		} else if(buf[i] == '*') {	//*优先级最高 
			s_char.push('*');
		} else if(buf[i] == '/') {
			char c = s_char.top();
			if(c == '*'){	//优先级比栈顶低,弹栈计算 
				push_and_cal('*');
				s_char.push('/');
			} else {	//优先级比栈顶高,压栈 
				s_char.push('/');
			}
		} else if(buf[i]=='+' || buf[i]=='-') {
			char c = s_char.top();
			if(c == '(') {	//优先级比栈顶高,压栈
				s_char.push(buf[i]);
			} else {	//优先级比栈顶低,弹栈计算 
				push_and_cal(c);
				s_char.push(buf[i]);
			}
		} else if(buf[i] == ')') {
			char c;
			while((c=s_char.top()) != '(') {
				push_and_cal(c);
			}
			s_char.pop();
		}
	} 
	cout << s_int.top() << endl;
	return 0;
}
