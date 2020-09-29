#ifndef WORDCOUNT_H
#define WORDCOUNT_H

struct Node {
	char key;
	int cnt;
};
typedef struct Node Cell;

struct TableHead {
	int tableSize;
	Cell *cells;
};
typedef struct TableHead *Table;

Table init_Table(int tableSize);
void insert_Table(Table t,char ch);
int read_File(const char *filename,Table t);
void traversal_Table(Table t);
void destroy_Table(Table t);

#endif
