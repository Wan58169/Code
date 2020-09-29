#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int max,min;

int maxCmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

int generateDiff(int n) 
{
	int a[4];

	for(int i=0; i<4; i++) {
		a[i] = n%10;
		n /= 10;
	}
	if(a[0]==a[1] && a[0]==a[2] && a[0]==a[3])
		return -1;
	qsort(a,4,sizeof(a[0]),maxCmp);
	max = a[0]*1000+a[1]*100+a[2]*10+a[3];
	min = a[3]*1000+a[2]*100+a[1]*10+a[0];

	return max-min;
}

int main()
{
	int n;
	int dif;

	scanf("%d",&n);
	dif = n;
	do {
		dif = generateDiff(dif);
		if(dif == -1) {
			printf("%d - %d = 0000\n",n,n);
			break;
		}
		else 
			printf("%d - %04d = %d\n",max,min,dif);
	} while(dif != 6174);

	return 0;
}
