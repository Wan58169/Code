#include<iostream>
using namespace std;

void swap(int & a,int & b)
{
    int t;
    t = a,a = b,b = t;
}

void bubble_sort(int a[],int aLen)
{
    for(int i=aLen-1; i>=0; i--) {
        int flag = 0;               //判断序列是否需要再交换
        for(int j=0; j<i; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
                flag = 1;
            }
        }
        //此时数组a已经有序了
        if(flag == 0) break;
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

    bubble_sort(a,aLen);
    
    //打印排序好的数组
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl; 
    return 0;
}
