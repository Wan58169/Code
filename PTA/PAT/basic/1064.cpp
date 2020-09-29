#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int sumTmp(int tmp)
{
	int ret = 0;
	while(tmp != 0) {
		ret += tmp%10;
		tmp /= 10;
	}
	return ret;
}

int main()
{
	freopen("1064.txt","r",stdin);
	int N;

	cin >> N;
	int *flag = (int*)malloc(sizeof(int)*64);
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		int index = sumTmp(tmp);
		flag[index]++;
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i=1; i<64; i++) {
		if(flag[i] != 0) {
			cnt1++;
		}
	}
	printf("%d\n",cnt1);

	for(int i=1; i<64; i++) {
		if(flag[i] != 0) {
			cnt2++;
			if(cnt1 == cnt2) {
				printf("%d",i);
				break;
			} else {
				printf("%d ",i);
			}	
		}
	}
	return 0;
}
