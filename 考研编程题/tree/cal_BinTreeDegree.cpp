//计算每个结点的度数
typedef char ElementType;

typedef struct TreeNode {
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right;
    int degree;                //度数=子树的个数
}BinTree;

//计算每个结点的度数
void cal_degree(BinTree *B)
{
    if(B) {
        if(B->left && B->right) B->degree = 2;
        else if(B->left || B->right) B->degree = 1;
        else B->degree = 0;
        cal_degree(B->left);
        cal_degree(B->right);
    }
}