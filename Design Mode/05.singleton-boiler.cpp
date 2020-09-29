#include <iostream>

using namespace std;

// 单件类
class Singleton {
private:
    static Singleton *m_s;

    Singleton() {}
    
    ~Singleton() {}
                                                    
public:
    static Singleton* get_instance() {
        if(m_s == NULL) {
            m_s = new Singleton();
        }
        cout << Singleton::m_s << endl;
        return m_s;
    }

    static void release_instance() {
        if(m_s != NULL) {
            cout << Singleton::m_s << " release" << endl;
            delete m_s;
            m_s = NULL;  
        }
    }
};

// 在用单件类之前必须初始化static成员变量
Singleton* Singleton::m_s = NULL;

int main(int argc, char const *argv[])
{
    Singleton *s = Singleton::get_instance();
    Singleton *s2 = Singleton::get_instance();

    Singleton::release_instance();

    return 0;
}
