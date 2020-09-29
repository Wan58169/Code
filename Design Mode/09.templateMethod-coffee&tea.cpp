#include <iostream>

using namespace std;

// 饮品类
class Beverage {
public:
    // 煮开水
    void boil_water() {
        cout << "Boiling water..." << endl;
    }

    // 冲泡
    virtual void brew() {}

    // 倒入杯中
    void pour_into_cup() {
        cout << "Pouring into cup..." << endl;
    }

    // 加调料
    virtual void add_condiments() {}

    // 准备饮品
    void prepare_recipe() {
        boil_water();
        brew();
        pour_into_cup();
        add_condiments();
    }
};

// 咖啡类
class Coffee : public Beverage {
public:
    // @override
    void brew() {
        cout << "Coffe brewing..." << endl;
    }

    void add_condiments() {
        cout << "Coffe adding sugar and mike..." << endl;
    }
};

// 茶类
class Tea : public Beverage {
public:
    // @override
    void brew() {
        cout << "Tea brewing..." << endl;
    }

    void add_condiments() {
        cout << "Tea adding lemon..." << endl;
    }
};

int main(int argc, char const *argv[])
{
    Beverage *coffee = new Coffee();
    Beverage *tea = new Tea();

    coffee->prepare_recipe();
    cout << "-------------------" << endl;
    tea->prepare_recipe();
    
    return 0;
}
