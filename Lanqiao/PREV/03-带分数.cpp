//100 ���Ա�ʾΪ����������ʽ��100 = 3 + 69258 / 714��
//
//�����Ա�ʾΪ��100 = 82 + 3546 / 197��
//
//ע���������������У�����1~9�ֱ������ֻ����һ�Σ�������0����
//
//���������Ĵ�������100 �� 11 �ֱ�ʾ����
//
//�����ʽ
//�ӱ�׼�������һ��������N (N<1000*1000)
//
//�����ʽ
//�������������������1~9���ظ�����©����ɴ�������ʾ��ȫ��������
//
//ע�⣺��Ҫ�����ÿ����ʾ��ֻͳ���ж��ٱ�ʾ����
//
//��������1
//100
//�������1
//11
//��������2
//105
//�������2
//6
#include<iostream>
using namespace std;

int N;	//������N 
int NLen;	//������N�ĳ���
int cnt = 0;	//�������ж��ٸ�������
 
//���������N�ĳ��� 
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
//���ַ���������� 
int getNum(int list[],int f,int r)
{
	int num = 0;
	
	for(int i=f; i<=r; i++) {
		num = list[i] + num*10;	//��λ 
	}
	return num;
}
//listΪȫ��������,kΪ��ʼλ��,lenΪ���鳤�� 
void f(int list[],int k,int len)
{
	if(k == len) {
		int a,b,c;						// N = a+(b/c)
		int bLast;				  		//bLastΪb�����һλ�� 
		//��a���� 
		for(int i=0; i<NLen; i++) {
			a = getNum(list,0,i);		//����a 
			bLast = ((N-a)*list[8])%10;	//����b�����һλ�� 
			for(int j=i+1; j<8; j++) {	//����b��C 
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
