#include<stdio.h>
#include<string.h>

#define BUFLEN 10001

void screenBuf(char *a,char *buf,int bufLen)
{
	int i,j;

	for(i=0,j=0; i<bufLen; i++) {
		if(buf[i]=='P' || buf[i]=='A' || buf[i]=='T'
			|| buf[i]=='e' || buf[i]=='s' || buf[i]=='t') {
			a[j] = buf[i];
			j++;
		}
	}
	a[j] = '\0';
}

void counter(char *a,int aLen,int cnt[])
{
	int i;

	for(i=0; i<aLen; i++) {
		if(a[i] == 'P')
			cnt[0]++;
		else if(a[i] == 'A')
			cnt[1]++;
		else if(a[i] == 'T')
			cnt[2]++;
		else if(a[i] == 'e')
			cnt[3]++;
		else if(a[i] == 's')
			cnt[4]++;
		else if(a[i] == 't')
			cnt[5]++;
	}
}

int isAllZero(int cnt[])
{
	int zero = 0;

	for(int i=0; i<6; i++) {
		if(cnt[i] == 0)
			zero++;
	}
	if(zero == 6)
		return 1;
	else 
		return 0;
}

void f(char *ch,int cnt[])
{
	int i,j;
	int min = 1;

	while(!isAllZero(cnt)) {
		for(i=0; i<6; i++) {
			if(min>cnt[i] && cnt[i]>0)
				min = cnt[i];
		}
		for(j=0; j<min; j++) {
			for(i=0; i<6; i++) {
				if(cnt[i] != 0) {
					printf("%c",ch[i]);
					cnt[i] -= min;
				}
			}
		}
	}
}

int main()
{
	freopen("1043.txt","r",stdin);
	char buf[BUFLEN];
	
	fgets(buf,BUFLEN,stdin);
	buf[strlen(buf)-1] = '\0';
	int bufLen = strlen(buf);
	char a[bufLen];
	/* 筛选 */
	screenBuf(a,buf,bufLen);
	int aLen = strlen(a);
	int cnt[6] = {0};
	/* 统计各字符出现次数 */
	counter(a,aLen,cnt);
	char ch[] = {'P','A','T','e','s','t'};
	/* 按照规则写单词 */
	f(ch,cnt);

	return 0;
}
