/*
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。
最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3

输出样例:
24 23 10
46 23 10
26 10
*/

#include <stdio.h>
#include <stdlib.h>

//定义小根堆
typedef struct Node {
    int *array;
    int size; 
    int capacity;
}MinHeap;

MinHeap *init_MinHeap(int capacity)
{
    MinHeap *mp = (MinHeap *)malloc(sizeof(struct Node));

    mp->array = (int *)malloc(capacity*sizeof(int));
    mp->size = 0;
    mp->capacity = capacity;
    mp->array[0] = -10000;

    return mp;
}

void insert_MinHeap(MinHeap *mp, int x)
{
    int i;

    i = ++mp->size;
    for(; mp->array[i/2] > x; i/=2) 
        mp->array[i] = mp->array[i/2];
    mp->array[i] = x;
}

int pop_MinHeap(MinHeap *mp)
{
    int parent,child;
	int minCell,tmpCell;

	minCell = mp->array[1];
	tmpCell = mp->array[mp->size--];
	
	for(parent=1; parent*2<=mp->size; parent=child) {
		child = parent*2;
        //选择最小的孩子
		if(child!=mp->size && mp->array[child+1]<mp->array[child])
			child++;
		if(tmpCell < mp->array[child]) break;
		else 
			mp->array[parent] = mp->array[child];
	}
	mp->array[parent] = tmpCell;

    return minCell;
}

int main()
{
    int n,m;

    scanf("%d %d", &n, &m);
    MinHeap *mp = init_MinHeap(n);
    int path[m];

    //依次插入数据
    for(int i=1; i<=n; i++) {
        int x;
        scanf("%d", &x);
        insert_MinHeap(mp, x);
    }

    //记录待查找的下标
    for(int i=0; i<m; i++) {
        scanf("%d", &path[i]);
    }

    //输出路径
    for(int i=0; i<m; i++) {
        int idx = path[i];
        while(1) {
            if(idx != 1) {
                printf("%d ", mp->array[idx]);
            } else {
                printf("%d", mp->array[1]);
                break;
            }
            idx /= 2;
        }
        printf("\n");
    }
    
    return 0;
}