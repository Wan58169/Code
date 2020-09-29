#include<iostream>
using namespace std;
 
void swap(int & a,int & b)
{
	int t;
	
	t = a,a = b,b = t;
}

void  sort( int r[], int n )  
{
   int i, j, mini, maxi;
   for (i=1; i<n-i+1; i++) {
      mini = maxi = i;
      for( j=i+1; j<=n-i+1; ++j ){
         if( r[j] < r[mini] ) mini = j; 
         else if(r[j] > r[maxi]) maxi = j;
      }
      //如果找到最小的，那就与r[i]交换
	  if( mini!=i ) swap(r[mini], r[i]);
      if( maxi != n-i+1 ){
		 //最大的以被换到r[mini]上
         if( maxi==i ) swap(r[mini], r[n-i+1]);
         else swap(r[maxi], r[n-i+1]);
      }
   }
}

int main()
{
	int a[] = {-1,4,7,1,2,5,3,9,6,10,8};
	int aLen = sizeof(a)/sizeof(a[0]);
	
	cout << "hello" << endl;
	//打印待排数组a
    for(int i=1; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl;

    sort(a,aLen-1);

    //打印排序好的数组
    for(int i=1; i<aLen; i++) {
        cout << a[i] << " ";
    }
    cout << " " << endl; 
	
	return 0;
}
