//问题描述
//　　如下面第一个图的九宫格中，放着 1~8 的数字卡片，还有一个格子空着。与空格子相邻的格子中的卡片可以移动到空格中。
//	  经过若干次移动，可以形成第二个图所示的局面。
//		1 2 3       1 2 3
// 		4 5 6       0 4 6
//		7 8 0       7 5 8
//　　我们把第一个图的局面记为：12345678.
//　　把第二个图的局面记为：123.46758
//　　显然是按从上到下，从左到右的顺序记录数字，空格记为句点。
//　　本题目的任务是已知九宫的初态和终态，求最少经过多少步的移动可以到达。如果无论多少步都无法到达，则输出-1。
//输入格式
//　　输入第一行包含九宫的初态，第二行包含九宫的终态。
//输出格式
//　　输出最少的步数，如果不存在方案，则输出-1。
//样例输入
//12345678.
//123.46758
//样例输出
//3
//样例输入
//13524678.
//46758123.
//样例输出
//22
#include<iostream>
#include<set>
#include<queue>
using namespace std;

struct status {
	string des;			//状态描述 
	int pos;			//空格位置 
	int step;			//到达该状态的步数 
	
	status(string s) {
		step = 0;
		des = s;
		for(int i=0; i<des.length(); i++) {
			if(des[i] == '.') {
				des[i] = '0';
				pos = i;
				break;
			}
		}
	}
	status(const status & t) {
		des = t.des;
		pos = t.pos;
		step = t.step;
	}
	bool operator<(const status & s) const {			//符号重载<,用于set 
		int ret = des.compare(s.des);
		if(ret >= 0)
			return false;
		else if(ret < 0)
			return true;
	}
	status operator=(const status & s) {				//符号重载=,用于结构体赋值 
		des = s.des;
		pos = s.pos;
		step = s.step;
		return s;
	}
	bool operator==(const status &s) const {			//符号重载==,用于结构体比较 
		if(des == s.des)
			return true;
		else 
		 	return false;
	}
};
set<status> s;			//集合s用于判重 
queue<status> q;        //队列q用于bfs 

status move(int dir,const status & t)
{
	status ret(t);
	
	switch(dir) {
		case 1 : {		//上 
			if(t.pos>2 && t.pos<=8) {
				ret.des[t.pos] = t.des[t.pos-3],ret.des[t.pos-3] = '0';
				ret.step++,ret.pos = t.pos-3; 
			}
			break;
		}
		case 2 : {		//下 
			if(t.pos<6 && t.pos>=0) {
				ret.des[t.pos] = t.des[t.pos+3],ret.des[t.pos+3] = '0';
				ret.step++,ret.pos = t.pos+3; 	
			}
			break;
		}
		case 3 : {		//左 
			if(t.pos!=0 && t.pos!=3 && t.pos!=6) {
				ret.des[t.pos] = t.des[t.pos-1],ret.des[t.pos-1] = '0';
				ret.step++,ret.pos = t.pos-1; 
			}
			break;
		}
		case 4 : {		//右 
			if(t.pos!=2 && t.pos!=5 && t.pos!=8) {
				ret.des[t.pos] = t.des[t.pos+1],ret.des[t.pos+1] = '0';
				ret.step++,ret.pos = t.pos+1; 
			}
			break;
		}
	}	
	if(s.find(ret) == s.end()) 
		s.insert(ret),q.push(ret);
	return ret;
}
int main()
{
	freopen("19.txt","r",stdin);
	//读入起始和终止状态 
	string s1,s2;
	cin >> s1 >> s2;
	//状态结点 
	status start(s1),end(s2);
	status now(""),next("");
	//bfs
	s.insert(start),q.push(start);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		//上下左右依次试探 
		for(int i=1; i<=4; i++) {
			next = move(i,now);
			if(next == end) {				//如果是终止状态 
				cout << next.step << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
