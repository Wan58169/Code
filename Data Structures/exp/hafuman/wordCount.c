#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "wordCount.h"

CellTable scanFile_wordCount(char *fileName)
{
	int i,j;
	FILE *fp;
	int table[128] = {0};
	int c;
	int cnt_vaildTable = 0;
	
	if((fp=fopen(fileName,"r")) == NULL) {
		printf("%s文件打开失败!\n",fileName);
		exit(0);
	}
	while((c=fgetc(fp)) != EOF) {
		table[c]++;
	} 
	for(i=0; i<sizeof(table)/sizeof(table[0]); i++) {
		if(table[i] != 0)
			cnt_vaildTable++;
	}
	CellTable t = malloc(sizeof(struct Table));
	t->capacity = cnt_vaildTable++;
	t->cell = malloc(sizeof(struct Node)*t->capacity);
	for(i=0,j=0; i<sizeof(table)/sizeof(table[0]); i++) {
		if(table[i] != 0) {
			t->cell[j].data = (char)i;
			t->cell[j].cnt = table[i];
			j++;
		}
	}
	sortTable_wordCount(t);
	return t;
}
static void sortTable_wordCount(CellTable t)
{
	int tmpCnt;
	char tmpData;
	int j;

	for(int i=1; i<t->capacity; i++) {
		tmpCnt = t->cell[i].cnt;
		tmpData = t->cell[i].data;
		for(j=i; j>0&&t->cell[j-1].cnt>tmpCnt; j--) {
			t->cell[j].cnt = t->cell[j-1].cnt;
			t->cell[j].data = t->cell[j-1].data;
		}
		t->cell[j].cnt = tmpCnt;
		t->cell[j].data = tmpData;
	}
}
void printCellTable_wordCount(CellTable t)
{
	int i;
	int len = t->capacity;
	printf("len=%d\n",len);
	for(i=0; i<t->capacity; i++) {
		printf("%c %d\n",t->cell[i].data,t->cell[i].cnt);
	}
}

