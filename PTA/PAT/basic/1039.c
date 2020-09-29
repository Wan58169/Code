#include<stdio.h>

int nBuy = 0;
int nNotBuy = 0;

void buyOrNotBuy(int table1[],int table2[])
{
	int table2Cnt = 0;
	int validCnt = 0;

	for(int i=0; i<128; i++) {
		if(table2[i] != 0) {
			validCnt++;
			if(table2[i] > table1[i]) {
				nNotBuy += table2[i]-table1[i];
			} else if(table2[i] <= table1[i]) {
				nBuy += table1[i]-table2[i];
				table2Cnt++;
			}
		} else if(table2[i] == 0) {
			nBuy += table1[i];
		}
	}
	if(table2Cnt == validCnt)
		printf("Yes %d\n",nBuy);
	else 
		printf("No %d\n",nNotBuy);
}

int main()
{
	freopen("1039.txt","r",stdin);
	int table1[128] = {0};
	int table2[128] = {0};
	char c = 1;

	/* 第一串 */
	while(1) {
		scanf("%c",&c);
		if(c == 10)
			break;
		table1[c]++;
	}
	/* 第二串 */
	while(1) {
		scanf("%c",&c);
		if(c == 10)
			break;
		table2[c]++;
	}
	buyOrNotBuy(table1,table2);

	return 0;
}
