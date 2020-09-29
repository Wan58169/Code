#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_multiset<int> s1;
    unordered_set<int> s2;

    for(int i=0; i<10000; i++) {
        s1.insert(i);
    }
    //返回迭代器
    auto ite = s1.find(8999);

    cout << *ite << endl;
    
    return 0;
}