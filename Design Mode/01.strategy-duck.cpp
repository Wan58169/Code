#include <iostream>

using namespace std;

// 飞行行为接口
class FlyBehavior {
public:
    virtual void fly()=0;
};

class FlyWithWings : public FlyBehavior {
public:
    void fly() {
        cout << "Fly with wings" << endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() {
        cout << "Fly no way" << endl;
    }
};

// 呱呱叫行为接口
class QuackBehavior {
public:
    virtual void quack()=0;
};

class Quack : public QuackBehavior {
public:
    void quack() {
        cout << "Quack" << endl;
    }
};

class Squeak : public QuackBehavior {
public:
    void quack() {
        cout << "squeak" << endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack() {
        cout << "mutequack" << endl;
    }
};

// 鸭子类
class Duck {
private:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    Duck(FlyBehavior* fb, QuackBehavior* qb):
        flyBehavior(fb), quackBehavior(qb) {}

    virtual ~Duck() {
        delete flyBehavior;
        delete quackBehavior;
    }

    void perform_quack() {
        quackBehavior->quack();
    }

    void perform_fly() {
        flyBehavior->fly();
    }
};

class GreenheadDuck : public Duck {
public:
    GreenheadDuck(FlyBehavior* fb, QuackBehavior* qb): 
        Duck(fb, qb) {}
};

class RedheadDuck : public Duck {
public:
    RedheadDuck(FlyBehavior* fb, QuackBehavior* qb):
        Duck(fb, qb) {}
};

class RubberDuck : public Duck {
public:
    RubberDuck(FlyBehavior* fb, QuackBehavior* qb):
        Duck(fb, qb) {}
};

class WoodDuck : public Duck {
public:
    WoodDuck(FlyBehavior* fb, QuackBehavior* qb):
        Duck(fb, qb) {}
};

int main(int argc, char const* argv[])
{
    // 绿头鸭
    Duck *green = new GreenheadDuck(new FlyWithWings(), new Quack());
    // 红头鸭
    Duck *red = new RedheadDuck(new FlyWithWings(), new Quack());
    // 橡皮鸭
    Duck *rubber = new RubberDuck(new FlyNoWay(), new Squeak());
    // 木头鸭
    Duck *wood = new WoodDuck(new FlyNoWay(), new MuteQuack());

    green->perform_fly();
    green->perform_quack();
    cout << "----------------------------------------" << endl;

    red->perform_fly();
    red->perform_quack();
    cout << "----------------------------------------" << endl;
    
    rubber->perform_fly();
    rubber->perform_quack();
    cout << "----------------------------------------" << endl;
    
    wood->perform_fly();
    wood->perform_quack();
    cout << "----------------------------------------" << endl;
    
    return 0;
}
