#include<stdio.h>
#include<string.h>

void f()
{
	int alph[128] = {0};
	char c = 48;

	/* 读取字符 */
	while(c != 10) {
		scanf("%c",&c);
		alph[c]++;
	}
	/* 选择频率最高的 */
	int cnt[26] = {0};
	for(int i=65; i<=90; i++) 
		cnt[i-65] += alph[i];	
	for(int i=97; i<=122; i++) 
		cnt[i-97] += alph[i];
	int maxIndex,maxCnt = 0;
	for(int i=0; i<26; i++) {
		if(cnt[i] > maxCnt) {
			maxCnt = cnt[i];
			maxIndex = i;
		}
	}
	printf("%c %d",maxIndex+97,maxCnt);
}

int main()
{
	freopen("1042.txt","r",stdin);
	
	f();

	return 0;
}
