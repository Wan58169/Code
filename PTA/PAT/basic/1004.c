#include<stdio.h>

typedef struct score
{
	char name[20];
	char id[20];
	int score;
}info;

int main()
{
	int n;

	scanf("%d",&n);
	info x[n];

	for(int i=0; i<n; i++) {
		scanf("%s %s %d",x[i].name,x[i].id,&x[i].score);
	}
	int loc_min = 0;
	int loc_max = 0;
	int score_temp = 0;
	//找出最大
	for(int i=0; i<n; i++) {
		if(score_temp < x[i].score) {
			loc_max = i;
			score_temp = x[i].score;
		}
	}
	//找出最小
	for(int i=0; i<n; i++) {
		if(score_temp > x[i].score) {
			loc_min = i;
			score_temp = x[i].score;
		}
	}
	printf("%s %s\n",x[loc_max].name,x[loc_max].id);
	printf("%s %s\n",x[loc_min].name,x[loc_min].id);

	return 0;
}
