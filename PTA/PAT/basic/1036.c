#include<stdio.h>

int main()
{
	int N;
	char C;
	
	scanf("%d %c",&N,&C);
	int row;
	if(N%2 == 0)
		row = N/2;
	else 
		row = (N+1)/2;
//	printf("row=%d\n",row);
	for(int i=0; i<N; i++)
		printf("%c",C);
	printf("\n");
	for(int i=0; i<row-2; i++) {
//		for(int j=0; j<N; j++)
//			printf(" ");
		printf("%c",C);
		for(int j=0; j<N-2; j++)
			printf(" ");
		printf("%c\n",C);
	}
//	for(int i=0; i<N; i++)
//		printf(" ");
//	printf("\n");
	for(int i=0; i<N; i++)
		printf("%c",C);
	printf("\n");

	return 0;
}
