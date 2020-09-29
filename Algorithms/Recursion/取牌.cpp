#include <iostream>

using namespace std;

//a[]：小明手中的13张牌
//beginIndex：小明手中的几号位置
//n：13
int f(int a[], int beginIndex, int n)
{

  for (int i = 1; i <= 13; i++)
  {
    a[beginIndex] = i;
    f(a,beginIndex+1,n);
    
  }
}

int main(int argc, char const *argv[])
{
  int a[14] = {0};

  int ans = f(a, 0, 13);

  cout << ans << endl;

  return 0;
}
