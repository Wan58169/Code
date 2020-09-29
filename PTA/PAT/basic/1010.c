#include<stdio.h>

#define MAX 100

int main()
{
	int src[MAX];
	int ret[MAX];
	int c;
	int i = 0;
	
	scanf("%s",src);

	for(int j=0; src[j]!=2000; j++) 
		printf("%c",src[j]);

	return 0;
}
