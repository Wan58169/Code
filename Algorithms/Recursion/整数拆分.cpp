#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
//ÕûÊı²ğ·Ö 
void f(int n) 
{
	//5..f(1)
	//4..f(2)
	if(n == 0) {
		vector<int>::iterator it;
		int cnt = 0;
		for(it=v.begin(); it!=v.end(); it++) {
			cout << *it;
			if(++cnt < v.size()) {
				cout << "+";
			}
		}
		cout << " " << endl;
		return;
	}
	for(int i=n; i>0; i--) {
		if(!v.empty() && i>v.back()) continue;
		v.push_back(i);
		f(n-i);
		v.pop_back();	
	}
}
int main()
{
	f(6);
	return 0;
}
