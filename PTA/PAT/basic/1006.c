#include<stdio.h>
#include<string.h>

int main()
{
	char buf[3] = "";
	char* p;
	int len = 0;

	scanf("%s",buf);
	p = &buf[0];
	len = strlen(buf);
	
	if(len == 3) {
		for(int i=0; i<*p-'0'; i++)
			printf("B");
		p++;
		len--;
	}
	if(len == 2) {
		for(int i=0; i<*p-'0'; i++)
			printf("S");
		p++;
		len--;
	}
	for(int i=1; i<=*p-'0'; i++)
		printf("%d",i);
	return 0;
}
