//标题：全球变暖
//
//你有一张某海域NxN像素的照片，”.”表示海洋、”#”表示陆地，如下所示：
//
//.......
//.##....
//.##....
//....##.
//..####.
//...###.
//.......
//
//其中”上下左右”四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。
//
//由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。
//
//例如上图中的海域未来会变成如下样子：
//
//.......
//.......
//.......
//.......
//....#..
//.......
//.......
//
//请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。
//
//【输入格式】
//第一行包含一个整数N。  (1 <= N <= 1000)
//以下N行N列代表一张海域照片。
//
//照片保证第1行、第1列、第N行、第N列的像素都是海洋。
//
//【输出格式】
//一个整数表示答案。

//【输入样例】
//7
//.......
//.##....
//.##....
//....##.
//..####.
//...###.
//.......
//
//【输出样例】
//1
#include<iostream>
using namespace std;

const int pixelNum = 100;		//地图的预计尺寸
//自定义地图类型
typedef struct {
	char c;
	int isVisited;
} MAP;

MAP mapA[pixelNum][pixelNum];
MAP mapB[pixelNum][pixelNum];

void dfs(MAP map[][pixelNum],int x,int y,int n,int groupId)
{
	//越界
	if(x<0 || y<0 || x>n || y>n)
		return;
	//如果是海洋或者已经被访问过 
	if(map[x][y].c=='.' || map[x][y].c=='#'&&map[x][y].isVisited!=0)
		return; 
	map[x][y].isVisited = groupId;
	//上下左右泛红 
	if(map[x-1][y].c=='#' && map[x-1][y].isVisited==0) {
		dfs(map,x-1,y,n,groupId);
	}
	if(map[x+1][y].c=='#' && map[x+1][y].isVisited==0) {
		dfs(map,x+1,y,n,groupId);
	}
	if(map[x][y-1].c=='#' && map[x][y-1].isVisited==0) {
		dfs(map,x,y-1,n,groupId);
	}
	if(map[x][y+1].c=='#' && map[x][y+1].isVisited==0) {
		dfs(map,x,y+1,n,groupId);
	}
}

int main()
{
	freopen("09.txt","r",stdin);
	int N;								//正整数N,地图尺寸 
	int groupANum,groupBNum;			//地图A,B的岛数 
	
	cin >> N;
	//初始化地图A
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			mapA[i][j].isVisited = 0;
			mapB[i][j].isVisited = 0;
		}
	}
	//读入地图A
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> mapA[i][j].c;
			mapB[i][j].c = mapA[i][j].c;
		}
	} 
	//处理,生成效果图B 
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			//如果该点是陆地 
			if(mapA[i][j].c == '#') {
				//判断上下左右是否是海洋 
				if(mapA[i-1][j].c=='.' || mapA[i+1][j].c=='.' || mapA[i][j-1].c=='.' || mapA[i][j+1].c=='.') {
					mapB[i][j].c = '.';
				}
			}
		}
	}
	//打印地图A
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << mapA[i][j].c;
		}
		cout << " " << endl;
	}
	//计算地图A的岛数
	groupANum = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(mapA[i][j].c=='#' && mapA[i][j].isVisited==0) {
				dfs(mapA,i,j,N,groupANum);
				groupANum++;
			}
		}
	}
	groupANum--;
	cout << groupANum << endl;
	cout << "----------------" << endl;
	//打印效果图B
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << mapB[i][j].c;
		}
		cout << " " << endl;
	}
	//计算效果图B的岛数
	groupBNum = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(mapB[i][j].c=='#' && mapB[i][j].isVisited==0) {
				dfs(mapB,i,j,N,groupBNum);
				groupBNum++;
			}
		}
	}
	groupBNum--;
	cout << groupBNum << endl;
	cout << "----------------" << endl;
	cout << groupANum-groupBNum << endl;
	return 0;
}
