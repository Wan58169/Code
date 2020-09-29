//11-散列1 电话聊天狂人（25 分）
//给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。
//
//输入格式:
//
//输入首先给出正整数N<=100000为通话记录条数。
//随后N行，每行给出一条通话记录。简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。
//
//输出格式:
//
//在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。
//
//输入样例:
//
//4
//13005711862 13588625832
//13505711862 13088625832
//13588625832 18087925832
//15005713862 13588625832
//输出样例:
//
//13588625832 3
#include<iostream>
#include<map>
using namespace std;

map<string,int> m;

int main()
{
	freopen("11-1.txt","r",stdin);
	int N;
	map<string,int>::iterator it;
	
	cin >> N;
	cin.get();
	while(N--) {
		string number1,number2;
		cin >> number1 >> number2;
		//处理number1 
		it = m.find(number1);
		if(it == m.end()) {
			m.insert(pair<string,int>(number1,1));
		} else {
			(*it).second++;
		}
		//处理number2
		it = m.find(number2);
		if(it == m.end()) {
			m.insert(pair<string,int>(number2,1));
		} else {
			(*it).second++;
		} 
	}
	//找最大
	int max = 0;
	for(it=m.begin(); it!=m.end(); it++) {
		if(max <= (*it).second) {
			max = (*it).second;
		}
	}
	//打印最小电话号码 
	int cnt = 0;
	string minNumber;
	//找到第一个聊天狂人 
	for(it=m.begin(); it!=m.end(); it++) {
		if((*it).second == max) {
			minNumber = (*it).first;
			cnt++;
			break;
		}
	}
	it++;
	//找出最小电话号码 和 数一数聊天狂人的个数 
	for(; it!=m.end(); it++) {
		if((*it).second == max) {
			if((*it).first < minNumber) {
				minNumber = (*it).first;
			}
			cnt++;
		}
	}
	if(cnt == 1) 
		cout << minNumber << " " << max << endl;
	else
 		cout << minNumber << " " << max << " " << cnt << endl;
	return 0;
}








