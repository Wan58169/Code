#include<iostream>
using namespace std;

void swap(int & a,int & b)
{
    int t;
    t = a,a = b,b = t;
}

void shell_sort(int a[],int aLen)
{
    for(int d=aLen/2; d>=1; d/=2) {     //增量变化
        for(int i=d; i<aLen; i++) {     //插入排序
            int tmp = a[i];
            //以d为增量向前寻找空位
            int j;
            for(j=i; tmp<a[j-d] && j>=d; j-=d) {   //错位
                a[j] = a[j-d];
            }
            //新牌落位
            a[j] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {8,9,5,7,4,6,2,1,3};
    int aLen = sizeof(a)/sizeof(a[0]);
    
    //打印待排数组a
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl;
    
    shell_sort(a,aLen);
    
    //打印排序好的数组
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl; 
    return 0;
}
