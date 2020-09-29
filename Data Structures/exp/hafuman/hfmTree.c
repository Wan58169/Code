#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "wordCount.h"

struct HfmTree {
	int no;
	char data;
	int cnt;
	int parent;
	int lchild;
	int rchild;
};
typedef struct HfmTree* HfmTree;
struct HfmTreeTable {
	HfmTree hfmTree;
	int capacity;
};
typedef struct HfmTreeTable* HfmTreeTable;

HfmTreeTable initHfmTree_hfmTree(CellTable ct)
{
	HfmTreeTable ht;
	int i;

	ht = malloc(sizeof(struct HfmTreeTable));
	ht->capacity = ct->capacity*2-1;
	ht->hfmTree = malloc(sizeof(struct HfmTree)*ht->capacity);
	for(i=0; i<ct->capacity; i++) {
		ht->hfmTree[i].no = i;
		ht->hfmTree[i].data = ct->cell[i].data;
		ht->hfmTree[i].cnt = ct->cell[i].cnt;
		ht->hfmTree[i].parent = -1;
		ht->hfmTree[i].lchild = -1;
		ht->hfmTree[i].rchild = -1;
	}
	for(; i<ht->capacity; i++) {
		ht->hfmTree[i].no = i;
		ht->hfmTree[i].data = -1;
		ht->hfmTree[i].cnt = 10000;
		ht->hfmTree[i].parent = -1;
		ht->hfmTree[i].lchild = -1;
		ht->hfmTree[i].rchild = -1;
	}

	return ht;
}

void buildHfmTree_hfmTree(HfmTreeTable ht)
{
	struct TmpV {
		int no;
		int cnt;
	};
	struct TmpV tmp1,tmp2;

	for(int j=(ht->capacity+1)/2; j<ht->capacity; j++) {
		tmp1.cnt = tmp2.cnt = 10000;
		tmp1.no = tmp2.no = 0;
		for(int i=0; i<ht->capacity; i++) {
			if(ht->hfmTree[i].parent == -1) {
				if(ht->hfmTree[i].cnt < tmp1.cnt) {
					tmp2.cnt = tmp1.cnt;
					tmp2.no = tmp1.no;
					tmp1.cnt = ht->hfmTree[i].cnt;
					tmp1.no = ht->hfmTree[i].no;
				} else if(ht->hfmTree[i].cnt < tmp2.cnt) {
					tmp2.cnt = ht->hfmTree[i].cnt;
					tmp2.no = ht->hfmTree[i].no;
				}
			}
		}
		ht->hfmTree[j].lchild = tmp1.no;
		ht->hfmTree[j].rchild = tmp2.no;
		ht->hfmTree[j].cnt = tmp1.cnt+tmp2.cnt;
		ht->hfmTree[tmp1.no].parent = j;
		ht->hfmTree[tmp2.no].parent = j;
	}
}
void printHfmTree_hfmTree(HfmTreeTable ht)
{
	for(int i=0; i<ht->capacity; i++) {
		printf("%03d ",ht->hfmTree[i].no);
		if(ht->hfmTree[i].data == 10)
			printf("10 ");
		else 
			printf("%c ",ht->hfmTree[i].data);
		printf("%03d %03d %03d %03d\n",
			ht->hfmTree[i].cnt,ht->hfmTree[i].parent,
			ht->hfmTree[i].lchild,ht->hfmTree[i].rchild);
	}
}

int main()
{
	CellTable ct;
	HfmTreeTable ht;

	ct = scanFile_wordCount("sourceData.txt");
	ht = initHfmTree_hfmTree(ct);
	buildHfmTree_hfmTree(ht);
	printHfmTree_hfmTree(ht);

	return 0;
}
