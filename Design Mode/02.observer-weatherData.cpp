#include <iostream>
#include <vector>
using namespace std;

// 观察者类接口
class Observer {
public:
    virtual void update()=0;
};

// 主题类接口
class Subject {
public:
    virtual void register_observer(Observer*)=0;
    virtual bool remove_observer(Observer*)=0;
    virtual void notify_observers()=0;
};

// 天气数据类
class WeatherData : public Subject {
private:
    float m_temperature;
    float m_humidity;
    float m_pressure;
    vector<Observer* > m_vct;

public:
    void register_observer(Observer *o) {
        m_vct.push_back(o);
    }

    bool remove_observer(Observer *o) {
        // 遍历vector
        for(auto ite = m_vct.begin(); ite!=m_vct.end(); ite++) {
            if((*ite) == o) {
                m_vct.erase(ite);
                return true;
            }
        }
        return false;
    }

    void notify_observers() {
        // 遍历vector
        for(auto ite = m_vct.begin(); ite!=m_vct.end(); ite++) {
            (*ite)->update();
        }
    }

    void set_measurements(float t, float h, float p) {
        m_temperature = t;
        m_humidity = h;
        m_pressure = p;
        notify_observers();
    }
};

// 近况公示牌
class CurrentConditionsDisplay : public Observer {
private:
    WeatherData *m_wd;

public:
    CurrentConditionsDisplay(WeatherData *wd):
        m_wd(wd) {
        m_wd->register_observer(this);
    }

    void update() {
        cout << "I'm currentConditions ready. I'm watching " << m_wd << endl;
    }
};

// 预测公示牌
class ForecastDisplay : public Observer {
private:
    WeatherData *m_wd;

public:
    ForecastDisplay(WeatherData *wd):
        m_wd(wd) {
        m_wd->register_observer(this);
    }

    void update() {
        cout << "I'm forecastDisplay ready. I'm watching " << m_wd << endl;
    }
};

int main()
{
    WeatherData *wd = new WeatherData();
    CurrentConditionsDisplay *cd = new CurrentConditionsDisplay(wd);
    ForecastDisplay *fd = new ForecastDisplay(wd);

    wd->set_measurements(1.01, 2.02, 3.03);
    // 删除ForecastDisplay
    wd->remove_observer(fd);
    
    wd->set_measurements(1, 1, 1);

    return 0;
}