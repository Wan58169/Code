#include<iostream>
#include<cmath>
using namespace std;

//������������еĳ���
string s1,s2;
int N,M;
int MaxLen[100][100];
int Max = -1;

int main()
{
	cin >> s1 >> s2;
	//��ʼ�� 
	N = s1.length();
	M = s2.length();
	//ά����
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(s1[i] == s2[j]) {	//�������ĩβ�ַ���ͬ,�����ʸ����빫���������� 
				MaxLen[i][j] = MaxLen[i-1][j-1]+1;
			} else {	//����ͬ,��ѡ��֮ǰ��Ĺ��������� 
				MaxLen[i][j] = max(MaxLen[i-1][j],MaxLen[i][j-1]);
			}
		}
	} 
	//������ 
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
