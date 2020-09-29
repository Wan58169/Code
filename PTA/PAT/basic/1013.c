#include<stdio.h>

#define MAX 100000

void formPrimeList(int data[],int n)
{
	for(int i=2; i < n/2; i++) {
		for(int j=2; i*j < n; j++) {
			data[i*j] = 0;
		}
	}
}

/*
void formPrimeList(int data[],int end)
{
	int flag = 1;
	
	data[0] = 2;
	int p = 1;
	
	for(int i=3; ; i++) {
		for(int j=2; j<i; j++) {
			if(i%j == 0) {
				flag = 0;
				break;
			}
		}
		
		if(flag == 1)
			data[p++] = i;
		else if(flag == 0) 
			flag = 1;

		if(p == end) break;
	}

}
*/

int main()
{
	int m,n;
	
	scanf("%d %d",&m,&n);
	
	int data[MAX];

	data[0] = data[1] = 0;
	for(int i=2; i<MAX; i++)
		data[i] = 1;
	formPrimeList(data,MAX);

	int ret[n];
	int p = 0;
	for(int i=0; i<MAX && p<n; i++) {
		if(data[i] == 1) {
			ret[p] = i;
			p++;
		}
	}

	int cnt = 1;
	for(int i=m-1; i<n; i++) {
		if(cnt%10 == 0) {
			printf("%d\n",ret[i]);
			cnt++;
		} else {
			if(i == n-1)
				printf("%d",ret[i]);
			else 
				printf("%d ",ret[i]);
			cnt++;
		}
	}

	
	/*
	int ret[n];	
	
	formPrimeList(ret,n);

	int cnt = 1;
	for(int i=m-1; i<n; i++) {
		if(cnt%10 == 0) {
			printf("%d\n",ret[i]);
			cnt++;
		} else {
			if(i == n-1)
				printf("%d",ret[i]);
			else 
				printf("%d ",ret[i]);
			cnt++;
		}
	}
	*/

	return 0;
}
