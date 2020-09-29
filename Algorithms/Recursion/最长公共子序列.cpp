#include<iostream>
#include<math.h>
using namespace std;

int f(string s1,string s2)
{
	if(s1.length()==0 || s2.length()==0) {
		return 0;
	}
	if(s1[0] == s2[0]) {
		return f(s1.substr(1),s2.substr(1))+1;
	} else {
		return max(f(s1,s2.substr(1)),f(s1.substr(1),s2));
	}
}
int main()
{
	cout << f("abced","bef") << endl;
	return 0;
}
