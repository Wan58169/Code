//标题：螺旋折线
//
//螺旋折线经过平面上所有整点恰好一次。
//
//12 13 14 15 16
//11  2  3  4 17
//10  1  0  5 18
// 9  8  7  6 19
//24 23 22 21 20
//
//对于整点(X, Y)，我们定义它到原点的距离dis(X, Y)是从原点到(X, Y)的螺旋折线段的长度。
//
//例如dis(0, 1)=3, dis(-2, -1)=9
//
//给出整点坐标(X, Y)，你能计算出dis(X, Y)吗？
//
//【输入格式】
//X和Y  
//
//对于40%的数据，-1000 <= X, Y <= 1000  
//对于70%的数据，-100000 <= X， Y <= 100000  
//对于100%的数据, -1000000000 <= X, Y <= 1000000000  
//
//【输出格式】
//输出dis(X, Y)  
//
//【样例输入】
//0 1
//
//【样例输出】
//3

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//定义坐标结构体 
typedef struct {
	int x;
	int y;
}point;

enum dir {Up,Down,Left,Right};			//移动方向 

int main()
{					
	int N;								//矩阵的边长 
	int x,y;							//目标坐标
	int **a;							//矩阵
		 
	cin >> x >> y;
	N = 2*max(abs(x),abs(y))+1;
	a = new int *[N];
	for(int i=0; i<N; i++) {
		a[i] = new int[N];
	}
	//确定中心点 
	point center,now;					//中心点 和 当前点	
	center.x = center.y = N/2;				
	a[center.x][center.y] = 0;
	now.x = center.x, now.y = center.y;
	int d = 1;							//每次开拓的距离 
	int value = 1;						//涂色 
	while(now.x!=N-1 || now.y!=0) {
		int minLim = center.x-d, maxLim = center.x+d;
		//向左一步 
		a[now.x][--now.y] = value++;		
		//向上
		for(int i=now.x-1; i>=minLim; i--) {
			a[i][now.y] = value++;
		} 
		now.x = minLim;
		//向右
		for(int i=now.y+1; i<=maxLim; i++) {
			a[now.x][i] = value++;
		} 
		now.y = maxLim;
		//向下
		for(int i=now.x+1; i<=maxLim; i++) {
			a[i][now.y] = value++;
		} 
		now.x = maxLim;
		//向左
		for(int i=now.y-1; i>=minLim; i--) {
			a[now.x][i] = value++;
		} 
		now.y = minLim;
		d++;
	}
	//输出目标坐标的值
	cout << a[center.x-y][center.y+x] << endl; 
	for(int i=0; i<N; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
} 
