#include <iostream>
#include <memory>

using namespace std;

class A {
private:
    int m_i;
    int *m_array;

public:
    A() :
        m_i(1),
        m_array(new int[1024]) {
            for(auto i=0; i<1024; i++)
                m_array[i] = 0;
    }

    ~A() { 
        cout << "~A()" << endl; 
        // 需要手动释放基础类型
        delete[] m_array;
    }

    int getI() { return m_i; }

};

A* get_A()
{
    return new A;
}

void g(A* a)
{
    cout << a->getI() << endl;
}

void f()
{
    auto_ptr<A> pt(get_A());
    // shared_ptr<A> pt(get_A());

    // 通过get()方法来获取auto_ptr里的对象
    g(pt.get());
}


int main()
{
    f();

    return 0;
}