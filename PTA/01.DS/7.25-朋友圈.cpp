#include <iostream>
#include <vector>

using namespace std;

//定义邻接表结构
//Edge结构
struct ENode {
    int vertex;
    ENode* next;
};

//顶点信息
struct AdjNode {
    int vertex;         //顶点编号
    ENode* firstArc;
};

//邻接表
class AdjList {
private:
    int m_numV;                    //顶点数
    int m_numE;                    //边数
    vector<AdjNode> m_list;        //正向邻接表

private:
    //创建adjList
    void __create_adjList(vector<AdjNode>&);

    //向adjList中插入边，头插法
    void __insert_into_adjList_head(vector<AdjNode>&, int, int, int);

    // 连通子图的dfs
    void __dfs(const vector<AdjNode>&, int v, vector<bool>&) const;

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

    // 返回正向邻接表，可修改
    vector<AdjNode>& get_list_for_modi() { return m_list; }

    // 无向图插边
    void insert_into_unDirAdjList(int src, int dest, int cost);

    // 全图dfs，计算连通集个数
    int dfs(const vector<AdjNode>&) const;

    //打印adjList @test
    void print_adjList(const vector<AdjNode>&) const;
};

int main(int argc, char const *argv[])
{
    //学生总数 俱乐部个数
    int N, M;

    cin >> N >> M;

    

    return 0;
}
