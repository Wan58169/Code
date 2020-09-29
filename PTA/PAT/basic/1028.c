#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char name[7];
	int time;
}Com;

int main()
{
	freopen("data.txt","r",stdin);

	int n;

	scanf("%d",&n);
	
//	char buf[30];
//	char tmp[10];
	Com max,min;
//	fgets(buf,30,stdin);
	max.time = 0;
	min.time = 111111111;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		/*
		fgets(buf,30,stdin);
		buf[strlen(buf)-1] = '\0';
		int p = 0;
		int q = 0;
		char name[10];
		while(buf[p] != ' ') {
			name[p] = buf[p];
			p++;
		}
		p++;
		name[p] = '\0';
		while(buf[p] != '\0') {
			if(buf[p] != '/') {
				tmp[q] = buf[p];
				q++;
			}
			p++;
		}
		*/
		char name[7];
		int year,month,day;
		scanf("%s %d/%d/%d",name,&year,&month,&day);
		int time;
		time = year*10000+month*100+day;
		printf("%d\n",time);
		if(time<18140906 || time>20140906)
			continue;
		//挑出最大的
		if(max.time < time) {
			max.time = time;
			strcpy(max.name,name);
		}
		//挑出最小的
		if(min.time > time) {
			min.time = time;
			strcpy(min.name,name);
		}
		cnt++;
		time = 0;
//		for(int j=0; j<10; j++)
//			name[j] = '\0';
	}
	printf("%d %s %s\n",cnt,min.name,max.name);

	return 0;
}

