#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

#define NUll 0 
#define FILENAME 50   /* 文件名称的长度  */
#define Number_HfmTree 200   /*  哈夫曼树结点的个数  */
#define HFMTRACK 50 /* 记录字符编码的数组容量 */
#define CODELENGTH 10000 /* 文本编码的长度 */
 
int theNumberOfCharacters = 0;/*  用于记录文本文件的字符个数  */
int capacity = 0;    /*  用于测试哈夫曼树容量  */
char CODE[CODELENGTH];
char UNCODE[CODELENGTH];

typedef struct LNode
{
	char data;
	int num;
	struct LNode* next;
}LNode;

typedef struct HfmTree
{
	int no;
	char data;
	int num;
	int parent;
	int lchild;
	int rchild;
}HfmTree;

typedef struct 
{
	int num;
	int i;
}ShaoBing;

typedef struct HfmTrack
{
	char data;
	char track[HFMTRACK];
	int length;
}HfmTrack;

void Read_File(char filename[]);
void InputFileIntoLNode(char filename[],LNode* L);
LNode* Init_LNode(LNode* L);
void Insert_LNode(LNode* L, char c);
void Print_LNode(LNode* L);
int GetLength_LNode(LNode* L);
void Init_HfmTree(HfmTree Hfm[]);
void Insert_HfmTree(HfmTree Hfm[],LNode* L);
void Print_HfmTree(HfmTree Hfm[]);
void ByOrder_HfmTree(HfmTree Hfm[]);
void CreateCode(HfmTree Hfm[],HfmTrack Track[]);
void Print_Code(HfmTrack Track[]);
void Translate_Code(HfmTrack Track[],char filename[]);
void Print_CODE();
void Compress_Code(char filename[]);
void UnCompress_Code(char filename[]);
void Print_UNCODE();
void Reverse_Code(HfmTrack Track[]);
void TranslateIntoTxt(char filename[],HfmTrack Track[]);

void main()
{	
	char filename[FILENAME];
	LNode* L;
	HfmTree Hfm[Number_HfmTree];
	HfmTrack Track[HFMTRACK];
	int action;
	
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\t|      此程序用于txt文件压缩     |\n");
	printf("\t\t\t|                                |\n");
	printf("\t\t\t|   1.压缩文件(start)            |\n");
	printf("\t\t\t|   2.退出程序(exit)             |\n");
	printf("\t\t\t|                                |\n");
	printf("\t\t\t---------------------------------|\n");
	scanf("%d",&action);
	switch(action) {
		case 1: {
		/* start */
		printf("Input the Name of File:");
		scanf("%s",filename);
		/* open the file and read the content */
		Read_File(filename);	
		/* Init_LNode */
		L = Init_LNode(L);	
		/*count and input data into LNode */
	 	InputFileIntoLNode(filename,L);
		/* print the LNode */
		Print_LNode(L);
		/* init the HfmTree */
		Init_HfmTree(Hfm);
		/* insert data into HfmTree */
		Insert_HfmTree(Hfm,L);	
		/* free LNode */
	
		/* Sort the HfmTree */
		ByOrder_HfmTree(Hfm);
		Print_HfmTree(Hfm);		
		CreateCode(Hfm,Track);
		Reverse_Code(Track);	
		Print_Code(Track);	
		Translate_Code(Track,filename);	
		Print_CODE();
		/* compress the text */
		Compress_Code("D:\\C-Language\\Hafuman\\compresscode.txt");	
		/* uncompress the code */
		UnCompress_Code("D:\\C-Language\\Hafuman\\compresscode.txt");
		Print_UNCODE();
		TranslateIntoTxt("D:\\C-Language\\Hafuman\\restore.txt",Track);
		printf("\nMission is accomplished.\n");
		system("pause");
			break;
		}
		case 2 :{
			break;
		}
	}
	
}


LNode* Init_LNode(LNode* L)
{
	L = (LNode* )malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}

void Read_File(char filename[])
{
	FILE* file1;
	char c;
	
	if( (file1=fopen(filename,"r")) == NULL ){
		printf("File can not open.");
		exit(0);
	}
	while( (c=fgetc(file1)) != EOF ){
		fputc(c,stdout);
		theNumberOfCharacters++;	
	}
	printf("\n");
	printf("The Number of Characters is %d\n",theNumberOfCharacters);
	printf("\n");
	fclose(file1);
}

void InputFileIntoLNode(char filename[],LNode* L)
{
	FILE* file1;
	char c;
	LNode *temp;
	
	if( (file1 = fopen(filename,"r")) == NULL){
		printf("File can not open.");
		exit(0);
	}
	if( (c=fgetc(file1)) != EOF){
		temp = (LNode* )malloc(sizeof(LNode));
		temp->data = c;
		temp->num = 1;
		temp->next = NULL;
		L->next = temp;
	}
	while( (c=fgetc(file1)) != EOF){
		Insert_LNode(L,c);
	}
	printf("\n");
	fclose(file1);
}

