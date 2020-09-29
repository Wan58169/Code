#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct {
	int address;
	int data;
	int next;
}Info;

void print(Info *info,int n)
{
	for(int i=1; i<=n; i++) {
		printf("%05d %d ",info[i].address,info[i].data);
		if(info[i].next == -1)
			printf("-1\n");
		else 
			printf("%05d\n",info[i].next);
	}
}

void sort(Info *info,int headAddress,int n)
{
	Info *ret = malloc(sizeof(Info)*(n+1));
	int i,index = 1;

	while(headAddress != -1) {
		for(i=1; i<=n; i++) {
			if(info[i].address == headAddress)
				break;
		}
		ret[index].address = info[i].address;
		ret[index].data = info[i].data;
		ret[index].next = info[i].next;
		index++;
		headAddress = info[i].next;
	}
	for(i=1; i<=n; i++) {
		info[i].address = ret[i].address;
		info[i].data = ret[i].data;
		info[i].next = ret[i].next;
	}
	free(ret);
}

void reserve(Info *info,int headAddress,int n,int k)
{	
	sort(info,headAddress,n);
	Info *ret = malloc(sizeof(Info)*(n+1));
	int startT = 1;
	int endT = k;
	int index = 1;
	int start = startT;
	int end = endT;
	
	while(1) {
		for(int i=0; i<k; i++) {
//			printf("end ..%d,& ..%d\n",end,info[end-1].address);
			ret[index].address = info[end].address;
			ret[index].data = info[end].data;
			ret[index++].next = info[--end].address;
//			printf("ret[%d].addr ..%d\n",index,ret[index].address);
//			printf("ret[%d].next ..%d\n",index,ret[index].next);
//			printf("-------------------------\n");
		}
		start = startT += k;
		end = endT += k;
		if(end > n)
			break;
	}
	endT = k;
	for(int i=endT; i<n; i+=k) 
		ret[i].next = ret[i+1].address;
	ret[n].next = -1;
	print(ret,n);
}

int main()
{
	freopen("1025.txt","r",stdin);
	int headAddress,n,k;

	scanf("%d %d %d",&headAddress,&n,&k);
	Info info[n+1];
	for(int i=1; i<=n; i++)
		scanf("%d %d %d",&info[i].address,&info[i].data,&info[i].next);
	reserve(info,headAddress,n,k);

	return 0;
}
