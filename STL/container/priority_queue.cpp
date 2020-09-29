#include <iostream>
#include <queue>

using namespace std;

class node {
private:
    string m_msg;
    int m_priority;

public:
    node(string msg, int priority):
        m_msg(msg), m_priority(priority) {}

    const string& get_msg() const { return m_msg; }

    const int get_priority() const { return m_priority; }

    bool operator< (const node& x) const {
        return m_priority > x.m_priority;
    }
};

// bool operator< (const node&a, const node& b)
// {
//     return a.get_priority() > b.get_priority();
// }

// struct cmp {
//     bool operator() (const node& a, const node& b) {
//         return a.get_priority() > b.get_priority();
//     }
// };

int main(int argc, char const *argv[])
{
    int N;

    cin >> N;

    priority_queue<node> q;

    string order, msg;
    int priority;
    // 读入N条指令
    for(int i=0; i<N; i++) {
        // 读入指令
        cin >> order;
        // 如果是PUT
        if(order == "PUT") {
            // 继续读入
            cin >> msg >> priority;
            // 将消息入队
            q.push(node(msg, priority));
        } 
        // 如果是GET
        else if(order == "GET") {
            // 如果信息不存在
            if(q.empty()) {
                cout << "EMPTY QUEUE!" << endl;
            } 
            else {
                // 试图从消息队列终获取优先级最高的消息
                auto ret = q.top();
                q.pop();
                cout << ret.get_msg() << endl;
            }
        }
    }   

    return 0;
}