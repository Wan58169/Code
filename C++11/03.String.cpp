#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* m_data;

public:
    String(const char* s = nullptr) :
        m_data(nullptr) {
        cout << "defalut ctor" << endl;
        // 如果s为空指针，则设置m_data为空
        if (s == nullptr) {
            m_data = new char[1];
            m_data[0] = '\0';
        }
        else {
            m_data = new char[strlen(s) + 1];
            strncpy(m_data, s, strlen(s));
        }
    }

    String(const String& str) :
        m_data(nullptr) {
        cout << "copy ctor" << endl;
        // 如果s的m_data为空指针，则设置m_data为空
        if (str.m_data == nullptr) {
            m_data = new char[1];
            m_data[0] = '\0';
        }
        else {
            m_data = new char[strlen(str.m_data) + 1];
            strncpy(m_data, str.m_data, strlen(str.m_data));
        }
    }

    String(String&& str) noexcept :
        m_data(nullptr) {
        cout << "move ctor" << endl;
        m_data = str.m_data;
        str.m_data = nullptr;
    }

    String& operator= (const String& str) {
        cout << "copy assignment" << endl;
        // 自我检测
        if (this != &str) {
            delete[] m_data;
            m_data = new char[strlen(str.m_data) + 1];
            strncpy(m_data, str.m_data, strlen(str.m_data));
        }
    
        return *this;
    }

    String& operator= (String&& str) noexcept {
        cout << "move assignment" << endl;
        // 自我检测
        if (this != &str) {
            m_data = str.m_data;
            str.m_data = nullptr;
        }
            
        return *this;
    }

    ~String() {
        // 检测
        if (m_data != nullptr) {
            delete[] m_data;
        }
    }

    char* get_c_str() const { return m_data; }
};

ostream& operator<< (ostream& os, const String& str)
{
    os << str.get_c_str();
    return os;
}

int main(int argc, char const* argv[])
{
    String str1("hello");
    String str2(str1);
    String str3 = str2;
    str3 = str1;
    String str4(move(String("world")));


    // cout << str1 << endl;
    // cout << str2 << endl;
    // cout << str3 << endl;
    // cout << str4 << endl;


    return 0;
}