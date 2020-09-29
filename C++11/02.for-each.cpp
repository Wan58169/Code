#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vct {1, 2, 3, 4, 5};

    // copy
    for(auto i : vct) {
        cout << i << " ";
    }
    cout << " " << endl;

    // reference
    for(auto& i : vct) {
        cout << i << " ";
        i *= 2;
    }
    cout << " " << endl;

    // traversal
    for(const auto& i : vct) {
        cout << i << " ";
    }
    cout << " " << endl;

    return 0;
}
