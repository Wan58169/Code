//问题描述
//抗日战争时期，冀中平原的地道战曾发挥重要作用。
//
//地道的多个站点间有通道连接，形成了庞大的网络。但也有隐患，当敌人发现了某个站点后，其它站点间可能因此会失去联系。
//
//我们来定义一个危险系数DF(x,y)：
//
//对于两个站点x和y (x != y), 如果能找到一个站点z，当z被敌人破坏后，x和y不连通，那么我们称z为关于x,y的关键点。
//相应的，对于任意一对站点x和y，危险系数DF(x,y)就表示为这两点之间的关键点个数。
//
//本题的任务是：已知网络结构，求两站点之间的危险系数。
//
//输入格式
//输入数据第一行包含2个整数n(2 <= n <= 1000), m(0 <= m <= 2000),分别代表站点数，通道数；
//
//接下来m行，每行两个整数 u,v (1 <= u, v <= n; u != v)代表一条通道；
//
//最后1行，两个数u,v，代表询问两点之间的危险系数DF(u, v)。
//
//输出格式
//一个整数，如果询问的两点不连通则输出-1.
//样例输入
//7 6
//1 3
//2 3
//3 4
//3 5
//4 5
//5 6
//1 6
//样例输出
//2
#include<iostream>
#include<vector>
using namespace std;

int N,M;								//N站点数,M通道数	 
int map[1001][1001];					//邻接矩阵
vector<int> v;							//记录访问过的点 
vector<vector<int> > path(100);			//记录路径
 
void dfs(int x,int y,int vis[],int pNum)
{
	if(x == y) {
		v.push_back(y);
		return;
	}
	if(vis[x] == 0) {
		vis[x] = 1;		//访问第x号点 
		v.push_back(x);
	}
	for(int i=1; i<=pNum; i++) {
		if(vis[i]==0 && map[x][i]!=0) {		//没有被访问过而且能到达 
			dfs(i,y,vis,pNum);
			vis[i] = 0;						//回溯!!! 
		}
	}
	//四面楚歌的情况下,-1是此路不通的信号 
	v.push_back(-1);
}
int main()
{
	freopen("12.txt","r",stdin);
	cin >> N >> M;
	//初始化邻接矩阵 
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			map[i][j] = 0;
		}
	}
	//读入边 
	for(int i=0; i<M; i++) {
		int s,e;				//s起点,e终点 
		cin >> s >> e;
		map[s][e] = 1;
		map[e][s] = 1;
	}
	int x,y;					//DF(x,y)
	cin >> x >> y;
	int vis[N+1] = {0};			//假设都没有访问过 
	dfs(x,y,vis,N); 
	//处理路径
	vector<int>::iterator it,it2;
	int k=0;					//第一条路径,path向量的下标 
	vector<int> vt;				//堆栈,暂存处理完的路径 
	for(it=v.begin(); it!=v.end(); it++) {
		if(*it != -1) {			//还没有碰到死胡同 
			vt.push_back(*it);
		} else {				//处理 
			for(it2=vt.begin(); it2!=vt.end(); it2++) {
//				cout << *it2 << " ";
				path[k].push_back(*it2);
			}
			k++;
			//栈顶是终点 
			if(vt.back() == y) {
				vt.pop_back();
			}
			vt.pop_back();
		}
	}
	int df[N+1] = {0}; 					//记录每个点出现的次数 
	int wayNum = 0;						//记录通向终点的条数 
	//遍历二维vector 
	for(int i=0; i<k; i++) {
		if(*(path[i].end()-1) == y) {	//这条路是通向终点的 
			wayNum++;
			for(it=path[i].begin(); it!=path[i].end(); it++) {
				cout << *it << " ";
				if(*it!=x && *it!=y) {
					df[*it]++;
				}
			}
			cout << " " << endl;
		}
	}
	int cnt = 0;						//割点数 
	for(int i=1; i<=N; i++) {
		if(df[i] == wayNum) {			
			cnt++;						//统计每条通向终点的路径都出现的点 
		}
	}
	cout << cnt << endl;
	return 0;
}
