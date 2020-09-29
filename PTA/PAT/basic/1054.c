#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

float sum = 0;
int cnt = 0;

int judge(char *buf,int bufLen)
{
	for(int j=0; j<bufLen; j++) {
		if(buf[j] == '.') {
			if(buf[j+3] != '\0') {
				return -1;
			}
		} else if(buf[j]=='-' && j>0) {
			return -1;
		} else if(isalpha(buf[j])) {
			return -1;
		}		
	}
	return 1;
}

void legal(char *buf,int bufLen)
{
	int i;
	int isFloat = 0;
	int isInt = 0;

	for(i=0; i<bufLen; i++) {
		if(buf[i] == '.') {
			isFloat = 1;
			break;
		}
	}
	if(i == bufLen) {
		isInt = 1;
	}
	if(isInt == 1) {
		int sum_int = 0;
		sum_int = atoi(buf);
		if(sum_int>=-1000 && sum_int<=1000) {
			sum += sum_int;
			cnt++;
		} else {
			printf("ERROR: %s is not a legal number\n",buf);
		}
	} else if(isFloat == 1) {
		float sum_float = 0;
		sum_float = atof(buf);
		if(sum_float-1000<1e-10 && sum_float+1000>1e-10) {
			sum += sum_float;
			cnt++;
		} else {
			printf("ERROR: %s is not a legal number\n",buf);
		}
	}
}

int main()
{
	freopen("1054.txt","r",stdin);
	int N;

	scanf("%d",&N);	
	char ret[100][256];
	for(int i=0; i<N; i++) {
		scanf("%s",ret[i]);
	}
	for(int i=0; i<N; i++) {
		int bufLen = strlen(ret[i]);
		int flag = judge(ret[i],bufLen);
		if(flag == 1) {
			legal(ret[i],bufLen);
		} else if(flag == -1) {
			printf("ERROR: %s is not a legal number\n",ret[i]);
		} 
	}
	if(cnt > 1)
		printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
	else if(cnt == 0)
		printf("The average of 0 numbers is Undefined\n");
 	else if(cnt == 1)
		printf("The average of 1 number is %.2lf\n",sum/cnt);

	return 0;
}
