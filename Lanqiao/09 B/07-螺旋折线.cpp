//���⣺��������
//
//�������߾���ƽ������������ǡ��һ�Ρ�
//
//12 13 14 15 16
//11  2  3  4 17
//10  1  0  5 18
// 9  8  7  6 19
//24 23 22 21 20
//
//��������(X, Y)�����Ƕ�������ԭ��ľ���dis(X, Y)�Ǵ�ԭ�㵽(X, Y)���������߶εĳ��ȡ�
//
//����dis(0, 1)=3, dis(-2, -1)=9
//
//������������(X, Y)�����ܼ����dis(X, Y)��
//
//�������ʽ��
//X��Y  
//
//����40%�����ݣ�-1000 <= X, Y <= 1000  
//����70%�����ݣ�-100000 <= X�� Y <= 100000  
//����100%������, -1000000000 <= X, Y <= 1000000000  
//
//�������ʽ��
//���dis(X, Y)  
//
//���������롿
//0 1
//
//�����������
//3

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//��������ṹ�� 
typedef struct {
	int x;
	int y;
}point;

enum dir {Up,Down,Left,Right};			//�ƶ����� 

int main()
{					
	int N;								//����ı߳� 
	int x,y;							//Ŀ������
	int **a;							//����
		 
	cin >> x >> y;
	N = 2*max(abs(x),abs(y))+1;
	a = new int *[N];
	for(int i=0; i<N; i++) {
		a[i] = new int[N];
	}
	//ȷ�����ĵ� 
	point center,now;					//���ĵ� �� ��ǰ��	
	center.x = center.y = N/2;				
	a[center.x][center.y] = 0;
	now.x = center.x, now.y = center.y;
	int d = 1;							//ÿ�ο��صľ��� 
	int value = 1;						//Ϳɫ 
	while(now.x!=N-1 || now.y!=0) {
		int minLim = center.x-d, maxLim = center.x+d;
		//����һ�� 
		a[now.x][--now.y] = value++;		
		//����
		for(int i=now.x-1; i>=minLim; i--) {
			a[i][now.y] = value++;
		} 
		now.x = minLim;
		//����
		for(int i=now.y+1; i<=maxLim; i++) {
			a[now.x][i] = value++;
		} 
		now.y = maxLim;
		//����
		for(int i=now.x+1; i<=maxLim; i++) {
			a[i][now.y] = value++;
		} 
		now.x = maxLim;
		//����
		for(int i=now.y-1; i>=minLim; i--) {
			a[now.x][i] = value++;
		} 
		now.y = minLim;
		d++;
	}
	//���Ŀ�������ֵ
	cout << a[center.x-y][center.y+x] << endl; 
	for(int i=0; i<N; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
} 
