#include<iostream>
using namespace std;

int N;
string pre,in;

struct Node{
    char data;
    struct Node *left,*right;
};
typedef struct Node *Tree;

//preL为前序序列的第一个结点，inL为中序,n为序列长度
Tree create_tree(int preL,int inL,int n)
{
    int i;
    char root;
    Tree T;

    if(n == 0) return NULL;

    //安放根结点
    root = pre[preL];
    T = new Node;
    T->data = root;
    //在中序序列中确定根结点的位置
    for(i=0; i<n; i++) {
        if(in[inL+i] == root) break;
    }
    //L为左子树的结点个数，R为右子树的结点个数
    int L = i, R = n-i-1;
    //建立左右子树
    T->left = create_tree(preL+1,inL,L);
    T->right = create_tree(preL+1+L,inL+L+1,R);
    return T;
}

//获取二叉树的高度
int getHeight(Tree T)
{
    int left,right;

    if(!T) return 0; 
    left = getHeight(T->left);
    right = getHeight(T->right);
    return max(left,right)+1;
}

int main(int argc, char const *argv[])
{
    Tree T;
    int height;

    cin >> N >> pre >> in;    
    
    T = create_tree(0,0,N);
    height = getHeight(T);

    cout << height << endl;

    return 0;
}
