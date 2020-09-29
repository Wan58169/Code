#include<iostream>
#include<cctype>
#include<stack>
using namespace std;

stack<char> s;

//���ȼ�����ջ��Ԫ�� 
bool isprior(char c) 
{
	//���ջΪ�� 
	if(s.empty()) {
		return true;
	}
	//���ջ���� 
	char top = s.top();
	if(top == '(') {
		return true;
	}
	switch(c) {
		case '-' : {
			return false;
		}
		case '+' : {
			if(top=='-' || top=='+') {
				return true;
			} else {
  		  		return false;
			}
		}
		case '/' : {
			if(top == '*') {
				return false;
			} else {
				return true;
			}
		}
		case '*' : {
			return true;
		}
	}	
}
int main()
{
	string exp;
	
	cin >> exp;
	for(int i=0; i<exp.length(); i++) {
		if(isdigit(exp[i])) {
			cout << exp[i]-'0' << " ";		
		} else if(isalpha(exp[i])) {
			cout << exp[i] << " ";
		} else if(exp[i] == '(') {
			s.push(exp[i]);
		} else if(exp[i] == ')') {	//������һֱ��ջ 
			while(1) {
				char c = s.top();
				if(c == '(') {
					s.pop();
					break;
				}
				cout << s.top() << " ";
				s.pop();
			}
		} else if(isprior(exp[i])) {
			s.push(exp[i]);
		} else {	//���ȼ���ջ����һֱ��ջ 
			while(!isprior(exp[i]) && !s.empty()) {
				cout << s.top() << " ";
				s.pop();
			}
			s.push(exp[i]);
		}
	}
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
