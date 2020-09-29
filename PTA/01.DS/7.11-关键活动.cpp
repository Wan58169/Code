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

    bool operator< (const AdjNode& x) const {
        return earliest < x.earliest;
    }
};

//邻接表
class AdjList {
private:
    int m_numV;
    int m_numE;
    vector<AdjNode> m_list;        //正向邻接表
    vector<AdjNode> m_verList;     //逆向邻接表

private:
    //创建adjList
    void __create_adjList() {
        //下标从1开始
        m_list.resize(m_numV + 1);
        //初始化m_list，将每个顶点的firstArc置为nullptr
        for (int i = 1; i <= m_numV; i++) {
            m_list[i].vertex = i;
            m_list[i].inDegree = 0;
            m_list[i].outDegree = 0;
            m_list[i].earliest = 0;
            m_list[i].latest = 0;
            m_list[i].firstArc = nullptr;
        }
    }

    // adjList中插入边 头插法
    void __insert_into_adjList(vector<AdjNode>& list, int src, int dest, int cost) {
        ENode* newENode;
        //创建新节点
        newENode = new ENode;
        newENode->vertex = dest;
        newENode->cost = cost;
        //头插法
        newENode->next = list[src].firstArc;
        list[src].firstArc = newENode;
        //入度加一
        list[dest].inDegree++;
        //出度加一
        list[src].outDegree++;
    }

    void __insert_into_adjList_tail(vector<AdjNode>& list, int src, int dest, int cost) {
        ENode* newENode, *tail;     // 新节点 尾指针
        //创建新节点
        newENode = new ENode;
        newENode->vertex = dest;
        newENode->cost = cost;
        newENode->next = nullptr;
        // cout << newENode->vertex << endl;
        // 尾插法
        // 如果该顶点无邻接点，即表示还没有插入过
        if(list[src].firstArc == nullptr) {
            list[src].firstArc = newENode;
        } 
        // 如果不是第一次插入
        else {
            for(tail=list[src].firstArc; tail->next; tail=tail->next) 
                ;
            tail->next = newENode;
        } 
        //入度加一
        list[dest].inDegree++;
        //出度加一
        list[src].outDegree++;
    }

    void __dfs(int v, vector<bool>& visited) {
        // 先访问该顶点
        visited[v] = true;
        // 尝试访问它的邻接点
        for(ENode *p=m_list[v].firstArc; p; p=p->next) {
            // 如果邻接点没有被访问过，则递归访问
            if(!visited[p->vertex]) {
                __dfs(p->vertex, visited);
            } 
        }
    }

    // 找出入度为0的顶点，并返回其编号
    int __find_inDegree_zero(vector<AdjNode>& list, vector<bool>& visited) {
        // 扫描每个顶点
        for(int i=1; i<=m_numV; i++) {
            // 如果入度为0 & 没有访问过
            if(list[i].inDegree==0 && !visited[i]) {
                visited[i] = true;
                return i;
            }
        }
        return -1;
    }

    // 计算每个顶点的earliest
    void __cal_adjList_earliest() {
        queue<int> startVs;     // 起点队列

        // 选择起点，扫描每个顶点，入度为0的可作为起点
        for(int i=1; i<=m_numV; i++) {
            if(m_list[i].inDegree == 0) {
                startVs.push(i);
            }
        }
        // 依次取出队列中的起点
        while(true) {
            if(startVs.empty()) {
                break;
            }
            // 取出队列中的起点
            int startV = startVs.front();
            startVs.pop();
            // 先前顶点
            int preV;
            // 下一个顶点队列
            queue<int> nextVs;
            nextVs.push(startV);

            while(true) {    
                if(nextVs.empty()) {
                    break;
                }
                // 取出下一个顶点
                preV = nextVs.front();
                nextVs.pop();
                // 更新该点的邻接点
                for(ENode *p=m_list[preV].firstArc; p; p=p->next) {
                    // 计算新值=该点的earliest+邻接点的cost
                    int tmpCost = m_list[preV].earliest+p->cost;
                    // 选择较大的值
                    if(tmpCost > m_list[p->vertex].earliest) {
                        m_list[p->vertex].earliest = tmpCost;
                    }
                    nextVs.push(p->vertex);
                }
            }
        }
        
    }

