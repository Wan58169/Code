#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
	int score;
	char op[5];
}ANS;

void setValue(char buf[],int x,int y,int numCol,char v)
{
	buf[x*numCol+y] = v;
}

char getValue(char buf[],int x,int y,int numCol)
{
	return buf[x*numCol+y];
}

void scanIntoAns(ANS ans[],int ansLen)
{
	int i;
	int num;				//输入的字符串长度
	int index_ansOp = 0;	//ans[]中op字符串的指针

	for(i=0; i<ansLen; i++) {
		index_ansOp = 0;
		scanf("%d %*d %d",&ans[i].score,&num);
		while(index_ansOp < num) {
			char c;
			scanf("%c",&c);
			if(isalpha(c)) {
				ans[i].op[index_ansOp++] = c;
			}
		}
		ans[i].op[index_ansOp] = '\0';
	}

}

void scanIntoStuAns(char stu_ans[],int N,int M)
{
	int i;

	for(i=0; i<N; i++) {
		int index = 0;
		while(1) {
			char c;
			scanf("%c",&c);
			if(c == '\n') 
				break;
			if(isalnum(c)) {
				setValue(stu_ans,i,index,6*M,c);
			}
		}
		setValue(stu_ans,i,index,6*M,'\0');
	}
}

int main()
{
	freopen("1058.txt","r",stdin);
	//N为学生人数
	//M为题数
	int N,M;

	scanf("%d %d",&N,&M);
	ANS ans[M];
	char stu_ans[N*6*M+1];
	//读入每题的正确答案
	scanIntoAns(ans,M);
	//清除缓冲区
	scanf("%*c");
	//读入每个人的答案
	scanIntoStuAns(stu_ans,N,M);
	int score[N][M+1];
	for(int i=0; i<N; i++) {
		for(int j=0; j<M+1; j++) {
			score[i][j] = 0;
		}
	}
	for(int i=0; i<N; i++) {
		int index = 0;
		int len = 0;
		int numberOfQuest = 0;
		while(getValue(stu_ans,i,index,6*M) != '\0') {
			len = getValue(stu_ans,i,index,6*M)-'0';
			char buf[len+1];
			for(int j=0; j<len; j++) {
				buf[j] = getValue(stu_ans,i,index,6*M);
			}
			buf[len] = '\0';
			index += len+1;
			if(strcmp(ans[numberOfQuest].op,buf) == 0) {
				score[i][numberOfQuest] = ans[numberOfQuest].score;
			}
			numberOfQuest++;
		}
	}
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			score[i][M] += score[i][j];
		}
	}
	for(int i=0; i<N; i++) {
		printf("%d\n",score[i][M]);
	}
	int ret[M];
	for(int i=0; i<M; i++) {
		ret[i] = 0;
	}
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			if(score[j][i] == 0) {
				ret[i]++;
			}
		}
	}
	int max = -1;
	for(int i=0; i<M; i++) {
		if(max < ret[i]) {
			max = ret[i];
		}
	}
	int maxCnt = 0;
	for(int i=0; i<M; i++) {
		if(ret[i] == max) {
			maxCnt++;
		}
	}
	printf("%d ",max);
	int cnt = 0;
	for(int i=0; i<M; i++) {
		if(ret[i] == max) {
			cnt++;
			if(cnt < maxCnt) {
				printf("%d ",i+1);
			} else if(cnt == maxCnt) {
				printf("%d",i+1);
			}
		} 
	}
	return 0;
}
