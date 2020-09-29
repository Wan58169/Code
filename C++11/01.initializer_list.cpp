#include <iostream>

using namespace std;

class P {
public:
    P(int a, int b) {
        cout << "P(int a, int b)" << endl;
    }

    P(initializer_list<int>) {
        cout << "p(initializer_list<int>)" << endl;
    }

    explicit P(int a, int b, int c) {
        cout << "P(int a, int b, int c)" << endl;
    }
};

int main(int argc, char const *argv[])
{
    P p1(1, 2);                     // P(int a, int b)
    P p2 {1, 2};                    // p(initializer_list<int>)
    P p3(1, 2, 3);                  // P(int a, int b, int c)
    P p4 {1, 2, 3};                 // p(initializer_list<int>)
    P p5 = {1, 2, 3};               // p(initializer_list<int>)

    return 0;
}
