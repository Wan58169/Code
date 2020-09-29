#include<stdio.h>

typedef struct 
{
	int num;
	int flag;
}calla;

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
	
	calla x[n];
	for(int i=0; i<n; i++) {
		scanf("%d",&x[i].num);
		x[i].flag = 0;
	}
	/*
	for(int i=0; i<n; i++) {
		printf("%d %d\n",x[i].num,x[i].flag);
	}
	*/
	calla t[n];
	//x[]赋值t[]
	for(int i=0; i<n; i++) {
		t[i].num = x[i].num;
		t[i].flag = x[i].flag;
	}
	for(int i=0; i<n; i++) {
		while(t[i].num != 1) {
			if(isEven(t[i].num)) {
				t[i].num /= 2;
			} else {
				t[i].num = 3*t[i].num+1;	
			}
			for(int j=0; j<n; j++) {
				if(x[j].num == t[i].num) {
					x[j].flag = 1;
					break;
				}
			}
		}
	}
	//排序，打印
	int ret[105];
	int len = 0;
	for(int i=0; i<n; i++) {
		if(x[i].flag == 0) {
			ret[len] = x[i].num;
			len++;
		}
	}
	for(int j=1; j<len; j++) {
		int TMP = ret[j];
		int p;
		for(p=j; p>=1&&ret[p-1]<TMP;p--)
			ret[p] = ret[p-1];
		ret[p] = TMP;
	}
	for(int i=0; i<len-1; i++)
		printf("%d ",ret[i]);
	printf("%d",ret[len-1]);
	return 0;
}
