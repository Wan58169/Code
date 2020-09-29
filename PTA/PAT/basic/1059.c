#include<stdio.h>

typedef struct {
	int id;
	int isVisit;
}List;

int isExist(List list[],int listLen,int id)
{
	int i;

	for(i=1; i<=listLen; i++) {
		if(list[i].id == id) 
			return i;
	}
	return 0;
}

int isPrime(int n)
{
	int i;

	if(n == 2)
		return 1;
	for(i=2; i<n; i++) {
		if(n%i == 0) 
			return 0;
	}
	return 1;
}

int main()
{
	freopen("1059.txt","r",stdin);
	int N,K;
	
	scanf("%d",&N);
	List score[N+1];
	//读入N个学生排名
	for(int i=1; i<=N; i++) {
		scanf("%d",&score[i].id);
		score[i].isVisit = 0;
	}
	scanf("%d",&K);
	//读入第i个学生排名
	for(int i=1; i<=K; i++) {
		int id;
		int index;
		scanf("%d",&id);

		index = isExist(score,N,id);
		if(index != 0){
			if(score[index].isVisit == 1) {
				printf("%04d: Checked\n",id);
			} else if(index == 1) {
				printf("%04d: Mystery Award\n",id);
			} else if(isPrime(index)) {
				printf("%04d: Minion\n",id);
			} else {
				printf("%04d: Chocolate\n",id);
			}
			score[index].isVisit = 1;
		} else {
			printf("%04d: Are you kidding?\n",id);
		}
	}
	return 0;
}
