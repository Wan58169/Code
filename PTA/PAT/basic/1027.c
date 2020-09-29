#include<stdio.h>

#define S(n) (((n*n-1)*2)+1)

int main()
{
	int N;
	int n;
	int L;
 	char c;

	scanf("%d %c",&N,&c);
	for(n=1; S(n)<=N; n++)
		;
	n--;
	L = 2*n-1;
	int j = L;
	while(j > 1) {
		for(int i=0; i<(L-j)/2; i++)
			printf(" ");
		for(int i=0; i<j; i++)
			printf("%c",c);
		printf("\n");
		j -= 2;
	}
	for(int i=0; i<(L-1)/2; i++)
		printf(" ");
	printf("%c\n",c);
	j += 2;
	while(j <= L) {
		for(int i=0; i<(L-j)/2; i++)
			printf(" ");
		for(int i=0; i<j; i++)
			printf("%c",c);
		printf("\n");
		j += 2;
	}
	printf("%d\n",N-S(n));

	return 0;
}
