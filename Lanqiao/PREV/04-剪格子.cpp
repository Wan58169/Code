#include<iostream>
using namespace std;

//如下图所示，3 x 3 的格子中填写了一些整数。
//
//+--*--+--+
//|10* 1|52|
//+--****--+
//|20|30* 1|
//*******--+
//| 1| 2| 3|
//+--+--+--+
//我们沿着图中的星号线剪开，得到两个部分，每个部分的数字和都是60。
//
//本题的要求就是请你编程判定：对给定的m x n 的格子中的整数，是否可以分割为两个部分，使得这两个区域的数字和相等。
//
//如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。
//
//如果无法分割，则输出 0。
//
//输入格式
//程序先读入两个整数 m n 用空格分割 (m,n<10)。
//
//表示表格的宽度和高度。
//
//接下来是n行，每行m个正整数，用空格分开。每个整数不大于10000。
//
//输出格式
//输出一个整数，表示在所有解中，包含左上角的分割区可能包含的最小的格子数目。
//样例输入1
//3 3
//10 1 52
//20 30 1
//1 2 3
//样例输出1
//3
//样例输入2
//4 3
//1 1 1 1
//1 30 80 2
//1 1 1 100
//样例输出2
//10

int dx[] = {-1,1, 0,0};	//方向 上下左右 
int dy[] = { 0,0,-1,1};
int map[10][10],isVisited[10][10];	
int N,M;	//N为行数 M为列数 
int SUM = 0;	

//核心:试探 
//方法:搜索+回溯

//评价函数 
int isRight(int x,int y,int cur_sum)
{
	if(x<0 || y<0 || x>N-1 || y>M-1) { //如果超出边界 
		return 0; 
	} else if(isVisited[x][y] == 1) { //如果已经访问过 
		return 0;
	} else if(cur_sum+map[x][y] > SUM/2) { //如果加上下一步,值超过SUM/2 
		return 0;
	} else {
	 	return 1;
	}
}
int dfs(int x,int y,int cur_sum)
{
	if(cur_sum == SUM/2) {
		return 1;
	}
	for(int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(isRight(nx,ny,cur_sum)) {
			isVisited[nx][ny] = 1;
			int cnt = dfs(nx,ny,cur_sum+map[nx][ny]);
			if(cnt) return cnt+1; //如果有路可走，则算一种方案 
			isVisited[nx][ny] = 0;
		}
	}
	//如果四个方向都不通，则返回0 
	return 0;
}
int main()
{
	freopen("4.txt","r",stdin);
	cin >> M >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> map[i][j];
			SUM += map[i][j];
			isVisited[i][j] = 0;
		}
	}
	if(SUM%2 == 1) {	//奇数不可能 
		cout << "0" << endl;
	} else {
		isVisited[0][0] = 1;
		cout << dfs(0,0,map[0][0]) << endl;
	}
	return 0;
}
