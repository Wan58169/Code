#include<stdio.h>

int main()
{
	int a[5] = {0};
	int cnt;
	int n;
	int i = 1;
	int flag_a2 = 1;  //起到控制1和-1的作用
	int isExe_a2 = 0;	//监测a2是否有变化
	int cnt_a4 = 0;	//a4的个数

	freopen("/home/rockywan/C-Language/PAT/basic/data.txt","r",stdin);
	scanf("%d",&cnt);

	for(int k=0; k<cnt; k++) {
		scanf("%d",&n);
		
		int mod = n%5;
		
		switch(mod) {
			case 0: {
				if(n%2 == 0) 
					a[0] += n;
				break;
			}
			case 1: {
				a[1] += flag_a2*n;
				flag_a2 = (flag_a2==1)? -1: 1;
				i++;
				isExe_a2 = 1;
				break;
			}
			case 2: {
				a[2]++;	
				break;
			}
			case 3: {
				a[3] += n;
				cnt_a4++;
				break;
			}
			case 4: {
				a[4] = (n > a[4])? n: a[4];
				break;
			}
		}		
	}

	if(!a[0]) printf("N "); else printf("%d ",a[0]);
	if(!isExe_a2) printf("N "); else printf("%d ",a[1]);
	if(!a[2]) printf("N "); else printf("%d ",a[2]);
	if(!cnt_a4) printf("N "); else printf("%.1lf ",a[3]*1.0/cnt_a4);
	if(!a[4]) printf("N"); else printf("%d",a[4]);

	return 0;
}
