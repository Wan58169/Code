#include<iostream>
using namespace std;

void swap(int & a,int & b)
{
    int t;
    t = a,a = b,b = t;
}

void select_sort(int a[],int aLen)
{
    for(int i=0; i<aLen; i++) {
        int min = i;
        for(int j=i; j<aLen; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i],a[min]);
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

    select_sort(a,aLen);
    
    //打印排序好的数组
    for(int i=0; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl; 
    return 0;
}
