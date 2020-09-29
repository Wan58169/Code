#include <iostream>
#include <string>

using namespace std;

// 被装饰者类
class Beverage {
private:
    string m_description;

public:
    Beverage() { m_description = "Unknown Beverage"; }

    Beverage(string des) { m_description = des; }

    virtual ~Beverage() {}

    inline
    string get_description() const { return m_description; }

    virtual double cost() {}
};

// HouseBlend被装饰者类
class HouseBlend : public Beverage {
public:
    HouseBlend():
        Beverage("HouseBlend") {}
    
    double cost() { return 0.89; }
};

// 装饰者类
class Decorator : public Beverage {
protected:
    Beverage *m_beverage;

public:
    Decorator() {}

    Decorator(Beverage * b):
        m_beverage(b) {}

    virtual ~Decorator() {}

    virtual double cost() {}
};

// Soy装饰者类
class Soy : public Decorator {
public:
    Soy(Beverage *b):
        Decorator(b) {}
    
    double cost() { return 0.15 + m_beverage->cost(); }
};

// Mocha装饰者类
class Mocha : public Decorator {
public:
    Mocha(Beverage *b):
        Decorator(b) {}
    
    double cost() { return 0.2 + m_beverage->cost(); }
};


int main(int argc, char const *argv[])
{
    Beverage *b = new HouseBlend();
    b = new Soy(b);
    b = new Mocha(b);

    cout << b->cost() << endl;

    return 0;
}
