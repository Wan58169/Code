#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "WordCount.h"

Table init_Table(int tableSize)
{
	Table t;

	t = malloc(sizeof(Table));
	t->tableSize = tableSize;
	t->cells = malloc(sizeof(Cell)*tableSize);
	for(int i=0; i<t->tableSize; i++) 
		t->cells[i].cnt = 0;

	return t;
}

void insert_Table(Table t,char ch)
{
	if(t->cells[ch].key != ch)
		t->cells[ch].key = ch;
	t->cells[ch].cnt++;
}

int read_File(const char *filename,Table t)
{
	FILE* fp;
	int ch;
	int cnt = 0;

	if((fp=fopen(filename,"r")) != NULL) {
		while((ch=fgetc(fp))!=EOF) {  
			if(ch != '\n') {
				insert_Table(t,ch);
				cnt++;
			}
		}
		return cnt;
	} else {
		printf("打开%s文件失败\n",filename);
		return -1;
	}
}

void traversal_Table(Table t)
{
	for(int i=0; i<t->tableSize; i++) { 
		if(t->cells[i].cnt != 0)
			printf("%d %c %d\n",i,t->cells[i].key,t->cells[i].cnt);
	}
}

void destroy_Table(Table t)
{
	free(t->cells);
	free(t);
}



















