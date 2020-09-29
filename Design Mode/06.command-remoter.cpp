#include <iostream>
#include <vector>

using namespace std;

// 命令接口
class Command {
public:
    Command() {}
    virtual ~Command() {}
    virtual void execute()=0;
};

// 灯类
class Light {
public:
    Light() {}
    
    ~Light() {}

    void on() {
        cout << "Light is on" << endl;
    }

    void off() {
        cout << "Light is off" << endl;
    }
};

// 关灯命令类
class LightOffCommand : public Command {
private:
    Light *m_light;

public:
    LightOffCommand(Light *light):
        m_light(light) {}

    ~LightOffCommand() {}

    void execute() {
        m_light->off();
    }
};

// 开灯命令类
class LightOnCommand : public Command {
private:
    Light *m_light;

public:
    LightOnCommand(Light *light):
        m_light(light) {}

    ~LightOnCommand() {}

    void execute() {
        m_light->on();
    }
};

// 音响类
class Stereo {
public:
    Stereo() {}
    
    ~Stereo() {}
    
    void on() {
        cout << "Stereo is on" << endl;
    }

    void off() {
        cout << "Stereo is off" << endl;
    }
};

// 关音响命令类
class StereoOffCommand : public Command {
private:
    Stereo *m_stereo;

public:
    StereoOffCommand(Stereo *stereo):
        m_stereo(stereo) {}

    ~StereoOffCommand() {}

    void execute() {
        m_stereo->off();
    }
};

// 开音响命令类
class StereoOnCommand : public Command {
private:
    Stereo *m_stereo;

public:
    StereoOnCommand(Stereo *stereo):
        m_stereo(stereo) {}

    ~StereoOnCommand() {}

    void execute() {
        m_stereo->on();
    }
};

// 遥控器类
class Remoter {
private:
    Command* m_onArray[7];
    Command* m_offArray[7];

public:
    Remoter() {
        // 让Command列表中的对象都指向NULL
        for(int i=0; i<sizeof(m_onArray)/sizeof(Command*); i++) {
            m_onArray[i] = NULL;
            m_offArray[i] = NULL;
        }
    }

    ~Remoter() {}

    void add_command(int idx, Command *on, Command *off) {
        m_onArray[idx] = on;
        m_offArray[idx] = off;
        cout << "add successfully" << endl;
    }

    void remove_command(int idx) {
        m_onArray[idx] = NULL;
        m_offArray[idx] = NULL;
    }
    
    void button_on(int idx) {
        if(m_onArray[idx] != NULL) {
            m_onArray[idx]->execute();
        } else {
            cout << "this idx isn't exist" << endl;
        }
    }

    void button_off(int idx) {
        if(m_offArray[idx] != NULL) {
            m_offArray[idx]->execute();
        } else {
            cout << "this idx isn't exist" << endl;
        }
    }
};

int main()
{
    // 遥控器对象
    Remoter *r = new Remoter();

    // 灯对象和音响对象
    Light *light = new Light();
    Stereo *stereo = new Stereo();

    // 灯控制器
    LightOnCommand *lightOnCommand = new LightOnCommand(light);
    LightOffCommand *lightOffCommand = new LightOffCommand(light);

    // 音响控制器
    StereoOnCommand *stereoOnCommand = new StereoOnCommand(stereo);
    StereoOffCommand *stereoOffCommand = new StereoOffCommand(stereo);

    // 嵌入到遥控器中
    r->add_command(0, lightOnCommand, lightOffCommand);
    r->add_command(1, stereoOnCommand, stereoOffCommand);

    // 按有效位置的按钮
    r->button_on(0);
    r->button_on(1);
    // 按无效位置的按钮
    r->button_on(3);
    // 移除0号位置的控制器
    r->remove_command(0);
    r->button_on(0);
    
    return 0;
}