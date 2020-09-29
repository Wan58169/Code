//寻找二叉排序树中任意两结点的共同祖先
#include<iostream>
#include<queue>
using namespace std;

typedef char ElementType;

typedef struct TreeNode {
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right;
}BinTree;


queue<int> Path,retA,retB;
const int INFINITY = 9999;

//计算根结点到结点A的路径
  void cal_path(BinTree *BT,BinTree *Node)
{
    if(Node->data < BT->data) {
        Path.push(BT);
        cal_path(BT->left);
    } else if(Node->data > BT->data) {
        Path.push(BT);
        cal_path(BT->right);
    } else {
        Path.push(BT);
        return;
    }
}

//寻找二叉排序树中任意两结点的共同祖先
BinTree *findAncestor(BinTree *BT,BinTree *Node1,BinTree *Node2)
{
    //计算根结点到结点A的路径
    cal_path(BT,Node1);
    while(!Path.empty()) {
        retA.push(Path.front());
        Path.pop();
    }
    retA.push(INFINITY);        //在队尾设置一个“不可能”flag
    //计算根结点到结点B的路径
    cal_path(BT,Node2);
    while(!Path.empty()) {
        retA.push(Path.front());
        Path.pop();
    }
    retB.push(INFINITY);        //在队尾设置一个“不可能”flag
    //寻找最低共同祖先
    BinTree *ancestor;
    while(1) {
        if(retA.front() == retB.front()) {
            ancestor = retA.front();
            retA.pop();
            retB.pop();
        } else {
            break;
        }
    }
    return ancestor;
}
