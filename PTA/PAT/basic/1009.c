#include<stdio.h>
#include<string.h>

int main()
{
	char s[81];
	int len;
	int wordNum = 1;

	fgets(s,81,stdin);
	len = strlen(s)-1;
	for(int i=0; i<len; i++) {
		if(s[i] == ' ')
			wordNum++;
	}	
	char t[81];
	int p = len-1;
	int q = p;
	int cnt = wordNum;
	for(int i=0; i<cnt; i++) {
		int j = 0;
		while(cnt > 0) {
			while(s[q-1]!=' ' && q>0)
				q--;
			int t_p = q;
			for(; t_p<=p; j++,t_p++)
				t[j] = s[t_p];
			t[j] = ' ';
			j++;
			p = q-2;
			q = p;
			cnt--;
		}	
	}
	for(int i=0; i<len; i++)
		printf("%c",t[i]);
	return 0;
}
