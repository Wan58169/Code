#include<stdio.h>
#include<string.h>

int cnt = 0;
/*
int isPrime(int n)
{
	for(int i=2; i<n; i++) {
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n;

	scanf("%d",&n);

	for(int i=1; i<=n-2; i++) {
		int j = i+2;
		if(isPrime(i) && !isPrime(i+1) && isPrime(j)) {
			cnt++;
//			printf("%d-%d\n",i,j);
		}
	}

	printf("%d\n",cnt);

	return 0;
}
*/

void formList(int data[],int n)
{
	for(int i=2; i<=n/2; i++)
		for(int j=2; i*j<=n; j++)  
			data[i*j] = 1;
}

int main()
{
	int n;

	scanf("%d",&n);
	int data[n+1];
	for(int i=0; i<n+1; i++)
		data[i] = 0;
	formList(data,n);
	
	int formPrime[n];
	int j =0;
	for(int i=1; i<n+1; i++) {
		if(data[i] == 0) {
			formPrime[j] = i;
			j++;
		}
	}
	for(int i=0; i<j; i++) {
		int tmp = formPrime[i+1]-formPrime[i]; 
		if(tmp == 2)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