void Insert_LNode(LNode* L,char c)
{
	LNode* p;
	LNode* temp;
	
	p = L->next;
	while(c != p->data && p->next != NULL){
		p = p->next;
	}
	if(c == p->data && p->next != NULL){
		p->num++;
		p = L->next;
	}
	else if(p->next == NULL && c == p->data){
		p->num++;
		p = L->next;
	}
	else if(p->next == NULL && c != p->data){
		temp = (LNode* )malloc(sizeof(LNode));
		temp->data = c;
		temp->num = 1;
		temp->next = NULL;
		p->next = temp;
		p = L->next;
	}
}

void Print_LNode(LNode* L)
{
	LNode* p;
	
	p = L->next;
	printf("char\tnum\n");
	while( p ){
		printf("%c\t%d\n",p->data,p->num);
		p = p->next;
		capacity++;
	}
	printf("The capacity of this LNode is %d\n",capacity);
	printf("\n");
}

int GetLength_LNode(LNode* L)
{
	LNode* p;
	int Length = 0;
	
	p = L;
	p = p->next;
	while(p){
		Length++;
		p = p->next;
	}
	return Length;
}

void Init_HfmTree(HfmTree Hfm[])
{
	int i;
	
	for(i =0; i < 2*capacity-1; i++){
		Hfm[i].no = i;
		Hfm[i].num = 10000;
		Hfm[i].lchild = -1;
		Hfm[i].rchild = -1;
		Hfm[i].parent = -1;
	}
	
}

void Insert_HfmTree(HfmTree Hfm[],LNode* L)
{
	int i;
	LNode* p;
	
	p = L->next;
	for(i=0; i < capacity; i++){
		Hfm[i].data = p->data;
		Hfm[i].num = p->num;
		p = p->next;
	}
}

void Print_HfmTree(HfmTree Hfm[])
{
	int i;
	
	printf("NO.\tData\tnum\tparent\tlchild\trchild\n");
	for(i = 0; i < capacity; i++){
		printf("%d\t%c\t%d\t%d\t%d\t%d\t\n",Hfm[i].no,Hfm[i].data,Hfm[i].num,Hfm[i].parent,Hfm[i].lchild,Hfm[i].rchild);
	}
	for(i = capacity; i < 2*capacity-1; i++){
		printf("%d\t%c\t%d\t%d\t%d\t%d\t\n",Hfm[i].no,Hfm[i].data,Hfm[i].num,Hfm[i].parent,Hfm[i].lchild,Hfm[i].rchild);
	}
	printf("The capacity of this HfmTree is %d\n",2*capacity-1);
	printf("\n");
}

void ByOrder_HfmTree(HfmTree Hfm[])
{
	int i,j;
	ShaoBing m1,m2;
	
	m1.num = m2.num = 10000;
	for(j = capacity; j < 2*capacity-1; j++){
		m1.num = m2.num = 10000;
		m1.i = m2.i = 0;
	 	for(i = 0; i < 2*capacity-1; i++){
			if(Hfm[i].num < m1.num && Hfm[i].parent == -1){
				m2.num = m1.num;
				m2.i = m1.i;
				m1.num = Hfm[i].num;
				m1.i = i;
			}			
			else if(Hfm[i].num < m2.num && Hfm[i].parent == -1){
				m2.num = Hfm[i].num;
				m2.i = i;
			}
	   	}
	   	Hfm[j].num = m1.num + m2.num;
		Hfm[j].lchild = m1.i;
		Hfm[j].rchild = m2.i;
		Hfm[m1.i].parent = j;
		Hfm[m2.i].parent = j;
	}
}

void CreateCode(HfmTree Hfm[],HfmTrack Track[])
{
	int i;
	int j = 0;
	int k;
	int tempNo;
	char tempTrack;
	
	for(i = 0; i < 2*capacity-1; i++) {
		tempNo = Hfm[i].no;
		Track[i].data = Hfm[i].data;
		Track[i].length = 0;
		k = 0;
		
		while(j < 2*capacity-1) {
			if(tempNo==Hfm[j].lchild || tempNo==Hfm[j].rchild) {
				if(Hfm[j].lchild == tempNo) {
					tempTrack = '0';
				} else {
					tempTrack = '1';
				}
				tempNo = Hfm[j].no;
				j = 0;
				Track[i].track[k] = tempTrack;
				Track[i].length++;
				k++;
				if(Hfm[tempNo].parent == -1)
					break;
			}
			else
				j++;
		}	
	}
}

