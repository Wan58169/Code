#include <iostream>
#include <vector>
#include <string>

using namespace std;

// pizza类
class Pizza {
private:
    string m_type;

public:
    Pizza(string type):
        m_type(type) {}

    virtual ~Pizza() {}

    void prepare() {
        cout << "Preparing " + m_type << endl;
    }

    void bake() {
        cout << "baking" << endl;
    }

    void cut() {
        cout << "cutting" << endl;
    }

    void box() {
        cout << "boxing" << endl;
    }
};

// 芝士pizza
class CheesePizza : public Pizza {
public:
    CheesePizza():
        Pizza("cheese") {}
    
    ~CheesePizza() {}
};

// 素食pizza
class VeggiePizza : public Pizza {
public:
    VeggiePizza():
        Pizza("veggie") {}

    ~VeggiePizza() {}
};

// pizaa店类
class PizzaStore {
public:
    void order_pizza(string type) {
        // factory方法
        Pizza *p = create_pizza(type);
        p->prepare();
        p->bake();
        p->cut();
        p->box();
    }

    Pizza *create_pizza(string type) {
        if(type == "cheese") {
            return new CheesePizza();
        } else if(type == "veggie") {
            return new VeggiePizza();
        } else {
            return new Pizza("default");
        }
    }
};

int main()
{
    // 创建pizza店
    PizzaStore *pizzaStore = new PizzaStore();

    // 点餐
    pizzaStore->order_pizza("cheese");
    pizzaStore->order_pizza("veggie");
    pizzaStore->order_pizza("sugar");

    return 0;
}