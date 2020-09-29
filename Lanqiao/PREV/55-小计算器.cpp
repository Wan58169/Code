//ģ������ͼ���������������ָ����ܰ�����ָ����
//
//1. ���֣�'NUM X'��XΪһ��ֻ������д��ĸ�����ֵ��ַ�������ʾһ����ǰ���Ƶ���
//2. ����ָ�'ADD','SUB','MUL','DIV','MOD'���ֱ��ʾ�Ӽ��ˣ�����ȡ�̣�����ȡ��
//3. ����ת��ָ�'CHANGE K'������ǰ����ת��ΪK����(2��K��36)
//4. ���ָ�'EQUAL'���Ե�ǰ����������
//5. ����ָ�'CLEAR'�������ǰ����
//
//
//ָ������¹��������
//���֣�����ָ�����������������ת��ָ����ָ�����ָ���п�����������
//����ָ�����ֵĵ�һ�����֣���ʾ������������֡����ڸ�����ָ��͸������м䲻���������ָ������ָ��
//����ָ�����ֵĵ�һ�����֣���ʾ����ֵ����������ָ��͵�һ�������м䲻���������ָ������ָ��
//����ת��ָ����ܳ������κεط�
//
//����������м������Ϊ�Ǹ���������С��2^63��
//�Դ�д��'A'~'Z'��ʾ10~35

//�����ʽ
//������1�У�1��n����ʾָ������
//������2..n+1�У�ÿ�и���һ��ָ�ָ������һ����'CLEAR'��Ϊ��ʼ����������ָ�����
//�����ʽ
//�������θ���ÿһ��'EQUAL'�õ��Ľ��
//��������
//7
//CLEAR
//NUM 1024
//CHANGE 2
//ADD
//NUM 100000
//CHANGE 8
//EQUAL
//�������
//2040
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

int radix = 10;						//Ĭ��ʮ����
string operCode = "";				//������,ADD SUM MUL DIV MOD
long long  operNumA=0,operNumB=0;	//������,A��B�� 

//��������
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
//��������ת��Ϊʮ�����ٽ��м���
long long radix_to_ten(string num)
{
	long long ret = 0;
	int x = 0;				//�ݴη� 
	
	for(int i=num.length()-1; i>=0; i--) {		//λȨ���ۼ���� 
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
//��ʮ���ƵĽ��ת��Ϊ�涨���Ƶ��ַ��� 
void radix_to_now()
{
	char buf[128];
	int t = operNumA;
	int k = 0;
	
	while(t) {
		if(t%radix>=10 && t%radix<=35) {
			sprintf(buf+k,"%c",t%radix+'A');			//��A~Zд��buf�� 
		} else {
			sprintf(buf+k,"%d",t%radix);				//��0~9д��buf�� 
		}
		k++;
		t /= radix;
	}
	for(int i=k-1; i>=0; i--) {							//��ӡ��� 
		cout << buf[i];
	}
}
//�������� 
void solve_order(string order,string num)
{
	if(order == "NUM") {
		if(operCode == "") {				//û���ݴ��ָ��
			operNumA = radix_to_ten(num);
		} else {
			operNumB = radix_to_ten(num);
			cal_AB();						//�������� 
			operCode = "";
		}
	} else if(order == "CHANGE") {			//ת������ 
		radix = atoi(num.c_str());
	} else if(order == "CLEAR") {		
		operNumA = 0;
		operCode = "";
	} else if(order == "EQUAL") {			//������ 
		radix_to_now();						//���涨������� 
	} else {								
		operCode = order;						
	}
}

int main()
{
	freopen("55.txt","r",stdin);
	int N;				//ָ������ 
	int radix = 10;		//���� 
	
	cin >> N;
	getchar();			//�����հ��ַ� 
	for(int i=0; i<N; i++) {
		string buf;
		getline(cin,buf); 						//������ 
		int index = buf.find(" ");				//�ж������Ƿ������ 
		if(index < 0) {							//�����������,����ADD 
			solve_order(buf,"");
		} else {								//���������,���� NUM 1024 
			solve_order(buf.substr(0,index),buf.substr(index+1));
		}
	} 
	return 0;
}
