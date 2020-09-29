#include<iostream>
using namespace std;

void swap(int & a,int & b)
{
    int t;

    t = a,a = b,b = t;
}

void sort(int a[],int aLen)
{
    int i,j;

    i = 0;
    j = aLen-1;
    while(i < j) {
        while(i<j && a[i]<0) {  //定位待交换的i下标
            i++;
        }
        while(i<j && a[j]>0) {  //定位待交换的j下标
            j--;
        }
        swap(a[i],a[j]);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {2,-1,0,-4,-10,6,4,-3,6,5,-2};
	int aLen = sizeof(a)/sizeof(a[0]);

    //打印待排数组a
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl;

    sort(a,aLen);

    //打印排序好的数组
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl; 
    
    return 0;
}
