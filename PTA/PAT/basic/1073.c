#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
	int score;
	int optionNumber;
	int rightNumber;
	char *ret;
};
typedef struct Node Record;

void scanIntoRecord(Record r[],int M)
{
	int i,j=0;
	char c;
	for(i=0; i<M; i++,j=0) {
		scanf("%d %d %d",&r[i].score,&r[i].optionNumber,&r[i].rightNumber);
		r[i].ret = malloc(sizeof(char)*(r[i].rightNumber+1));
		while((c=getchar()) != '\n') {
			if(c != ' ') {
				r[i].ret[j++] = c;
			}
		}
	}
}

void initRet(int ret[][5],int M)
{
	int i,j;

	for(i=0; i<M; i++) {
		for(j=0; j<5; j++) {
			ret[i][j] = 0;
		}
	}
}

int isSame(char buf[],char ret[],int k)
{
	int i;

	for(i=0; i<k; i++) {
		if(buf[i] != ret[i]) {
			return 0;
		}
	}
	return 1;
}

int isIn(char buf[],char ret[],int k,int retLen)
{
	int i,j;
	int hasFlag = 0;

	for(i=0; i<k; i++) {
		hasFlag = 0;
		for(j=0; j<retLen; j++) {
			if(buf[i] == ret[j]) {
				hasFlag = 1;
			}
		}
		if(hasFlag == 0) {
			return 0;
		}
	}
	return 1;
}

void cmp(char buf[],char asn[],int bufLen,int asnLen,int ret[][5],int row)
{
	int i;

	for(i=0; i<bufLen; i++) {	//判断"多选的"
		if(!isIn(buf+i,asn,1,asnLen)) {
			ret[row][buf[i]-'a']++;
		} 
	}
	for(i=0; i<asnLen; i++) {	//判断"少选的"
		if(!isIn(asn+i,buf,1,bufLen)) {
			ret[row][asn[i]-'a']++;
		}
	}
}

void calculateScore(Record r[],int M,int ret[][5])
{
	int i,j,k;
	float score = 0;
	int optionNumber = 0;
	char c;

	for(i=0,j=0; i<M; i++,j=0) {
			while((c=getchar()) != '(')
				;
			scanf("%d",&optionNumber);
			char buf[5];
			while((c=getchar()) != ')') {
				if(c != ' ') {
					buf[j++] = c;
				}
			}
			buf[j] = '\0';
			int bufLen = j;
			int retLen = r[i].rightNumber;
			if(optionNumber == retLen) {
				if(isSame(buf,r[i].ret,bufLen)) {
					score += r[i].score;	
				} 
				cmp(buf,r[i].ret,bufLen,retLen,ret,i);		
			} else if (optionNumber < retLen) {
				if(isIn(buf,r[i].ret,bufLen,retLen)) {
					score += r[i].score*1.0/2;
				}
				cmp(buf,r[i].ret,bufLen,retLen,ret,i);
			} else if (optionNumber > retLen) {
				cmp(buf,r[i].ret,bufLen,retLen,ret,i);
			}
		}
		printf("%.1lf\n",score);
		score = 0;
}

int findMax(int ret[][5],int row)
{
	int i,j;
	int max = -1;

	for(i=0; i<row; i++) {
		for(j=0; j<5; j++) {
			if(max < ret[i][j]) {
				max = ret[i][j];
			}		
		}
	}
	return max;
}

void printMax(int ret[][5],int row,int max)
{
	int i,j;

	for(i=0; i<row; i++) {
		for(j=0; j<5; j++) {
			if(ret[i][j] == max) {
				printf("%d %d-%c\n",max,i+1,j+'a');
			}
		}
	}
}

int main()
{
	freopen("1073.txt","r",stdin);
	int N,M;
	
	scanf("%d %d",&N,&M);
	Record record[M];
	int ret[M][5];
	int retMax;
	initRet(ret,M);
	scanIntoRecord(record,M);
	for(int i=0; i<N; i++) {
		calculateScore(record,M,ret);
	}
	retMax = findMax(ret,M);
	if(retMax == 0) {
		printf("Too simple\n");
	} else {
		printMax(ret,M,retMax);
	}

	return 0;
}
