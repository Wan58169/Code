#include<stdio.h>

int cal_sum(int a,int d_a)
{
	int cnt = 0;

	while(a) {
		int mod = a%10;
		a /= 10;
		if(mod == d_a)
			cnt++;
	}
	int ret = 0;
	for(int i=1,j=0; j<cnt; i*=10,j++)
		ret += d_a*i;
	
	return ret;
}

int main()
{
	int a = 0;
	int b = 0;
	int d_a = 0;
	int d_b = 0;

	scanf("%d %d %d %d",&a,&d_a,&b,&d_b);

	int ret1 = cal_sum(a,d_a);
	int ret2 = cal_sum(b,d_b);
	printf("%d\n",ret1+ret2);

	return 0;
}
