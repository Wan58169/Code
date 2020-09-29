//问题描述
//　　儿童节那天有K位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
//　　小明一共有N块巧克力，其中第i块是Hi x Wi的方格组成的长方形。
//
//
//　　为了公平起见，小明需要从这 N 块巧克力中切出K块巧克力分给小朋友们。切出的巧克力需要满足：
//
//
//　　1. 形状是正方形，边长是整数
//　　2. 大小相同
//
//
//　　例如一块6x5的巧克力可以切出6块2x2的巧 克力或者2块3x3的巧克力。
//
//
//　　当然小朋友们都希望得到的巧克力尽可能大，你能帮小Hi计算出最大的边长是多少么？
//输入格式
//　　第一行包含两个整数N和K。(1 <= N, K <= 100000)
//　　以下N行每行包含两个整数Hi和Wi。(1 <= Hi, Wi <= 100000)
//　　输入保证每位小朋友至少能获得一块1x1的巧克力。
//输出格式
//　　输出切出的正方形巧克力最大可能的边长。
//样例输入
//2 10
//6 5
//5 6
//样例输出
//2
#include<iostream>
using namespace std;

//定义长方形 
typedef struct {
	int H;			//高 
	int W;			//宽 
}RECT;

const int MAX = 110000;
int N,K;				//巧克力块数和小朋友人数
int L = 2;				//正方形的起始边长
RECT chocolate[MAX];

int isOk(int length)
{
	int tK = 0;					//能够切成正方形的块数 
	
	for(int i=0; i<N; i++) {
		tK += (chocolate[i].H/length)*(chocolate[i].W/length);
	}
	if(tK < K) return 0;	
	else return 1;
}
int main()
{
	cin >> N >> K;
	//读入巧克力信息 
	for(int i=0; i<N; i++) {
		cin >> chocolate[i].H >> chocolate[i].W;
		//预设正方形边长 
		if(chocolate[i].H < chocolate[i].W) {
			L = chocolate[i].W;
		} else {
			L = chocolate[i].H;
		}
	}
	//二分确定L 
	int left = 1;
	int right = L;
	int maxLen = 1;			//记录最大边长 
	while(left <= right) {
		int mid = (left+right)/2;
		if(isOk(mid)) {
			if(mid > maxLen) maxLen = mid;
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	cout << maxLen << endl;
	return 0;
}
