#include<iostream>
using namespace std;

//���⣺����ָ�

//6x6�ķ������Ÿ��ӵı��߼����������֡�
//Ҫ���������ֵ���״��ȫ��ͬ��

//����ָ�
//����:����+����
//����:������߿����ָ������,�����Ƿ���
const int N = 6;
int map[N+1][N+1];	//�ɵ���ɵľ��� 
int dx[] = {-1,1,0,0};	//����:�������� 
int dy[] = {0,0,-1,1};
int cnt = 0;	

void dfs(int x,int y)
{
	if(x==0 || x==N || y==0 || y==N) {
		cnt++;
		return;
	}
	for(int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(map[nx][ny] == 0) {
			map[nx][ny] = 1;
			map[N-nx][N-ny] = 1;
			dfs(nx,ny);
			map[nx][ny] = 0;
			map[N-nx][N-ny] = 0;
		} 
	}
} 
int main()
{
	//��ʼ��map
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			map[i][j] = 0;
		}
	}	
	map[N/2][N/2] = 1;	//�ָ��߱ع����ĶԳƵ�
	dfs(N/2,N/2); 
	cout << cnt/4 << endl;
	return 0;
} 
