// 7-3 树的同构（25 分）
// 给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。
// 现给定两棵树，请你判断它们是否是同构的。

// 输入格式:
// 输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，
// 即该树的结点数（此时假设结点从0到N−1编号）；
// 随后N行，第i行对应编号第i个结点，
// 给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。
// 如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。

// 输出格式:
// 如果两棵树是同构的，输出“Yes”，否则输出“No”。

// 输入样例1（对应图1）：
// 8
// A 1 2
// B 3 4
// C 5 -
// D - -
// E 6 -
// G 7 -
// F - -
// H - -
// 8
// G - 4
// B 7 6
// F - -
// A 5 1
// H - -
// C 0 -
// D - -
// E 2 -
// 输出样例1:
// Yes
// 输入样例2（对应图2）：
// 8
// B 5 7
// F - -
// A 0 3
// C 6 -
// H - -
// D - -
// G 4 -
// E 1 -
// 8
// D 6 -
// B 5 -
// E - -
// H - -
// C 0 2
// G - 3
// F - -
// A 1 4
// 输出样例2:
// No
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct {
    char data;
    int left,right;
}Tree;

int N;                  //树的结点个数
const int Null = -1;    //叶结点

//建树
Tree* build_tree()
{
    Tree *T;

    //初始化
    cin >> N;
    T = new Tree[N];
    //读入结点信息
    for(int i=0; i<N; i++) {
        char left,right;
        cin >> T[i].data >> left >> right;
        if(left == '-') T[i].left = -1;
        else T[i].left = left-'0';
        if(right == '-') T[i].right = -1;
        else T[i].right = right-'0'; 
    }
    return T;
}

//寻找根结点
int find_root(Tree *T)
{
    int check[N] = {0};
  
    for(int i=0; i<N; i++) {
        if(T[i].left != -1) check[T[i].left] = 1;
        if(T[i].right != -1) check[T[i].right] = 1;
    }
    for(int i=0; i<N; i++) {
        if(check[i] == 0) return i;
    }
}

//判断两棵树是否同构
bool isSame(Tree *T1,Tree *T2,int R1,int R2)
{
    //如果两个都是叶子结点
    if(R1==Null && R2==Null) return true;
    //如果只有一个是叶子结点
    if((R1==Null&&R2!=Null) || (R1!=Null&&R2==Null)) return false;
    //如果结点的数据不同
    if(T1[R1].data != T2[R2].data) return false;
    //如果左子树都为空
    if(T1[R1].left==Null && T2[R2].left==Null) {
        return isSame(T1,T2,T1[R1].right,T2[R2].right);
    }
    //如果左子树都不为空
    if(T1[R1].left!=Null && T2[R2].left!=Null) {
        if(T1[T1[R1].left].data == T2[T2[R2].left].data)
            return isSame(T1,T2,T1[R1].left,T2[R2].left)&&isSame(T1,T2,T1[R1].right,T2[R2].right);
        else 
            return isSame(T1,T2,T1[R1].left,T2[R2].right)&&isSame(T1,T2,T1[R1].right,T2[R2].left);
    }
}

int main()
{
    freopen("07-3.txt","r",stdin);
    Tree *T1,*T2;                   //树的存储结构
    int R1,R2;                      //树结点

    //建树
    T1 = build_tree();
    R1 = find_root(T1);
    T2 = build_tree();
    R2 = find_root(T2);
    
    //判断是否同构
    if(isSame(T1,T2,R1,R2))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
}