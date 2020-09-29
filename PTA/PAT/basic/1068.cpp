#include<stdio.h>
#include<math.h>

int getValue(int p[],int row,int col,int rowNum)
{
	return p[row*rowNum+col];
}

int judge(int p[],int minRow,int maxRow,int curCol,int row,int col,int M,int TOL)
{
	int i;

	for(i=minRow; i<=maxRow; i++) {	
		int a = getValue(p,i,curCol,M);
		int b = getValue(p,row,col,M);
		if((b-a) < TOL) {
			return 0;		
		}
	}
	return 1;
}

void f(int p[],int pLen,int N,int M,int TOL)
{
	int row,col;
	int cnt = 0;
	int x,y;

	for(row=1; row<N-1; row++) {
		for(col=1; col<M-1; col++) {
			//九宫格判别 左三个 上一个 下一个 右三个 一个不能多一个不能少
			if(judge(p,row-1,row+1,col-1,row,col,M,TOL) &&
			   judge(p,row-1,row-1,col,row,col,M,TOL) &&
			   judge(p,row+1,row+1,col,row,col,M,TOL) &&
			   judge(p,row-1,row+1,col+1,row,col,M,TOL)) {
			   	cnt++;
				if(cnt == 1) {
					x = row;
					y = col;
				}
			}
		}
	}
	if(cnt == 1) {
		printf("(%d, %d): %d\n",y+1,x+1,getValue(p,x,y,M));
	} else if (cnt > 1) {
		printf("Not Unique\n");
	} else if (cnt == 0) {
		printf("Not Exist\n");
	}
}

int main()
{	
	freopen("1068.txt","r",stdin);

	int M,N,TOL;
	scanf("%d %d %d",&M,&N,&TOL);
	int pLen = N*M;
	int p[pLen];
	for(int i=0; i<pLen; i++) {
		scanf("%d",&p[i]);
	}
	if(M<=2 || N<=2) {
		printf("Not Exist\n");
	} else {
		f(p,pLen,N,M,TOL);
	}

	return 0;
}