    //创建逆向adjList
    void __create_verAdjList() {
        // 下标从1开始
        m_verList.resize(m_numV + 1);
        //初始化m_verList，将每个顶点的firstArc置为nullptr
        for (int i = 1; i <= m_numV; i++) {
            m_verList[i].vertex = i;
            m_verList[i].earliest = 0;
            m_verList[i].latest = 1000;
            m_verList[i].firstArc = nullptr;
        }
        // 利用正向邻接表，自动生成逆向邻接表
        for(int i=1; i<=m_numV; i++) {
            for(ENode *p=m_list[i].firstArc; p; p=p->next) {
                // cout << p->vertex << " " << i << " " << p->cost << endl;
                __insert_into_adjList_tail(m_verList, p->vertex, i, p->cost);
            }
        }
    }

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
    void __print_adjNode(const vector<AdjNode>& list, int idx) {
        cout << "[" << list[idx].vertex << ", " << list[idx].inDegree << ", "
         << list[idx].outDegree << ", " << list[idx].earliest << ", " << list[idx].latest <<  "]->";
    }

    //打印顶点的firstArc链接的链表 @test
    void __print_enode(const vector<AdjNode>& list, int idx) {
        //顶点编号 顶点描述 与之的代价
        for(ENode* e = list[idx].firstArc; e; e = e->next) {
            cout << "{" << e->vertex << ", " << e->cost << "} ";
        }
        cout << " " << endl;
    }

public:
    AdjList(int numV, int numE):
        m_numV(numV), m_numE(numE) {
        __create_adjList();
    }

    ~AdjList() {}

    // 返回正向邻接表，不可修改
    const vector<AdjNode>& get_list() const { return m_list; }

    // 返回逆向邻接表，不可修改
    const vector<AdjNode>& get_verList() const { return m_verList; }

    // 返回正向邻接表，可修改
    vector<AdjNode>& get_list_for_modi() { return m_list; }

    // 有向图插边
    void insert_into_dirAdjList(int src, int dest, int cost) {
        __insert_into_adjList(m_list, src, dest, cost);
    }

    // 无向图插边
    void insert_into_adjList(int src, int dest, int cost) {
        __insert_into_adjList(m_list, src, dest, cost);
        __insert_into_adjList(m_list, dest, src, cost);
    }

    // 全图dfs，计算连通集个数
    int dfs() {
        vector<bool> visited(m_numV+1, false);      // 临时向量，标记是否已访问过该顶点，默认没有访问过
        int cnt = 0;        //连通集个数

        //全图dfs
        for(int i=1; i<=m_numV; i++) {
            if(!visited[i]) {
                cnt++;
                __dfs(i, visited);
            }
        }
        // 返回连通集个数
        return cnt;
    }

    // 返回是否有环，true->无环，false->有环
    bool top_sort() {
        int cnt = 0;        // 记录能够通过拓扑排序的顶点个数
        vector<AdjNode> list(m_list);               // copy一份!!!
        vector<bool> visited(m_numV+1, false);      // 临时向量，标记是否已访问过该顶点的入度信息，默认没有访问过

        while(true) {
            int v = __find_inDegree_zero(list, visited);
            // 入度为0的顶点不存在
            if(v == -1) {
                break;
            }
            else {
                // 标记已访问过该顶点的入度信息
                visited[v] = true;
                cnt++;
                // cout << v << " ";
                // 扫描该顶点的邻接点，让邻接点们的入度都减一
                for(ENode *p=list[v].firstArc; p; p=p->next) {
                    list[p->vertex].inDegree--;
                }
            }
        }
        // 返回是否有环
        return cnt==m_numV;
    }

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
    void print_adjList(const vector<AdjNode>& list) {
        for(int i = 1; i <= m_numV; i++) {
            // cout << list[i].firstArc << endl;
            //打印该顶点信息
            __print_adjNode(list, i);
            //打印该顶点的firstArc链接的链表
            __print_enode(list, i);
        }
    }
};

int main(int argc, char const *argv[])
{
    freopen("7.11-data.txt", "r", stdin);

    // 顶点数 边数
    int N, M;

    cin >> N >> M;

    AdjList adjList(N, M);

    //读入M条数据 边的信息
    for(int i=0; i<M; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        adjList.insert_into_dirAdjList(src, dest, cost);
    }

    // 判断是否有回路
    if(!adjList.top_sort()) {
        cout << "0" << endl;
        return 0;
    }

    // 关键路径法
    adjList.critical_path_method();

    

    // 输出关键路径
    adjList.print_critical_path();
    

    // 打印正向adjList @test
    adjList.print_adjList(adjList.get_list());
    cout << "---------------------------" << endl;
    // 打印逆向adjList @test
    adjList.print_adjList(adjList.get_verList());

    return 0;
}
