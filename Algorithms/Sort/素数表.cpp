#include<stdio.h>

void initA(int a[],int N)
{
	int i;

	for(i=0; i<N; i++) {
		a[i] = 1;
	}
}
//生成素数表	 
void generateTable(int a[],int N)
{	
	int i,j;
	//先用2筛选
	for(i=2; 2*i<=N; i++) {
		a[2*i] = 0;
	}
	//用3筛选
	for(i=3; i*i<=N; i++) {
		if(a[i] == 1) {
			for(j=i*i; j<=N; j+=i) {
				a[j] = 0;
			}
		}
	}
}

void printA(int a[],int N)
{
	int i;
	int cnt =0;

	for(i=2; i<=N; i++) {
		if(a[i]==1) {
			printf("%d ",i);
			cnt++;
		}
	}
	printf("\n%d\n",cnt);
}

int main()
{
	int N;

	scanf("%d",&N);
	N++;
	int a[N];
	initA(a,N);
	generateTable(a,N);
	printA(a,N);

	return 0;
}

