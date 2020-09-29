#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct {
	int id1;
	int id2;
}CP;

int cmp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	freopen("1065.txt","r",stdin);
	int N;

	scanf("%d",&N);
	CP cp[N];
	for(int i=0; i<N; i++) {
		scanf("%d %d",&cp[i].id1,&cp[i].id2);
	}
	int M;
	scanf("%d",&M);
	int idList[M];
	for(int i=0; i<M; i++) {
		scanf("%d",&idList[i]);
	}
	for(int i=0; i<M-1; i++) {
		int id1 = idList[i];
		int id2;
		int flag = 0;
		//找另一半
		for(int j=0; j<N; j++) {
			if(cp[j].id1 == id1) {
				id2 = cp[j].id2;
				flag = 1;
				break;
			} else if(cp[j].id2 == id1) {
				id2 = cp[j].id1;
				flag = 1;
				break;
			}
		}
		//划掉cp
		if(flag == 1) {
			for(int j=0; j<M; j++) {
				if(idList[j] == id2) {
					idList[j] = idList[i] = -1;
				}
			}
		}
	}
	int cnt = 0;
	int ret[M];
	for(int i=0,j=0; i<M; i++) {
		if(idList[i] != -1) {
			cnt++;
			ret[j++] = idList[i];
		}
	}
	qsort(ret,cnt,sizeof(int),cmp);
	printf("%d\n",cnt);
	for(int i=0; i<cnt-1; i++) {
		printf("%d ",ret[i]);
	}
	printf("%d",ret[cnt-1]);
	return 0;
}
