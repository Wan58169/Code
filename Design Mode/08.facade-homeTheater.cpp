#include <iostream>
#include <string>
using namespace std;

// movie类
class Movie {
private:
    string m_moiveName;

public:
    Movie(string movieName):
        m_moiveName(movieName) {}

    ~Movie() {}

    string get_movie_name() const {
        return m_moiveName;
    }
};

// dvd类
class Dvd {
private:
    Movie *m_movie;

public:
    Dvd(Movie *movie):
        m_movie(movie) {}
    
    ~Dvd() {}

    void on() {
        cout << "dvd on " << "... " << m_movie->get_movie_name() << endl;
    }

    void off() {
        cout << m_movie->get_movie_name() << " ...dvd off" << endl;
    }
};

// 幕布类
class Screen {
public:
    void down() {
        cout << "screen down" << endl;
    }

    void up() {
        cout << "screen up" << endl;
    }
};

// 投影仪类
class Projector {
public:
    void on() {
        cout << "projector on" << endl;
    }

    void off() {
        cout << "projector off" << endl;
    }
};

// 家庭电影院类
class HomeTheater {
private:
    Dvd *m_dvd;
    Screen *m_screen;
    Projector *m_projector;

public:
    HomeTheater(Dvd *dvd, Screen *screen, Projector *projector):
        m_dvd(dvd), m_screen(screen), m_projector(projector) {}

    ~HomeTheater() {}

    // 外观模式的核心方法 多个方法封装成一个方法
    // 开始
    void watch_movie() {
        m_screen->down();
        m_projector->on();
        m_dvd->on();
    }

    // 结束
    void end_movie() {
        m_dvd->off();
        m_projector->off();
        m_screen->up();
    }
};

int main(int argc, char const *argv[])
{
    // 电影：虎胆龙威
    Movie *movie = new Movie("Die hard");
    // 创建Dvd对象
    Dvd *dvd = new Dvd(movie);
    // 创建幕布对象
    Screen *screen = new Screen();
    // 创建投影仪对象
    Projector *projector = new Projector();
    // 创建家庭电影院对象
    HomeTheater *homeTheater = new HomeTheater(dvd, screen, projector);

    homeTheater->watch_movie();
    cout << "---------------------" << endl;
    homeTheater->end_movie();
    
    return 0;
}
