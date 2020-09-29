/*
“最大子列和”则被定义为所有连续子列元素的和中最大者。
例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
现要求你编写程序，计算给定整数序列的最大子列和。

输入格式:
输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。

输出格式:
在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:
6
-2 11 -4 13 -5 -2
    
输出样例:
20
*/


// 二重循环
#include<stdio.h>
#include<stdlib.h>

int findMax(int a[], int aLen)
{
    int max = a[0];

    for(int i=0; i<aLen; i++) {
        if(max < a[i]) {
            max = a[i];
        }
    }

    return max;
}

void max_Seq_sum(int a[], int ret[], int N) 
{
    for(int i=0; i<N; i++) {
        int sum = 0;
        int max = a[i];
        for(int j=i; j<N; j++) {
            sum += a[j];
            if(sum > max) {
                max = sum;
            }
        }
        ret[i] = max;
    }
}

int main()
{
    freopen("7.1-最大子列和问题.txt", "r", stdin);
    int N;
    int *a, *ret;

    scanf("%d", &N);
    a = (int *)malloc(sizeof(int)*N);
    ret = (int *)malloc(sizeof(int)*N);

    for(int i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }

    max_Seq_sum(a, ret, N);

    printf("%d", findMax(ret, N));

    return 0;
}

//在线处理
// #include<stdio.h>
// #include<stdlib.h>

// int max_Seq_sum(int a[], int aLen)
// {
//     int seqSum, maxSum;

//     seqSum = maxSum = 0;
//     for(int i=0; i<aLen; i++) {
//         seqSum += a[i];
//         if(seqSum > maxSum) {
//             maxSum = seqSum;
//         } else if(seqSum < 0) {
//             seqSum = 0;
//         }
//     }

//     return maxSum;
// }

// int main()
// {
//     freopen("7.1-最大子列和问题.txt", "r", stdin);
//     int N;
//     int *a;

//     scanf("%d", &N);
//     a = (int *)malloc(sizeof(int)*N);

//     for(int i=0; i<N; i++) {
//         scanf("%d", &a[i]);
//     }

//     printf("%d", max_Seq_sum(a, N));

//     return 0;
// }