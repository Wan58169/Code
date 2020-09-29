// 给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。
// 输入格式:
// 输入首先给出正整数N（≤10^5）即员工总人数；随后给出N个整数，即每个员工的工龄，范围在[0, 50]。

// 输出格式:
// 按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。
// 输入样例:
// 8
// 10 2 0 5 7 2 5 2

// 输出样例:
// 0:1
// 2:3
// 5:2
// 7:1
// 10:1

#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("7.13-data.txt", "r", stdin);

    int N;

    cin >> N;

    map<int, int> map;

    // 读入N条数据
    for(int i=0; i<N; i++) {
        int age;
        cin >> age;
        // 尝试插入
        auto retPair = map.insert(pair<int, int>(age, 1));
        // 插入失败
        if(!retPair.second) {
            // 获得插入失败位置的Ite
            auto tmpIte = retPair.first;
            // 让该Ite的val++
            tmpIte->second++;
        } 
    }    

    //输出
    for(const auto& v : map) {
        cout << v.first << ":" << v.second << endl;
    }

    return 0;
}
