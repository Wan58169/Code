#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int main()
{
	freopen("1069.txt","r",stdin);
	int M,N,S;

	//M总人数
	//N抽奖间隔
	//S中奖人的编号
	cin >> M >> N >> S;
	map<string,int> mapp;
	string buf;
	int flag = 0;	//是否有人中奖
	for(int i=1; i<=M; i++) {
		cin >> buf;
		if(i == S) {	//中奖
			if(mapp[buf] == 1) {	//之前中奖过
				S++;
			} else if(mapp[buf] == 0) {	//没中奖过
				cout << buf << endl;
				mapp[buf] = 1;
				flag++;
				S += N;
			}
		}
	}
	if(flag == 0) {
		cout << "Keep going..." << endl;
	}

	return 0;
}
