#include<stdio.h>

void f1(int *g1,int *s1,int *k1,int *g2,int *s2,int *k2,int *ret_g,int *ret_s,int *ret_k)
{
	if(*k2 >= *k1) 
		*ret_k = *k2-*k1;
	else {
		*ret_k = *k2+29-*k1;
		(*s2)--;
	}
	if(*s2 >= *s1)
		*ret_s = *s2-*s1;
	else {
		*ret_s = *s2+17-*s1;
		(*g2)--;
	}
	*ret_g = *g2-*g1;
}

void f2(int *s1,int *k1,int *s2,int *k2,int *ret_s,int *ret_k)
{
	if(*k2 >= *k1)
		*ret_k = *k2-*k1;
	else {
		*ret_k = *k2+29-*k1;
		(*s2)--;
	}
	*ret_s = *s2-*s1;
}

int main()
{
	int g1,s1,k1;
	int g2,s2,k2;
	int ret_g,ret_s,ret_k;

	scanf("%d.%d.%d %d.%d.%d",
		&g1,&s1,&k1,&g2,&s2,&k2);
	if(g1 < g2) {
		f1(&g1,&s1,&k1,&g2,&s2,&k2,&ret_g,&ret_s,&ret_k);
	} else if(g1 > g2) {
		printf("-");
		f1(&g2,&s2,&k2,&g1,&s1,&k1,&ret_g,&ret_s,&ret_k);
	} else if(g1 == g2) {
		ret_g = 0;
		if(s1 < s2) {
			f2(&s1,&k1,&s2,&k2,&ret_s,&ret_k);
		} else if(s1 > s2) {
			printf("-");
			f2(&s2,&k2,&s1,&k1,&ret_s,&ret_k);
		} else if(s1 == s2) {
			ret_s = 0;
			if(k1 < k2) {
				ret_k = k2-k1;			
			} else if(k1 > k2) {
				printf("-");
				ret_k = k1-k2;
			} else if(k1 == k2) {
				ret_k = 0;
			}
		}
	}
	printf("%d.%d.%d\n",ret_g,ret_s,ret_k);

	return 0;
}
