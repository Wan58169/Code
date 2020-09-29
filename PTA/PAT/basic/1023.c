#include<stdio.h>
#include<stdlib.h>

void f(int *buf,int cnt,int len)
{
	int *ret = malloc(sizeof(int)*cnt);

	for(int j=1; j<len; j++) {
		if(buf[j] != 0) {
			ret[0] = j;
			buf[j]--;
			break;
		}
	}
	for(int i=1; i<cnt; i++) {
		for(int j=0; j<len; j++) {
			if(buf[j] != 0) {
				ret[i] = j;
				buf[j]--;
				break;
			}
		}
	}
	for(int i=0; i<cnt; i++)
		printf("%d",ret[i]);
	printf("\n");
}

int main()
{
	freopen("1023.txt","r",stdin);
	int buf[10];
	int cnt = 0;

	for(int i=0; i<sizeof(buf)/sizeof(buf[0]); i++) {
		scanf("%d",&buf[i]);
		cnt += buf[i];
	}
	f(buf,cnt,sizeof(buf)/sizeof(buf[0]));

	return 0;
}
