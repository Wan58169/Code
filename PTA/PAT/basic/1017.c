#include<stdio.h>
#include<string.h>

int main()
{
	int m = 0;
	int n;
	char buf[1000];
	
	scanf("%s %d",buf,&n);
	if(strlen(buf) == 1) {
		
	} else {
		for(int i=0; i<strlen(buf); i++) {
			if(i>0 && m==0 && buf[i]-'0'<n) 
				printf("0");
			m = m*10+buf[i]-'0';
			if(m/n > 0) {
				printf("%d",m/n);
				m = m%n;
			}
		}
	}
	
	return 0;
}
