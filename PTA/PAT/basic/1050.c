#include<stdio.h>
#include<stdlib.h>

enum direction {Right,Down,Left,Up};

void calculateMN(int N,int *arg1,int *arg2)
{
	int m,n;

	for(m=N; m>0; m--) {
		if(N%m == 0) {
			n = N/m;
			if(n >= m)
				break;
		}
	}
	*arg1 = n;
	*arg2 = m;
}

void setValue(int *a,int row,int col,int n,int v)
{
	a += row*n+col;
	*a = v;
}

int getValue(int *a,int row,int col,int n)
{
	a += row*n+col;
	return *a;
}
void f(int *a,int row,int col,int m,int n,int *b)
{
	enum direction dir = Right;
	int nMin,nMax,mMin,mMax;

	nMin = mMin = 0;
	nMax = n-1;
	mMax = m-1;
	for(int i=0; i<m*n; i++) {
		setValue(a,row,col,n,b[i]);
		/* 判断是否要改变方向 */
		if(col==nMax && row==mMin)
			dir = Down;
		else if(col==nMax && row==mMax)
			dir = Left;
		else if(col==nMin && row==mMax)
			dir = Up;
		else if(col==nMin && row==mMin+1) {
			dir = Right;
			nMin++;
			nMax--;
			mMin++;
			mMax--;
		}
		/* 按方向前进 */
		if(dir == Right) 
			col++;
		else if(dir == Down)
			row++;
		else if(dir == Left)
			col--;
		else if(dir == Up)
			row--;
	}
}

void printArray(int *a,int m,int n)
{
	int i,j;

	for(i=0; i<m; i++) {
		for(j=0; j<n-1; j++) {
			printf("%d ",getValue(a,i,j,n));
		}
		printf("%d",getValue(a,i,j,n));
		printf("\n");
	}
}

int cmp(const void *a,const void *b)
{
	return *(int*)b - *(int*)a;
}
void initB(int *b,int m,int n)
{
	int t;
	for(int i=0; i<m*n; i++) {
		scanf("%d",&t);
		b[i] = t;
	}
	qsort(b,m*n,sizeof(int),cmp);
}

void initA(int *a,int m,int n)
{
	int i,j;

	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) 
			setValue(a,i,j,n,0);
	}
}
int main()
{
	freopen("1050.txt","r",stdin);
	int N;
	int m,n;

	scanf("%d",&N);
	calculateMN(N,&m,&n);
	int *a = malloc(sizeof(int)*m*n);
	int *b = malloc(sizeof(int)*m*n);
	initA(a,m,n);
	initB(b,m,n);
	f(a,0,0,m,n,b);
	printArray(a,m,n);

	return 0;
}
