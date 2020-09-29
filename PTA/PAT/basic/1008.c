#include<stdio.h>

int main()
{
	int n,m;
	int cnt = 0;

	scanf("%d %d",&n,&m);
	int x[n];

	for(int i=0; i<n; i++)
		scanf("%d",&x[i]);
	
	for(int i=0; i<m; i++) {
		int tmp = x[n-1];
		for(int j=n-1; j>0; j--)
			x[j] = x[j-1];
		x[0] = tmp;
	}

	for(int i=0; i<n; i++)
		printf("%d ",x[i]);
	printf("\n");	

	return 0;
}
