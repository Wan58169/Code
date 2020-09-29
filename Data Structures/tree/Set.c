#include<stdio.h>

typedef int ElementType;

typedef struct {
	ElementType data;
	int parent;
}SetType;

//找集合的根
int find(SetType s[],int size,ElementType x)
{
	int i;

	for(i=0; i<size && s[i].data!=x; i++);
	if(i >= size) return -1;
	for(; s[i].parent >= 0; i = s[i].parent);
	return i;
}

//两不同集合合并
void merge(SetType s[],int size,ElementType x1,ElementType x2)
{
	int root1,root2;

	root1 = find(s,size,x1);
	root2 = find(s,size,x2);
	if(root1 == root2)	return;
	else {
		if(s[root1].parent <= s[root2].parent) {
			s[root1].parent += s[root2].parent;
			s[root2].parent = root1;
		} else if(s[root1].parent > s[root2].parent) {
			s[root2].parent += s[root1].parent;
			s[root1].parent = root2;
		} 
	}
}

int main()
{
	freopen("Set.txt","r",stdin);
	int n;
	
	scanf("%d",&n);
	SetType s[n];
	for(int i=0; i<n; i++) {
		scanf("%d",&s[i].data);
		s[i].parent = -1;
	}
	int x1,x2;
	scanf("%d %d",&x1,&x2);
	while(x1!=-1 || x2!=-1) {
		merge(s,n,x1,x2);
		scanf("%d %d",&x1,&x2);
	}	
	merge(s,n,2,5);
	for(int i=0; i<n; i++) 
		printf("%d|%2d %2d\n",i,s[i].data,s[i].parent);

	return 0;
}




















