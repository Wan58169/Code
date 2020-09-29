#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//地图信息
struct Node {
    char key;                       //墙 or 路
    pair<int, int> point;           //坐标
    bool isVisited;                 //标记是否已访问过
    int g, h, f;                    //g:已走的距离 h:该点到终点的距离 f:g+h
    pair<int, int> parentPoint;     //父顶点坐标
};

//根据行列来初始化map
void _init_map(vector<vector<Node> >& map, int N, int M)
{
    //固定行 
    map.resize(N);
    //固定列
    for (auto ite = map.begin(); ite != map.end(); ite++) {
        ite->resize(M);
    }
}

//读入map信息
void _scan_into_map(vector<vector<Node> >& map)
{
    //迭代器遍历二维向量
    int row = 0, col = 0;
    for (auto rowIte = map.begin(); rowIte != map.end(); rowIte++, row++) {
        for (auto colIte = rowIte->begin(); colIte != rowIte->end(); colIte++, col++) {
            //读入顶点标识
            cin >> colIte->key;
            //一视同仁操作
            colIte->point = move(pair<int, int>(row, col));
            colIte->isVisited = false;
            colIte->g = 0;
            colIte->h = colIte->f = INT_MAX;
        }
        //一行到头，置0
        col = 0;
    }
}

//找出起点 终点
void _find_src_and_dest(const vector<vector<Node> >& map, pair<int, int>& src, pair<int, int>& dest)
{
    //迭代器遍历二维向量
    for (auto rowIte = map.begin(); rowIte != map.end(); rowIte++) {
        for (auto colIte = rowIte->begin(); colIte != rowIte->end(); colIte++) {
            //如果是源点
            if (colIte->key == 'S') {
                src = colIte->point;
            }
            //如果是终点
            else if (colIte->key == 'D') {
                dest = colIte->point;
            }
        }
    }
}

//创建map
void create_map(vector<vector<Node> >& map, int N, int M, pair<int, int>& src, pair<int, int>& dest)
{
    //根据行列来初始化map
    _init_map(map, N, M);
    //读入map信息
    _scan_into_map(map);
    //找出起点 终点
    _find_src_and_dest(map, src, dest);
}

//判断坐标是否合法
bool _is_legal_point(const vector<vector<Node> >& map, const pair<int, int>& point)
{
    //顶点的x 和 y是否合法
    return point.first >= 0 && point.first < map.capacity() &&
        point.second >= 0 && point.second < map.begin()->capacity();
}

//判断是否为墙
bool _is_wall(const vector<vector<Node> >& map, const pair<int, int>& point)
{
    return (map[point.first][point.second].key == 'W') ? true : false;
}

//判断是否为起点
bool _is_src(const vector<vector<Node> >& map, const pair<int, int>& point)
{
    return (map[point.first][point.second].key == 'S') ? true : false;
}

//判断是否为终点
bool _is_dest(const vector<vector<Node> >& map, const pair<int, int>& point)
{
    return (map[point.first][point.second].key == 'D') ? true : false;
}

//判断是否已访问
bool _is_visited(const vector<vector<Node> >& map, const pair<int, int>& point)
{
    return map[point.first][point.second].isVisited;
}

//计算该点的g值
int _cal_g(const vector<vector<Node> >& map, const pair<int, int>& point)
{
    //拿到父顶点
    pair<int, int> parentPoint = map[point.first][point.second].parentPoint;

    return map[parentPoint.first][parentPoint.second].g + 1;
}

//计算该点到终点的距离h 曼哈顿距离
int _cal_h(const pair<int, int>& src, const pair<int, int>& dest)
{
    return abs(src.first - dest.first) + abs(src.second - dest.second);
}

//计算该点的f值
int _cal_f(const vector<vector<Node> >& map, const pair<int, int>& point, const pair<int, int>& dest)
{
    return _cal_g(map, point) + _cal_h(point, dest);
}

