//��������
//������ͯ��������KλС���ѵ�С�������͡�С���ó�����ص��ɿ����д�С�����ǡ�
//����С��һ����N���ɿ��������е�i����Hi x Wi�ķ�����ɵĳ����Ρ�
//
//
//����Ϊ�˹�ƽ�����С����Ҫ���� N ���ɿ������г�K���ɿ����ָ�С�����ǡ��г����ɿ�����Ҫ���㣺
//
//
//����1. ��״�������Σ��߳�������
//����2. ��С��ͬ
//
//
//��������һ��6x5���ɿ��������г�6��2x2���� ��������2��3x3���ɿ�����
//
//
//������ȻС�����Ƕ�ϣ���õ����ɿ��������ܴ����ܰ�СHi��������ı߳��Ƕ���ô��
//�����ʽ
//������һ�а�����������N��K��(1 <= N, K <= 100000)
//��������N��ÿ�а�����������Hi��Wi��(1 <= Hi, Wi <= 100000)
//�������뱣֤ÿλС���������ܻ��һ��1x1���ɿ�����
//�����ʽ
//��������г����������ɿ��������ܵı߳���
//��������
//2 10
//6 5
//5 6
//�������
//2
#include<iostream>
using namespace std;

//���峤���� 
typedef struct {
	int H;			//�� 
	int W;			//�� 
}RECT;

const int MAX = 110000;
int N,K;				//�ɿ���������С��������
int L = 2;				//�����ε���ʼ�߳�
RECT chocolate[MAX];

int isOk(int length)
{
	int tK = 0;					//�ܹ��г������εĿ��� 
	
	for(int i=0; i<N; i++) {
		tK += (chocolate[i].H/length)*(chocolate[i].W/length);
	}
	if(tK < K) return 0;	
	else return 1;
}
int main()
{
	cin >> N >> K;
	//�����ɿ�����Ϣ 
	for(int i=0; i<N; i++) {
		cin >> chocolate[i].H >> chocolate[i].W;
		//Ԥ�������α߳� 
		if(chocolate[i].H < chocolate[i].W) {
			L = chocolate[i].W;
		} else {
			L = chocolate[i].H;
		}
	}
	//����ȷ��L 
	int left = 1;
	int right = L;
	int maxLen = 1;			//��¼���߳� 
	while(left <= right) {
		int mid = (left+right)/2;
		if(isOk(mid)) {
			if(mid > maxLen) maxLen = mid;
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	cout << maxLen << endl;
	return 0;
}
