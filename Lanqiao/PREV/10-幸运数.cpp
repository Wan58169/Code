//��������
//�������ǲ�����ѧ������ķ�����ġ��������������������Ƶġ�ɸ��������
//
//��
//���ȴ�1��ʼд����Ȼ��1,2,3,4,5,6,....
//
//1 ���ǵ�һ����������
//
//���Ǵ�2�������ʼ������������ܱ�2��������ɾ������Ϊ��
//
//1 _ 3 _ 5 _ 7 _ 9 ....
//
//���������������¼���Ϊ��
//
//1 3 5 7 9 .... ����ʱ��3Ϊ��2����������Ȼ��������ܱ�3���������λ�õ���ɾȥ��
//ע�⣬�����λ�ã������Ǹ��������ܷ�3����!! ɾ����Ӧ����5��11, 17, ...
//
//��ʱ7Ϊ��3����������Ȼ����ɾȥ���λ���ܱ�7������(19,39,...)
//
//���ʣ�µ��������ƣ�
//
//1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, ...
//
//�����ʽ
//��������������m n, �ÿո�ֿ� (m < n < 1000*1000)
//�����ʽ
//������� λ��m��n֮����������ĸ�����������m��n����
//��������1
//1 20
//�������1
//5
//��������2
//30 69
//�������2
//8
#include<iostream>
using namespace std;

int M,N;			//�������˵� 

int main()
{
	cin >> M >> N;
	
	int aLen = N;
	int *a = new int[aLen+1];	//aΪ��,bΪ��	
	//��ʼ������a
	for(int i=1; i<=N; i++) 
	{
		a[i] = i;			//��Ȼ������ 
	} 
	//��2��ʼ 
	int cnt_del = 0;
	for(int i=1; i<=N; i++) 
	{
		if(i%2 == 0) 
		{
			a[i] = 0;
			cnt_del++;
		}	
	}
	int bLen = aLen-cnt_del;
	int *b = new int[bLen+1];
	for(int i=1,j=1; i<=aLen; i++)
	{
		if(a[i] != 0) 
		{
			b[j++] = a[i];
		}
	}
	//������b�е����ݵ��ص�����a��
	aLen = bLen;
	delete a;
	a = new int[aLen+1];
	for(int i=1; i<=aLen; i++)
	{	
		a[i] = b[i];
	} 
	//��3��ʼ 
	int luckNum = 3;
	int luckId = 2;
	while(1) 
	{
		cnt_del = 0;
		for(int i=1; i<=aLen; i++) 
		{
			if(i%luckNum == 0)
			{
				a[i] = 0;
				cnt_del++;
			}
		}
		bLen = aLen-cnt_del;
		delete b;
		b = new int[bLen+1];
		for(int i=1,j=1; i<=aLen; i++)
		{
			if(a[i] != 0)
			{
				b[j++] = a[i];
			}
		}
		//������b�е����ݵ��ص�����a��
		aLen = bLen;
		delete a;
		a = new int[aLen+1];
		for(int i=1; i<=aLen; i++)
		{	
			a[i] = b[i];
		}  
		luckId++;
		luckNum = a[luckId];
		if(luckNum > aLen) break;
	}
//	//��ӡ����a
	int cnt = 0;
	for(int i=1; i<=aLen; i++) 
	{
		if(a[i]<N && a[i]>M)
		{
			cnt++;
		}
	} 
	cout << cnt << endl;
	return 0;
}
