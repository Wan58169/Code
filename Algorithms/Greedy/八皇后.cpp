#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100

int x[MAX] = {0};

void dfs(int k,int n)
{
	int i,j;
	
	if(k > n) {	//k行都已放好 
		for(int i=1; i<=n; i++)
			printf("%d ",x[i]);
		printf("\n");
		return;
	}

	for(i=1; i<=n; i++) {	//定位列 
		for(j=1; j<k; j++) {	//定位前k-1行 
			//剪枝条件 
			if(abs(k-j)==abs(x[j]-i) || x[j]==i) break;
		}
		if(j == k) {
			x[k] = i;
			dfs(k+1,n);
		}
	}
}

int main()
{
	int n;
	
	scanf("%d",&n);
	
	dfs(1,n);
	
	return 0;
}
