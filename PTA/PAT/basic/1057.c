#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define BUF_SIZE 100001

int main()
{
	char buf[BUF_SIZE];
	int bufLen;
	int sum = 0;

	fgets(buf,BUF_SIZE,stdin);
	bufLen = strlen(buf);
	//扫描每个字符
	for(int i=0; i<bufLen; i++) {
		if(isalpha(buf[i])) {
			char t = tolower(buf[i]);
			sum += t-'a'+1;
		}
	}
	//转为二进制
	int cnt1 = 0;
	int cnt0 = 0;
	while(sum != 0) {
		int ret = sum%2;
		if(ret == 1) {
			cnt1++;
		} else {
			cnt0++;
		}
		sum /= 2;
	}
	printf("%d %d",cnt0,cnt1);
	return 0;
}
