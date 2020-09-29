#include<iostream>
using namespace std;

int f(string s1,string s2)
{
	if(s1.length() != s2.length()) {
		return 0;
	}
	if(s1.length() == 0) {
		return 1;
	}
	if(s1[0] == s2[0]) {
		return f(s1.substr(1),s2.substr(1));
	} else {
		return false;
	}
}
int main()
{
	string s1 = "hello";
	string s2 = "hello";
	
	cout << f(s1,s2) << endl;
	return 0;
}
