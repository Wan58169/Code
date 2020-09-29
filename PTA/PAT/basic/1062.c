#include<stdio.h>

int main()
{
	int N1,N2,M1,M2,K;

	scanf("%d/%d %d/%d %d",&N1,&M1,&N2,&M2,&K);
	//从小到大排列这个分数
	if(N1*M2 > N2*M1) {
		int	tmpN = N2;
		int	tmpM = M2;
		N2 = N1;
		M2 = M1;
		N1 = tmpN;
		M1 = tmpM;
	}
	//计算X的最小值
	int min,max;
	min = (int)1.0*N1*K/M1 + 1; 
	max = (int)1.0*N2*K/M2;
	for(int i=min; i<=max; i++) {
		if(K%i != 0) {
			printf("%d/%d",i,K);
			if(i < max) {
				printf(" ");
			}
		}
	}
	return 0;
}
