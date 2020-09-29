#include<stdio.h>
#include<math.h>

int main()
{
	freopen("1063.txt","r",stdin);
	int N;
	double max = 0;

	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		double ret = sqrt(a*a+b*b);
		if(ret-max > 1e-12) {
			max = ret;
		}
	}
	printf("%.2lf",max);
	return 0;
}