void Reverse_Code(HfmTrack Track[])
{
	int i;
	int f;
	int r;
	char temp;
	
	for(i = 0; i < capacity; i++) {
		f = 0;
		r = Track[i].length-1;
		while(f < Track[i].length/2) {
			temp = Track[i].track[f];
			Track[i].track[f] = Track[i].track[r];
			Track[i].track[r] = temp;
			f++;
			r--;		
		}
	}	
}

void Print_Code(HfmTrack Track[])
{
	int i,j = 0;
	
	for(i = 0; i < capacity; i++) {
		printf("%c: ",Track[i].data);
		while(j < Track[i].length) {
			printf("%c",Track[i].track[j]);
			j++;
		}
		j = 0;
		printf("\t%d\n",Track[i].length);
	}
	printf("\n");
}

void Translate_Code(HfmTrack Track[],char filename[])
{
	FILE* fp;
	char c;
	int i;
	int k = 0;
	int j = 0;

	if( (fp=fopen(filename,"r")) == NULL) {
		printf("File can not open.");
		exit(0);
	}
	while( (c=fgetc(fp)) != EOF ) {
		for(i = 0; i < capacity; i++) {
			if(c == Track[i].data) {
				while(k < Track[i].length) {
					CODE[j] = Track[i].track[k];
					j++;
					k++;	
				}	
			}
			k = 0;
		}	
	}
	CODE[j] = '2';
	fclose(fp);
}

void Print_CODE()
{
	int i;
	int cnt = 0;
	
	printf("\nThe content of CODE[] :\n");
	for(i = 0; CODE[i] != '2'; i++) {
		if(i % 8 == 0 && i != 0)
			printf(" ");
		printf("%c",CODE[i]);
		cnt++;
	}
	printf("\nThe Length of Txt_Code is %d\n",cnt);
	printf("\n");
}

void Compress_Code(char filename[])
{
	FILE* fp;
	int i = 0;
	int j = 0;
	int k;
	int p = 7;
	int cnt = 0;
	char temp[8];
	char t;
	int ret = 0;
	
	printf("\n");
	if( (fp=fopen(filename,"w")) == NULL) {
		printf("The file cannot open.");
		exit(0);
	}
	while(CODE[j] != '2') {
		while(i < 8 && CODE[j] != '2') {
			temp[i] = CODE[j];
			i++;
			j++;
		}
		for(k = 0; k < 8; k++) {
			t = temp[k];
			temp[k] = '0';
			ret += (t-48)*pow(2,p);
			p--;
		}
		p = 7;
		i = 0;
		printf("%c",ret);
		fputc(ret,fp);
		ret = 0;
		cnt++;
	}
	fclose(fp);
	printf("\nThe Length of Compress_Txt is %d\n",cnt);
	printf("\n");
}

void UnCompress_Code(char filename[]) 
{
	FILE* fp;
	int c;
	int i = 0;
	int j = 0;
	char t;
	int k;
	char uncode[8];
	
	if( (fp=fopen(filename,"r")) == NULL) {
		printf("The file cannot open.");
		exit(0);
	}
	while( (c=fgetc(fp)) != EOF ) {
		for(k = 0; k < 8; k++) {
			uncode[k] = '0';
		}
		k = 7;
		while(i < 8 && c != 0) {
			t = c % 2;
			t += 48;
			c /= 2;
			uncode[k] = t;
			i++;		
			k--;
		}
		k = 0;
		while(k < 8) {
			UNCODE[j] = uncode[k];
			k++;
			j++;
		}
		i = 0;
	}
	fclose(fp);
	UNCODE[j] = '2'; 
}

void Print_UNCODE()
{
	int i,j;
	int cnt = 0;
	
	printf("\nThe content of UNCODE[] :\n");
	for(i = 0; UNCODE[i] != '2'; i++) {
		if(i % 8 == 0 && i != 0) 
			printf(" ");
		printf("%c",UNCODE[i]);
		cnt++;
	}
	printf("\nThe Length of Txt_Code is %d\n",cnt);
	printf("\n");
}

void TranslateIntoTxt(char filename[],HfmTrack Track[])
{
	FILE* fp;
	int i = 0;
	int j = 0;
	int k = 0;
	int ret = 0;
	
	if( (fp=fopen(filename,"w")) == NULL ) {
			printf("The file cannot open.");
			exit(0);
	}
	while(UNCODE[k] != '2') {
		for(i = 0; i < capacity; i++) {
			j = 0;
			while(UNCODE[k] != '2') {
				if(Track[i].track[j] == UNCODE[k] && j < Track[i].length) {
					j++;
					k++;
					if(j == Track[i].length) {
						printf("%c",Track[i].data);
						fputc(Track[i].data,fp);
						break;
					}		
				} else if(Track[i].track[j] != UNCODE[k]) {
					k -= j;
					j = 0;
					break;
				} 	
			}
		}
	}
	fclose(fp);
}
