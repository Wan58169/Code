#ifndef __MYADJLIST_H__
#define __MYADJLIST_H__

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//定义邻接表结构
//Edge结构
struct ENode {
    int vertex;
    int cost;
    ENode* next;
};

//顶点信息
struct AdjNode {
    int vertex;         //顶点编号
    int inDegree;       //入度
    int outDegree;      //出度
    int earliest;       //最早开始时间
    int latest;         //最晚开始时间
    ENode* firstArc;
};

//邻接表
class AdjList {
private:
    int m_numV;                    //顶点数
    int m_numE;                    //边数
    vector<AdjNode> m_list;        //正向邻接表
    vector<AdjNode> m_verList;     //逆向邻接表

private:
    //创建adjList
    void __create_adjList(vector<AdjNode>&);

    //向adjList中插入边，头插法
    void __insert_into_adjList_head(vector<AdjNode>&, int, int, int);

    // 连通子图的dfs
    void __dfs(const vector<AdjNode>&, int v, vector<bool>&) const;

    // 形成逆向adjList
    void __form_verAdjList();

    // 计算每个顶点的earliest
    void __cal_adjList_earliest();

    // 计算每个顶点的latest
    void __cal_adjList_latest() {
        queue<int> endVs;   // 终点队列

        int maxPeriod = -1; // 最长周期
        int maxPeriodIdx;
        // 选择终点，扫描每个顶点，出度为0的可作为终点
        for(int i=1; i<=m_numV; i++) {
            if(m_list[i].outDegree == 0) {
                endVs.push(i);
                // 设置终点的latest
                m_verList[i].latest = m_list[i].earliest;
                if(maxPeriod < m_list[i].earliest) {
                    maxPeriod = m_list[i].earliest;
                    maxPeriodIdx = i;
                }
            }
        } 
        cout << maxPeriod << endl;
        // 依次取出队列中的终点
        while(true) {
            if(endVs.empty()) {
                break;
            }
            // 取出终点
            int endV = endVs.front();
            endVs.pop();
            // 先前顶点
            int preV;
            // 下一个顶点队列
            queue<int> nextVs;
            nextVs.push(endV);

            while(true) {    
                if(nextVs.empty()) {
                    break;
                }
                // 取出下一个顶点
                preV = nextVs.front();
                nextVs.pop();
                // 进行邻接点更新
                for(ENode *p=m_verList[preV].firstArc; p; p=p->next) {
                    int tmpLatest = m_verList[preV].latest - p->cost;
                    // 选择较小的值
                    if(tmpLatest < m_verList[p->vertex].latest) {
                        m_verList[p->vertex].latest = tmpLatest;
                    }
                    nextVs.push(p->vertex);
                }
            }
        }
    }

    //打印adjNode相关信息 @test
    void __print_adjNode(const vector<AdjNode>&, int) const;

    //打印顶点的firstArc链接的链表 @test
    void __print_enode(const vector<AdjNode>&, int) const;

public:
    AdjList(int numV, int numE):
        m_numV(numV), m_numE(numE) {
        __create_adjList(m_list);
    }

    ~AdjList() {}

    // 返回正向邻接表，不可修改
    const vector<AdjNode>& get_list() const { return m_list; }

    // 返回逆向邻接表，不可修改
    const vector<AdjNode>& get_verList() const { return m_verList; }

    // 返回正向邻接表，可修改
    vector<AdjNode>& get_list_for_modi() { return m_list; }

    // 有向图插边
    void insert_into_dirAdjList(int src, int dest, int cost);

    // 无向图插边
    void insert_into_unDirAdjList(int src, int dest, int cost);

    // 全图dfs，计算连通集个数
    int dfs(const vector<AdjNode>&) const;

    // 返回是否有环，true->无环，false->有环
    bool top_sort(const vector<AdjNode>&) const;

    // 关键路径法
    void critical_path_method() {
        // 创建逆向邻接表
        __create_verAdjList();
        __cal_adjList_earliest();
        __cal_adjList_latest();
    }

    // 输出关键路径
    void print_critical_path() {
        // 扫描所有顶点，判断该点是否为关键活动
        for(int i=1; i<=m_numV; i++) {
            // 如果该顶点不是关键活动，则跳过该点
            if(m_list[m_verList[i].vertex].earliest != m_verList[i].latest) {
                continue;
            }
            // 如果该顶点是关键活动，则访问其邻接点
            else {
                for(ENode *p=m_list[m_verList[i].vertex].firstArc; p; p=p->next) {
                    // 如果该邻接点是关键活动
                    if(m_list[p->vertex].earliest == m_verList[p->vertex].latest) {
                        cout << i << "->" << p->vertex << endl;
                    }
                }
            }
        }
    }

    //打印adjList @test
    void print_adjList(const vector<AdjNode>&) const;
};

#endif
