#include<stdio.h>

struct Node {
	char key;
	int no;
	int price;
};
typedef struct Node Book;

void tableSort(Book b[],int ret[],int N)
{
	char tmpKey;
	int i,j;

	for(i=1; i<N; i++) {
		tmpKey = b[i].key;
		for(j=i; j>0&&b[ret[j-1]].key>tmpKey; j--) 
			ret[j] = ret[j-1];
		ret[j] = b[i].no;
	}
}

void printBook(Book b[],int ret[],int N)
{
	for(int i=0; i<N; i++) 
		printf("%c %d %d\n",b[ret[i]].key,b[ret[i]].no,b[ret[i]].price);
}

int main()
{
	freopen("tableSort.txt","r",stdin);

	int N;
	char buf[256];

	scanf("%d",&N);
	fgets(buf,256,stdin);
	Book b[N];
	int ret[N];
	for(int i=0; i<N; i++) {
		scanf("%c %d",&b[i].key,&b[i].price);
		fgets(buf,256,stdin);
		b[i].no = ret[i] = i;
	}
	tableSort(b,ret,N);
	printBook(b,ret,N);

	return 0;
}
