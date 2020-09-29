#include<stdio.h>
#include<string.h>

void shift(char buf[],int bufLen)
{
	int i,j;

	for(i=bufLen-1,j=20; i>=0; i--,j--) {
		buf[j] = buf[i];
	}
	for(i=0; i<=20-bufLen; i++) {
		buf[i] = 'x';
	}
}

void initBuf(int buf[])
{
	int i;

	for(i=0; i<21; i++) {
		buf[i] = 0;
	}
}

void f(char c[],char n1[],char n2[],int ret[])
{
	int maxCarry;
	int i;
	int carry = 0;
	int overFlag = 0;

	for(i=20; overFlag!=1; i--) {
		maxCarry = c[i]-'0';
		if(n1[i] == 'x') {
			n1[i] = '0';
			overFlag = 1;
		} 
		if (n2[i] == 'x') {
			n2[i] = '0';
			overFlag = 1;
		}
		int tmpRet = n1[i]-'0'+n2[i]-'0'+carry;
		if(maxCarry != 0) {
			if(tmpRet >= maxCarry) {
				carry = 1;
				ret[i] = tmpRet-maxCarry;
			} else {
				carry = 0;
				ret[i] = tmpRet;
			}
		} else {
			if(tmpRet >= 10) {
				carry = 1;
				ret[i] = tmpRet-10;
			} else {
				carry = 0;
				ret[i] = tmpRet;
			}
		}
	}

}

int main()
{
	freopen("1074.txt","r",stdin);
	char carryTable[21],number1[21],number2[21];
	int carryTableLen,number1Len,number2Len;
	int ret[21];
	int i;

	scanf("%s",carryTable);
	scanf("%s",number1);
	scanf("%s",number2);
	carryTableLen = strlen(carryTable);
	number1Len = strlen(number1);
	number2Len = strlen(number2);
	shift(carryTable,carryTableLen);
	shift(number1,number1Len);
	shift(number2,number2Len);
	initBuf(ret);
	f(carryTable,number1,number2,ret);
//	printf("%s\n",carryTable);
//	printf("%s\n",number1);
//	printf("%s\n",number2);
	for(i=0; ; i++) {
		if(ret[i] != 0) {
			break;
		}
	}
	for(; i<21; i++) {
		printf("%d",ret[i]);
	}
	printf("\n");

	return 0;
}
