//��������
//��������һ��ֻ�����Ӽ��Գ������ŵĺϷ����ʽ������ʽ��ֵ�����г���ʾ������
//�����ʽ
//��������һ�У�����һ�����ʽ��
//�����ʽ
//�������������ʽ��ֵ��
//��������
//1-2+3*(4-5)
//�������
//-4
//���ݹ�ģ��Լ��
//�������ʽ���Ȳ�����100�����ʽ����Ϸ���������̶���int�ڽ��С�
#include<iostream>
#include<cctype>
#include<stack>
using namespace std;

stack<char> s_char;
stack<int> s_int;
//���ʽ����
 
//��ջ������ 
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
	//�����ʽ��β������ 
	buf = "(";
	cin >> buff;
	buf += buff;
	buf += ')';
	//ɨ��
	for(int i=0; i<buf.length(); i++) {
		if(buf[i] == '(') {
			s_char.push('(');		
		} else if(isdigit(buf[i])) {
			//����ʾ���ֵ��ַ�������� 
			int ret = 0;
			while(isdigit(buf[i])) {
				ret *= 10;
				ret += buf[i]-'0';
				i++;
			}
			i--;
			s_int.push(ret);
		} else if(buf[i] == '*') {	//*���ȼ���� 
			s_char.push('*');
		} else if(buf[i] == '/') {
			char c = s_char.top();
			if(c == '*'){	//���ȼ���ջ����,��ջ���� 
				push_and_cal('*');
				s_char.push('/');
			} else {	//���ȼ���ջ����,ѹջ 
				s_char.push('/');
			}
		} else if(buf[i]=='+' || buf[i]=='-') {
			char c = s_char.top();
			if(c == '(') {	//���ȼ���ջ����,ѹջ
				s_char.push(buf[i]);
			} else {	//���ȼ���ջ����,��ջ���� 
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
