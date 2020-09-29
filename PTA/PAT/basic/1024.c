#include<stdio.h>
#include<math.h>

#define BUF_SIZE 10000

double myPower(int exp)
{
	double ret = 1;

	for(int i=0; i<exp; i++)
		ret /= 10;

	return ret;
}

int myMul(int len)
{
	int ret = 1;

	for(int i=0; i<len-1; i++)
		ret *= 10;

	return ret;
}

int myCnt(char *buf,int index)
{
	int cnt = 0;
	int len;

	for(int i=index; buf[i]!='\0'; i++)
		len++;
	for(int i=index; buf[i]!='\0'; i++,len--)
		cnt += (buf[i]-'0')*myMul(len);

	return cnt;
}

int main()
{
	char symbol1;
	int integer;
	double decimal = 0;
	double sum;
	char symbol2;
	char buf[BUF_SIZE];

	scanf("%s",buf);
	symbol1 = buf[0];
	integer = buf[1] - '0';
	int i;
	for(i=3; buf[i]!='E'; i++) 
		decimal += myPower(i-2)*(buf[i]-'0');
	sum = integer+decimal;
	symbol2 = buf[++i];
	int cnt = myCnt(buf,++i);
	if(symbol2 == '+') {
		for(int j=0; j<cnt; j++)
			sum *= 10;
	} else {
		for(int j=0; j<cnt; j++)
			sum /= 10;
	}
	if(symbol1 == '-') 
		printf("-");
	printf("%lf",sum);

	return 0;
}
