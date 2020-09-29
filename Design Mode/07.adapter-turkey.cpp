#include <iostream>

using namespace std;

// Duck类
class Duck {
public:
    Duck() {}
    virtual ~Duck() {}

    virtual void quack() {
        cout << "Duck quack" << endl;
    }

    virtual void fly() {
        cout << "Duck fly" << endl;
    }
};

// Turkey类
class Turkey {
public:
    void gobble() {
        cout << "Turkey gobble" << endl;
    }

    void fly() {
        cout << "Turkey fly" << endl;
    }
};

// 适配器类
class Adapter : public Duck {
private:
    Turkey *m_turkey;

public:
    Adapter(Turkey *turkey):
        m_turkey(turkey) {}
    
    ~Adapter() {}

    // 模仿Duck的quack()行为
    void quack() {
        m_turkey->gobble();
    }

    // 模仿Duck的fly()行为
    void fly() {
        for(int i=0; i<5; i++) {
            m_turkey->fly();
        }
    }
};


int main(int argc, char const *argv[])
{
    // 创建两个小动物
    Duck *duck = new Duck();
    Turkey *turkey = new Turkey();

    // 转换器（适配器，adapter）
    Duck *fakeDuck = new Adapter(turkey);

    // 以假乱真
    fakeDuck->quack();
    fakeDuck->fly();
    
    return 0;
}
