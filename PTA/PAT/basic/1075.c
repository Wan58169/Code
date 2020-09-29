#include<stdio.h>

struct Node {
	int address;
	int data;
	int next;
};
typedef struct Node Record;

void sortRecord(Record r[],int N,int fstAddress)
{
	int i,j;
	Record t[N];
	int address;

	for(i=0; i<N; i++) {
		if(r[i].address == fstAddress) {
			t[0].address = r[i].address;
			t[0].data = r[i].data;
			t[0].next =  r[i].next;
			break;
		}
	}
	for(j=0; j<N-1; j++) {
		for(i=0; i<N; i++) {
			if(t[j].next == r[i].address) {
				t[j+1].address = r[i].address;
				t[j+1].data = r[i].data;
				t[j+1].next = r[i].next;
			}
		}
	}
	for(i=0; i<N; i++) {
		r[i].address = t[i].address;
		r[i].data = t[i].data;
		r[i].next = t[i].next;
	}
}

void printRecord(Record r[],int N)
{
	int i;

	for(i=0; i<N-1; i++) {
		printf("%05d %d %05d\n",r[i].address,r[i].data,r[i].next);
	}
	printf("%05d %d %d\n",r[N-1].address,r[N-1].data,r[N-1].next);

}

void f(Record r[],int N,int k)
{
	int i,j;
	Record t[N];
	int cnt1,cnt2,cnt3;	//<0 0-K >k
	
	cnt1 = cnt2 = cnt3 = 0;
	for(i=0; i<N; i++) {
		if(r[i].data < 0) {
			cnt1++;
		} else if (r[i].data>=0 && r[i].data<=k) {
			cnt2++;
		} else if (r[i].data > k) {
			cnt3++;
		}
	}
	for(i=0; i<N && cnt1!=0; i++) {
		for(j=0; j<N; j++) {
			if(r[j].data < 0) {
				t[i].address = r[j].address;
				t[i].data = r[j].data;
				if(i > 0) {
					t[i-1].next = t[i].address;
				}
				r[j].data = 200000;
				cnt1--;
				break;
			}
		}
	}
	for( ; i<N && cnt2!=0; i++) {
		for(j=0; j<N; j++) {
			if(r[j].data>=0 && r[j].data<=k) {
				t[i].address = r[j].address;
				t[i].data = r[j].data;
				t[i-1].next = t[i].address;
				r[j].data = 200000;
				cnt2--;
				break;
			}
		}
	}
	for( ; i<N && cnt3!=0; i++) {
		for(j=0; j<N; j++) {
			if(r[j].data>k && r[j].data<=10000) {
				t[i].address = r[j].address;
				t[i].data = r[j].data;
				t[i-1].next = t[i].address;
				r[j].data = 200000;
				cnt3--;
				break;
			}
		}
	}
	for(i=0; i<N; i++) {
		r[i].address = t[i].address;
		r[i].data = t[i].data;
		r[i].next = t[i].next;
	}
	r[N-1].next = -1;
}

int main()
{
	freopen("1075.txt","r",stdin);
	int fstAddress,N,k;
	int i;

	scanf("%d %d %d",&fstAddress,&N,&k);
	Record r[N];
	for(i=0; i<N; i++) {
		scanf("%d %d %d",&r[i].address,&r[i].data,&r[i].next);
	}
	sortRecord(r,N,fstAddress);
	f(r,N,k);
	printRecord(r,N);

	return 0;
}

