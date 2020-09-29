#include<stdio.h>

int cnt = 0;

int isEven(int n)
{
	if(n%2 == 0)
		return 1;
	else 
		return 0;
}

int main()
{
	int n;

	scanf("%d",&n);
	
	while(n!=1) {
		if(isEven(n)) {
			n /= 2;
			cnt++;
		} else {
			n = 3*n+1;
		} 
	}
	printf("%d\n",cnt);
	return 0;
}
