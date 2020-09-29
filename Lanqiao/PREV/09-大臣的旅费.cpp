//很久以前，T王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。
//
//为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接
//到达。同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。
//
//J是T国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。
//他有一个钱袋，用于存放往来城市间的路费。
//
//聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，
//在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。
//
//J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？
//
//输入格式
//输入的第一行包含一个整数n，表示包括首都在内的T王国的城市数
//
//城市从1开始依次编号，1号城市为首都。
//
//接下来n-1行，描述T国的高速路（T国的高速路一定是n-1条）
//
//每行三个整数Pi, Qi, Di，表示城市Pi和城市Qi之间有一条高速路，长度为Di千米。
//
//输出格式
//输出一个整数，表示大臣J最多花费的路费是多少。
//
//样例输入1
//5
//1 2 2
//1 3 1
//2 4 5
//2 5 4
//样例输出1
//135
//输出格式
//大臣J从城市4到城市5要花费135的路费。
#include<iostream>
#include<vector>
using namespace std;

int N;				//正整数N,几个城市 
int map[101][101];	//邻接矩阵
vector<int> v;

//递归计算旅费 
int cal_money(int k)
{
	if(k == 1) {
		return 11;
	}
	return cal_money(k-1)+10+k;
}
//从树的一点出发,计算到达各个最远方的距离 
void dfs(int s,int n,int vis[],int len) 
{
	if(vis[s] == 0) {			//该点没被访问过 
		vis[s] = 1;
	}
	for(int i=1; i<=n; i++) {
		if(map[s][i]!=0 && vis[i]==0) {		//确保有边并且没有访问过 
			len += map[s][i];
			dfs(i,n,vis,len);
			len -= map[s][i];
		}
	}
	v.push_back(len);
}
int main()
{
	freopen("09.txt","r",stdin);
	cin >> N;
	
	//初始化map
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			map[i][j] = 0;		//假设都不通 
		}
	}
	//生成邻接矩阵 
	for(int i=0; i<N-1; i++) {
		int s,e,w;				//s代表起点,e代表终点,w代表距离 
		cin >> s >> e >> w;
		map[s][e] = w;
		map[e][s] = w;
	} 	
	//核心dfs 
	for(int i=1; i<=N; i++) {
		int vis[N+1] = {0};			//假设都没被访问过 
		dfs(i,N,vis,0);
	}
	//找最大 
	vector<int>::iterator it;
	int max = 0;					//最远距离 
	for(it=v.begin(); it!=v.end(); it++) {
		if(max < *it) {
			max = *it;
		}
	}
	cout << cal_money(max) << endl;
	return 0;
} 
