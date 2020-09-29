#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("1061.txt","r",stdin);
	//N人数 M题数
	int N,M;	

	scanf("%d %d",&N,&M);
	int score[M],ans[M];
	//读入每题分值
	for(int i=0; i<M; i++) {
		scanf("%d",&score[i]);
	}
	//读入每题正确选项
	for(int i=0; i<M; i++) {
		scanf("%d",&ans[i]);
	}
	//判断得分
	for(int i=0; i<N; i++) {
		int tmp;
		int sum = 0;
		for(int j=0; j<M; j++) {
			scanf("%d",&tmp);
			if(tmp == ans[j]) {
			 	sum += score[j];
			}
		}
		printf("%d\n",sum);
	}	
	return 0;
}
