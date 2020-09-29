//02-线性结构3 Reversing Linked List（25 分）
//Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. 
//For example, 
//given L being 1→2→3→4→5→6,
// if K=3, then you must output 3→2→1→6→5→4; 
//if K=4, you must output 4→3→2→1→5→6.
//
//Input Specification:
//
//Each input file contains one test case. 
//For each case, the first line contains the address of the first node, 
//a positive N(N<=100000)which is the total number of nodes, 
//and a positive K(K<=N)which is the length of the sublist to be reversed.
//The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
//
//Then N lines follow, each describes a node in the format:
//
//Address Data Next
//
//where Address is the position of the node, Data is an integer, and Next is the position of the next node.
//
//Output Specification:
//
//For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
//
//Sample Input:
//
//00100 6 4
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//Sample Output:
//
//00000 4 33218
//33218 3 12309
//12309 2 00100
//00100 1 99999
//99999 5 68237
//68237 6 -1
#include<iostream>
#include<vector>
using namespace std;

//定义结点 
typedef struct {
	string add;
	int data;
	string next;
}node;

vector<node> v,tv;
const string END = "-1";

int main()
{
	freopen("02-3.txt","r",stdin);
	string begin_add;
	int N,K;
	
	cin >> begin_add >> N >> K;
	//读入链表信息 
	node tn;
	for(int i=0; i<N; i++) {
		cin >> tn.add >> tn.data >> tn.next;
		tv.push_back(tn);
	}
	//整理排序链表
	vector<node>::iterator it;
	//找出首结点 
	for(it=tv.begin(); it!=tv.end(); it++) {
		if((*it).add == begin_add) {
			v.push_back((*it));	
			break;
		}
	} 
	//顺序连接 
	while(1) {
		string tadd = v.back().next;
		if(tadd == END) break;						//尾结点直接退出 
		for(it=tv.begin(); it!=tv.end(); it++) {	//根据上一个结点的next寻找下一个 
			if((*it).add == tadd) 
				v.push_back((*it));
		}
	}
	//每K个逆序 
	int idx = 0;
	tv.clear();
	for(idx=K; idx<=N; idx+=K) {
		for(int i=idx-1; i>=idx-K; i--) {
			tv.push_back(v[i]);
		}
	}
	idx -= K;
	for(int i=idx; i<N; i++) {
		tv.push_back(v[i]);
	}
	//将tv导入v中 
	v.assign(tv.begin(),tv.end());
	for(it=v.begin(); it!=v.end(); it++) {
		if(it != v.end()-1)
			(*it).next = (*(it+1)).add;
		else 
			(*it).next = END;
		cout << (*it).add << " " << (*it).data << " " << (*it).next << endl;
	}
	return 0;
}