//小根堆的cmp
struct cmp {
    bool operator() (const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};

void a_star(vector<vector<Node> >& map, const pair<int, int>& src, const pair<int, int>& dest)
{
    //小根堆 压入顶点编号和该点的f值
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> q;
    q.push(pair<pair<int, int>, int>(src, 0));

    while (!q.empty()) {
        pair<pair<int, int>, int> v = q.top();
        q.pop();
        //拆分v，拿出v的坐标信息
        pair<int, int> point = v.first;

        //访问该顶点
        map[point.first][point.second].key = '-';
        map[point.first][point.second].isVisited = true;

        //上下左右的走法
        int movX[] = { -1, 1, 0, 0 };
        int movY[] = { 0, 0, -1, 1 };
        //更新上下左右
        for (int i = 0; i < 4; i++) {
            //下一步坐标
            pair<int, int> nextPoint(point.first + movX[i], point.second + movY[i]);

            //如果坐标不合法 or 是墙
            if (!_is_legal_point(map, nextPoint) || _is_wall(map, nextPoint)) {
                continue;
            }

            //如果是终点
            if (_is_dest(map, nextPoint)) {
                // 更新该点的父顶点信息    
                map[nextPoint.first][nextPoint.second].parentPoint = point;
                goto over;
            }

            //如果未被访问  
            if (!_is_visited(map, nextPoint)) {
                //获取旧的f值，如果该点曾经被更新过，则再次比较更新；
                //如果该点没有被更新过，也无妨，进行再次比较更新即可
                int oldF = map[nextPoint.first][nextPoint.second].f;
                //暂存该点的父顶点
                pair<int, int> oldParentPoint = map[nextPoint.first][nextPoint.second].parentPoint;
                map[nextPoint.first][nextPoint.second].parentPoint = point;
                //假设该点作为下一出发点，那么g值要+1
                int newF = _cal_f(map, nextPoint, dest);
                //还原父顶点
                map[nextPoint.first][nextPoint.second].parentPoint = oldParentPoint;

                //新f值比旧f值小
                if (newF < oldF) {
                    // 更新该点的父顶点信息   
                    map[nextPoint.first][nextPoint.second].parentPoint = point;
                    //该顶点的g值+1
                    map[nextPoint.first][nextPoint.second].g = map[point.first][point.second].g + 1;
                    //计算该点到终点的距离h
                    map[nextPoint.first][nextPoint.second].h = _cal_h(nextPoint, dest);
                    //重算该顶点的f值
                    map[nextPoint.first][nextPoint.second].f = map[nextPoint.first][nextPoint.second].g +
                        map[nextPoint.first][nextPoint.second].h;
                    //标记该顶点已访问过
                    map[nextPoint.first][nextPoint.second].isVisited = true;
                    //将该顶点压入最小堆
                    q.push(move(pair<pair<int, int>, int>(nextPoint, map[nextPoint.first][nextPoint.second].f)));
                }
            }
        }
    }
over: {
    //反向跟踪，追溯起点
    pair<int, int> point(dest), parentPoint;

    //还原起点标志
    map[src.first][src.second].key = 'S';
    while (true) {
        //先记录该顶点的父顶点
        parentPoint = map[point.first][point.second].parentPoint;

        //如果是起点
        if (_is_src(map, parentPoint)) {
            break;
        }
        else {
            map[parentPoint.first][parentPoint.second].key = '@';
        }
        point = parentPoint;
    }
    }
}

//打印map信息
void print_map(const vector<vector<Node> >& map)
{
    //迭代器遍历二维向量
    for (auto rowIte = map.begin(); rowIte != map.end(); rowIte++) {
        for (auto colIte = rowIte->begin(); colIte != rowIte->end(); colIte++) {
            cout << colIte->key << " ";
        }
        cout << "" << endl;
    }
}

int main(int argc, char const* argv[])
{
    freopen("A-Star.txt", "r", stdin);
    //行 列
    int N, M;
    //起点 终点
    pair<int, int> src, dest;

    cin >> N >> M;
    //创建一个二维向量map
    vector<vector<Node> > map;
    create_map(map, N, M, src, dest);

    cout << "before A-Star:" << endl;
    //打印map
    print_map(map);
    cout << "" << endl;

    //a-star算法
    a_star(map, src, dest);

    cout << "after A-Star:" << endl;
    //打印map
    print_map(map);
    cout << "" << endl;

    return 0;
}
