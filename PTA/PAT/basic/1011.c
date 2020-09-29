#include<stdio.h>

int main()
{
	long a,b,c;
	int n;
	
	scanf("%d",&n);
	int ret[n];

	for(int i=0; i<n; i++) {
		scanf("%ld %ld %ld",&a,&b,&c);
		if(a+b > c)
			ret[i] = 1;
		else 
			ret[i] = 0;
	}
	
	for(int i=0; i<n; i++) {
		if(ret[i] == 1) 
			printf("Case #%d: true\n",i+1);	
		else 
			printf("Case #%d: false\n",i+1);
	}

	return 0;
}
