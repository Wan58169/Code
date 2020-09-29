#include<stdio.h>

void reorganize(int org[],int org_re[],int n)
{
	int p = 0;
	for(int i=1; i<n; i++) {
		if(org[i] < org[0]) {
			org_re[p++] = org[i];
		}
	}
	org_re[p++] = org[0];
	for(int i=1; i<n; i++) {
		if(org[i] > org[0]) {
			org_re[p++] = org[i];
		}
	}
}

int isSame(int org[],int tmp[],int n)
{
	if(org[0] == tmp[0]) {
		int org_re[n];
		int tmp_re[n];

		//重新组织org[]
		reorganize(org,org_re,n);
		//重新组织tmp[]
		reorganize(tmp,tmp_re,n);	
		//判断两个数组是否相等
		for(int i=0; i<n; i++) {
			if(org_re[i] != tmp_re[i])
				return 0;
		}
		return 1;
	} else 
		return 0;

}

int main(int argc,char *argv[])
{
//	freopen("SameBinTree.txt","r",stdin);
	int L,N;

	scanf("%d",&N);
	while(N) {
		scanf("%d",&L);
		int org[N];
		for(int i=0; i<N; i++)
			scanf("%d",&org[i]);
		for(int j=0; j<L; j++) {
			int tmp[N];
			for(int k=0; k<N; k++)
				scanf("%d",&tmp[k]);
			if(isSame(org,tmp,N))
				printf("YES\n");
			else 
				printf("NO\n");
		}
		scanf("%d",&N);
	}

	return 0;
}
