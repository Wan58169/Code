#include<stdio.h>

int main()
{
	int N;

	scanf("%d",&N);
	int buf[N];
	int sum = 0;
	for(int i=0; i<N; i++) {
		scanf("%d",&buf[i]);
	}
	//i代表十位数
	//j代表个位数
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i != j) {
				sum += buf[i]*10+buf[j];
			}
		}
	}
	printf("%d",sum);
	return 0;
}
