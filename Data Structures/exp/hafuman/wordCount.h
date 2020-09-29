#ifndef WORDCOUNT_H
#define WORDCOUNT_H

struct Node {
	char data;
	int cnt;
};
typedef struct Node* Cell;
struct Table {
	Cell cell;
	int capacity;
};
typedef struct Table* CellTable;

CellTable scanFile_wordCount(char *fileName);
static void sortTable_wordCount(CellTable t);
void printCellTable_wordCount(CellTable t);

#endif
