#include<stdio.h>

//win返回1 lose返回0 notEnough返回2 gameOver返回-1
int f(int n1,int b,int t,int n2,int *T)
{
	int cmpFlag = 0;	//0是< 1是> 

	if(n2 < n1) {
		cmpFlag = 0;
	} else if (n2 > n1) {
		cmpFlag = 1;
	}
	if(*T <= 0) { //gameOver
		return -1;
	} else if (t > *T) { //notEnough
		return 2;
	} else if (cmpFlag == b){ //win
		*T += t;
		return 1;
	} else { //lose
		*T -= t;
		return 0;
	}
}

int main()
{
	freopen("1071.txt","r",stdin);
	int T,K;
	int n1,b,t,n2;
	int i;
	int retFlag;

	scanf("%d %d",&T,&K);
	for(i=0; i<K; i++) {
		scanf("%d %d %d %d",&n1,&b,&t,&n2);
		retFlag = f(n1,b,t,n2,&T);
		if(retFlag == 1) {
			printf("Win %d!  Total = %d.\n",t,T);
		} else if (retFlag == 0) {
			printf("Lose %d.  Total = %d.\n",t,T);
		} else if (retFlag == 2) {
			printf("Not enough tokens.  Total = %d.\n",T);
		} else if (retFlag == -1) {
			printf("Game Over.\n");
			break;
		}
	}

	return 0;
}
