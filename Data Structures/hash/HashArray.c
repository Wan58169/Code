#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef	int ElementType;
struct Node {
	ElementType data;
	int info;	//Empty 1  Full 2  Delete 3
};

typedef struct Node Cell;
struct HashTbl {
	int tableSize;
	Cell *cells;
};

typedef struct HashTbl *H;
typedef int Index;
typedef int Position;

H init(int tableSize)
{
	H h;

	h->tableSize = tableSize;
	h->cells = malloc(sizeof(struct Node)*tableSize);
	for(int i=0; i<tableSize; i++) {
		h->cells[i].data = -1234567;
		h->cells[i].info = 1;
	}

	return h;
}

Index hash(H h,ElementType key)
{
	return key%h->tableSize;
}

Position find(H h,ElementType key)
{
	Position nowPos,curPos;
	int cNum = 0;

	nowPos = curPos = hash(h,key);
	//非空 && 关键字!=key
	while(h->cells[curPos].info==2 && h->cells[curPos].data!=key) {
		if(++cNum%2) {	//奇数
			curPos = nowPos+(cNum+1)/2*(cNum+1)/2;
			while(curPos >= h->tableSize)
				curPos -= h->tableSize;
		} else {	//偶数
			curPos = nowPos-cNum/2*cNum/2;
			while(curPos < 0)
				curPos += h->tableSize;
		}
	}
	//空 || 关键字==key
	return curPos;
}

void insert(H h,ElementType key)
{
	Position pos = find(h,key);

	if(h->cells[pos].info == 1) {	//空
		h->cells[pos].data = key;
		h->cells[pos].info = 2;
	} else if(h->cells[pos].info == 2) {	//关键字==key
		printf("The element exists!\n");
	}
}

void traversal(H h)
{
	for(int i=0; i<h->tableSize; i++) {
		printf("%d %d\n",i,h->cells[i].data);
	}
}

int main(int argc,char *argv[])
{
	freopen("data_HashArray.txt","r",stdin);
	H h;
	int n;
	ElementType buf;

	h = init(11);
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&buf);
		insert(h,buf);
	}
	traversal(h);

	return 0;
}
