#include<iostream>
#include "BinTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    BTree *T;

    int idx = 0;
    string s;

	cin >> s;
	T = CreateBTree(s,&idx);

    cout << isCompletedTree(T) << endl;

    return 0;
}
