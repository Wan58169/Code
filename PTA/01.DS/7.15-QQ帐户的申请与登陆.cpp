#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("7.15-data.txt", "r", stdin);
    int N;

    cin >> N;

    // 二叉搜索树
    map<string, string> map;

    // 读入N条指令
    for(int i=0; i<N; i++) {
        char order;
        string account;
        string passwd;
        // 读取指令 账号 密码
        cin >> order >> account >> passwd;

        // 如果是创建账号
        if(order == 'N') {
            // 尝试插入
            auto retIte = map.insert(pair<string, string>(account, passwd));    
            // 插入成功，即该账号是第一次出现
            if(retIte.second) {
                cout << "New: OK" << endl;
            }
            // 插入失败，即已经存在该账号
            else {
                cout << "ERROR: Exist" << endl;
            }
        }
        // 如果是登录账号
        else if(order == 'L') {
            // 尝试查找
            auto retIte = map.find(account);
            // 如果该账号存在  
            if(retIte != map.end()) {
                // 密码也正确
                if(retIte->second == passwd) {
                    cout << "Login: OK" << endl;
                } 
                // 密码不正确
                else {
                    cout << "ERROR: Wrong PW" << endl;
                }
            } 
            // 该账号不存在
            else {
                cout << "ERROR: Not Exist" << endl;
            }
        }
    }

    return 0;
}
