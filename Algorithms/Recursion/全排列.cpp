#include<iostream>
using namespace std;
//树状图+深搜 
//k为当前位置,与其后面元素交换 
void f(string s,int k) 
{
	if(k == s.length()) {
		cout << s << endl;
		return;
	}
	for(int i=k; i<s.length(); i++) {
		{char tmp =s[k]; s[k] = s[i]; s[i] = tmp;}
		f(s,k+1);
		{char tmp =s[k]; s[k] = s[i]; s[i] = tmp;}
	}
}
int main()
{
	string s;
	
	cin >> s;
	f(s,0);
	return 0;
} 
