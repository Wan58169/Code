// 给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。
// 输入格式:
// 输入首先给出正整数N（≤10^5）为通话记录条数。随后N行，每行给出一条通话记录。简单起见，
// 这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

// 输出格式:
// 在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，
// 则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

// 输入样例:
// 4
// 13005711862 13588625832
// 13505711862 13088625832
// 13588625832 18087925832
// 15005713862 13588625832

// 输出样例:
// 13588625832 3

#include <iostream>
#include <map>

using namespace std;

// 查找成功 或查找失败需插入
void find_or_insert(map<string, int>& map, string phoneNumber)
{
    // 尝试查找phoneNumber
    auto ite = map.find(phoneNumber);
    // 如果list中存在phoneNumber
    if(ite != map.end()) {
        ite->second++;
    }
    else {
        map.insert(pair<string, int>(phoneNumber, 1));
    }
}

int main(int argc, char const *argv[])
{
    freopen("7.14-data.txt", "r", stdin);

    int N;

    cin >> N;


    map<string, int> map;

    //读入N条数据
    for(int i=0; i<N; i++) {
        string phoneNumber1, phoneNumber2;
        cin >> phoneNumber1 >> phoneNumber2;
        //查找成功 或 查找失败需插入
        find_or_insert(map, phoneNumber1);
        find_or_insert(map, phoneNumber2);
    }

    // 找出电话狂人
    // 让retIte默认指向容器的首元素
    auto retIte = map.begin();
    // 记录狂人有几位
    int cnt = 0;
    // 遍历，找出最大的电话次数
    for(auto ite=map.begin(); ite!=map.end(); ite++) {
        // 如果比retIte值大，则retIte指向新位置
        if(ite->second > retIte->second) {
            retIte = ite;
        }
    }
    // 遍历，计算狂人有几位
    for(auto ite=map.begin(); ite!=map.end(); ite++) {
        // 如果比retIte值大，则retIte指向新位置
        if(ite->second == retIte->second) {
            cnt++;
        }
    }
    //输出结果
    // 如果狂人不止一位
    if(cnt > 1) {
        // 遍历，找出狂人中最小的号码的信息
        auto firstIte = map.begin();
        // 找出狂人中最小的号码
        for(auto ite=map.begin(); ite!=map.end(); ite++) {
            if(ite->second == retIte->second) {
                firstIte = ite;
                break;
            }
        }
        cout << firstIte->first << " " << firstIte->second << " " << cnt << endl;
    } 
    else {
        cout << retIte->first << " " << retIte->second << endl;
    }

    return 0;
}
