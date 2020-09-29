#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

//µÝ¹é 
// 10*9*8*7...
int f(int n)
{
	if(n == 1) {
		return 1;
	}
	return n*f(n-1);
}
//Ä£ÄâµÝ¹é ÈË¹¤Õ» 
int f_loop(int n)
{
	int ret;
	bool isOver = false;
	
	do {
		if(isOver == false) {
			if(n == 1) {
				isOver = true;
				ret = 1;
			}
			s.push(n);
			n--;
		} else {
			ret *= s.top();
			s.pop();
		}
	}while(!s.empty());
	return ret;
}
int main()
{
	int n = 16;
	
	cout << f(n) << endl;
	cout << f_loop(n) << endl; 
	return 0;
}
