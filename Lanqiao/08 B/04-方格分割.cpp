#include<iostream>
using namespace std;

//标题：方格分割

//6x6的方格，沿着格子的边线剪开成两部分。
//要求这两部分的形状完全相同。

//方格分割
//核心:深搜+回溯
//方法:将点和线看作分割的依据,而不是方格
const int N = 6;
int map[N+1][N+1];	//由点组成的矩阵 
int dx[] = {-1,1,0,0};	//方向:上下左右 
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
	//初始化map
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			map[i][j] = 0;
		}
	}	
	map[N/2][N/2] = 1;	//分割线必过中心对称点
	dfs(N/2,N/2); 
	cout << cnt/4 << endl;
	return 0;
} 
