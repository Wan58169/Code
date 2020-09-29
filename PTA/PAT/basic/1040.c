#include<stdio.h>
#include<string.h>

#define BUF_SIZE 100001
#define I 1000000007

int main()
{
	char buf[BUF_SIZE];
	int numT = 0;
	int numAT = 0;
	int numPAT = 0;
	
	scanf("%s",buf);
	for(int i=strlen(buf)-1; i>=0; i--) {
		if(buf[i] == 'T')
			numT++;
		else if(buf[i] == 'A')
			numAT = (numT+numAT)%I;
		else if(buf[i] == 'P')
			numPAT = (numAT+numPAT)%I;
	}
	printf("%d",numPAT);
	
	return 0;
}
