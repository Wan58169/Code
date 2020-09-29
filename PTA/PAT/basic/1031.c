#include<stdio.h>

int f(char *buf)
{
	int weight[] = {7,9,10,5,8,
					4,2,1,6,3,
					7,9,10,5,8,
					4,2};
	int sum = 0;
	int ret;
	char check;

	for(int i=0; i<17; i++) {
		if(buf[i] != 'X') 
			sum += (buf[i]-'0')*weight[i];
		else 
			return 0;
	}
	ret = sum%11;
	switch(ret) {
		case 0: check = '1'; break;
		case 1: check = '0'; break;
		case 2: check = 'X'; break;
		case 3: check = '9'; break;
		case 4: check = '8'; break;
		case 5: check = '7'; break;
		case 6: check = '6'; break;
		case 7: check = '5'; break;
		case 8: check = '4'; break;
		case 9: check = '3'; break;
		case 10: check = '2'; break;
	}
	if(check == buf[17])
		return 1;
	else
		return 0;
}

int main()
{
	freopen("1031.txt","r",stdin);
	int n;
	char buf[18];
	int cnt = 0;

	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%s",buf);
		if(f(buf))
			cnt++;
		else
			printf("%s\n",buf);
	}
	if(cnt == n)
		printf("All passed\n");

	return 0;
}
