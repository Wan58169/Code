#include<stdio.h>

int staffCnt = 0;
int stuffCnt = 0;

int isInStuff(int tmpNumber,int stuff[],int M)
{
	int i;

	for(i=0; i<M; i++) {
		if(tmpNumber == stuff[i]) {
			return 1;
		}
	}
	return 0;
}

void f(int stuff[],int M)
{
	char name[5];
	int number,tmpNumber;
	int i = 0;
	int j = 0;

	scanf("%s %d",name,&number);
	int record[number];
	for(i=0; i<number; i++) {
		scanf("%d",&tmpNumber);
		if(isInStuff(tmpNumber,stuff,M)) {
			record[j++] = tmpNumber;	
		}
	}
	if(j != 0) {
		printf("%s: ",name);
		staffCnt++;
		for(i=0; i<j-1; i++) {
			printf("%d ",record[i]);
			stuffCnt++;
		}
		printf("%d\n",record[i]);
		stuffCnt++;
	}
}

int main()
{
	freopen("1072.txt","r",stdin);
	int N,M;

	scanf("%d %d",&N,&M);
	int stuff[M];
	int i;
	for(i=0; i<M; i++) {
		scanf("%d",&stuff[i]);
	}
	for(i=0; i<N; i++) {
		f(stuff,M);
	}
	printf("%d %d\n",staffCnt,stuffCnt);

	return 0;
}

