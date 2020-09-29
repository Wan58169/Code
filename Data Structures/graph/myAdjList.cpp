#include "myAdjList.h"

//创建adjList
void AdjList::__create_adjList(vector<AdjNode>& list) 
{
    //下标从1开始
    list.resize(m_numV + 1);
    //初始化m_list，将每个顶点的firstArc置为nullptr
    for (int i = 1; i <= m_numV; i++) {
        list[i].vertex = i;
        list[i].inDegree = 0;
        list[i].outDegree = 0;
        list[i].earliest = 0;
        list[i].latest = 1000;
        list[i].firstArc = nullptr;
    }
}

//向adjList中插入边，头插法
void AdjList::__insert_into_adjList_head(vector<AdjNode>& list, int src, int dest, int cost)
{
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

// 有向图插边
void AdjList::insert_into_dirAdjList(int src, int dest, int cost)
{
    __insert_into_adjList_head(m_list, src, dest, cost);
}

// 无向图插边
void AdjList::insert_into_unDirAdjList(int src, int dest, int cost)
{
    __insert_into_adjList_head(m_list, src, dest, cost);
    __insert_into_adjList_head(m_list, dest, src, cost);
}

// 形成逆向adjList
void AdjList::__form_verAdjList() 
{
    // 创建m_verList
    __create_adjList(m_verList);
    // 利用正向邻接表，自动生成逆向邻接表
    for(int i=1; i<=m_numV; i++) {
        for(ENode *p=m_list[i].firstArc; p; p=p->next) {
            // cout << p->vertex << " " << i << " " << p->cost << endl;
            __insert_into_adjList_head(m_verList, p->vertex, i, p->cost);
        }
    }
}

//打印adjNode相关信息 @test
void AdjList::__print_adjNode(const vector<AdjNode>& list, int idx) 
{
    cout << "[" << list[idx].vertex << ", " << list[idx].inDegree << ", "
        << list[idx].outDegree << ", " << list[idx].earliest << ", " << list[idx].latest <<  "]->";
}

//打印顶点的firstArc链接的链表 @test
void AdjList::__print_enode(const vector<AdjNode>& list, int idx) 
{
    //顶点编号 顶点描述 与之的代价
    for(ENode* e = list[idx].firstArc; e; e = e->next) {
        cout << "{" << e->vertex << ", " << e->cost << "} ";
    }
    cout << " " << endl;
}

//打印adjList @test
void AdjList::print_adjList(const vector<AdjNode>& list) 
{
    for(int i = 1; i <= m_numV; i++) {
        // cout << list[i].firstArc << endl;
        //打印该顶点信息
        __print_adjNode(list, i);
        //打印该顶点的firstArc链接的链表
        __print_enode(list, i);
    }
}

// 连通子图的dfs
void AdjList::__dfs(const vector<AdjNode>& list, int v, vector<bool>& visited)
{
    // 先访问该顶点
    visited[v] = true;
    // 尝试访问它的邻接点
    for(ENode *p=list[v].firstArc; p; p=p->next) {
        // 如果邻接点没有被访问过，则递归访问
        if(!visited[p->vertex]) {
            __dfs(list, p->vertex, visited);
        } 
    }
}

// 全图dfs，返回连通集个数
int AdjList::dfs(vector<AdjNode>& list) 
{
    // 临时向量，标记是否已访问过该顶点，默认没有访问过
    vector<bool> visited(m_numV+1, false);      
    int cnt = 0;        //连通集个数

    //全图dfs
    for(int i=1; i<=m_numV; i++) {
        if(!visited[i]) {
            cnt++;
            __dfs(list, i, visited);
        }
    }
    // 返回连通集个数
    return cnt;
}

// 找出入度为0的顶点，并返回其编号 only!@top_sort()
static int __find_inDegree_zero(vector<AdjNode>& list, vector<bool>& visited) {
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

// 返回是否有环，true->无环，false->有环
bool AdjList::top_sort(const vector<AdjNode>& list) 
{
    int cnt = 0;        // 记录能够通过拓扑排序的顶点个数
    vector<AdjNode> tmpList(list);               // copy一份!!!
    vector<bool> visited(m_numV+1, false);      // 临时向量，标记是否已访问过该顶点的入度信息，默认没有访问过

    while(true) {
        int v = __find_inDegree_zero(tmpList, visited);
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
            for(ENode *p=tmpList[v].firstArc; p; p=p->next) {
                tmpList[p->vertex].inDegree--;
            }
        }
    }
    // 返回是否有环
    return cnt==m_numV;
}

// 计算每个顶点的earliest
void AdjList::__cal_adjList_earliest() 
{
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

// 关键路径法
void AdjList::critical_path_method() {
    // 生成逆向邻接表
    __form_verAdjList();
    __cal_adjList_earliest();
    __cal_adjList_latest();
}