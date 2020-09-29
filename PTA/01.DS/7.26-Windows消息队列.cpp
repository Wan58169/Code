// 消息队列是Windows系统的基础。对于每个进程，系统维护一个消息队列。如果在进程中有特定事件发生，
// 如点击鼠标、文字改变等，系统将把这个消息加到队列当中。同时，如果队列不是空的，这一进程循环地从队列中按照优先级获取消息。
// 请注意优先级值低意味着优先级高。请编辑程序模拟消息队列，将消息加到队列中以及从队列中获取消息。

// 输入格式:
// 输入首先给出正整数N（≤10^5），随后N行，每行给出一个指令——GET或PUT，分别表示从队列中取出消息或将消息添加到队列中。
// 如果指令是PUT，后面就有一个消息名称、以及一个正整数表示消息的优先级，此数越小表示优先级越高。消息名称是长度不超过10个字符且不含空格的字符串；题目保证队列中消息的优先级无重复，且输入至少有一个GET。

// 输出格式:
// 对于每个GET指令，在一行中输出消息队列中优先级最高的消息的名称和参数。如果消息队列中没有消息，输出EMPTY QUEUE!。对于PUT指令则没有输出。

// 输入样例:
// 9
// PUT msg1 5
// PUT msg2 4
// GET
// PUT msg3 2
// PUT msg4 4
// GET
// GET
// GET
// GET

// 输出样例:
// msg2
// msg3
// msg4
// msg1
// EMPTY QUEUE!

// #include <iostream>
// #include <map>

// using namespace std;


// int main(int argc, char const *argv[])
// {
//     freopen("7.26-data.txt", "r", stdin);

//     int N;

//     cin >> N;

//     map<int, string> map;

//     // 读入N条指令
//     for(int i=0; i<N; i++) {
//         string order, msg;
//         int priority;
//         // 读入指令
//         cin >> order;
//         // 如果是PUT
//         if(order == "PUT") {
//             // 继续读入
//             cin >> msg >> priority;
//             // 将消息入队
//             map.insert(pair<int, string>(priority, msg));
//         } 
//         // 如果是GET
//         else if(order == "GET") {
//             // 如果信息不存在
//             if(map.empty()) {
//                 cout << "EMPTY QUEUE!" << endl;
//             } 
//             else {
//                 // 试图从消息队列终获取优先级最高的消息
//                 auto retIte = map.begin();
//                 cout << retIte->second << endl;
//                 map.erase(retIte);
//             }
//         }
//     }   

//     return 0;
// }

#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

struct node {
    string m_msg;
    int m_priority;

    node(string msg, int priority):
        m_msg(msg), m_priority(priority) {
            // cout << "default ctor" << endl;
    }

    node(const node& x):
        m_msg(x.m_msg), m_priority(x.m_priority) {
            // cout << "copy ctor" << endl;
    }

    node(node&& x) noexcept :
        m_msg(x.m_msg), m_priority(x.m_priority) {
            // cout << "move ctor" << endl;
            // m_msg.assign(move(x.m_msg));
    }

    node& operator= (const node& x) {
    }

    node& operator= (node&& x) noexcept {
        m_msg.assign(move(x.m_msg));
    }

    bool operator< (const node& x) const {
        return m_priority > x.m_priority;
    }
};

int main(int argc, char const *argv[])
{
    // freopen("7.26-data.txt", "r", stdin);
    
    // int N;

    // cin >> N;

    // priority_queue<node> q;

    // string order, msg;
    // int priority;
    // // 读入N条指令
    // for(int i=0; i<N; i++) {
    //     // 读入指令
    //     cin >> order;
    //     // 如果是PUT
    //     if(order == "PUT") {
    //         // 继续读入
    //         cin >> msg >> priority;
    //         // 将消息入队
    //         q.push(node(msg, priority));
    //     } 
    //     // 如果是GET
    //     else if(order == "GET") {
    //         // 如果信息不存在
    //         if(q.empty()) {
    //             // cout << "EMPTY QUEUE!" << endl;
    //         } 
    //         else {
    //             // 试图从消息队列终获取优先级最高的消息
    //             auto ret = q.top();
    //             q.pop();
    //             // cout << ret.m_msg << endl;
    //         }
    //     }
    // }   

    clock_t start, end;

    start = clock();

    priority_queue<node> q;

    for(int i=0; i<20000000; i++) {
        q.push(node("msg", rand()));
    }

    while(!q.empty()) {
        q.pop();
    }
   

    end = clock();
    cout << (end-start) / CLK_TCK << endl;

    return 0;
}

