#include<stdio.h>

void f(int sum,int sysNumber)
{
	char ret[256];
	int i = 0;

	if(sum == 0)
		printf("0");
	while(sum != 0) {
		ret[i] = sum%sysNumber;
		sum /= sysNumber;
		i++;
	}
	for(--i; i>=0; i--)
		printf("%d",ret[i]);
}

int main()
{
	int a,b;
	int sysNumber;

	scanf("%d %d %d",&a,&b,&sysNumber);
	f(a+b,sysNumber);

	return 0;
}
