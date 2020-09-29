//计算每个结点的平衡因子

typedef char ElementType;

typedef struct TreeNode {
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right;
    int bal;                //平衡因子
}BinTree;

//计算深度
int cal_depth(BinTree *B)
{
	int left = 0,right = 0;
	int max = 0;

	if(!B)	return 0;

	left = cal_depth(B->left);
	right = cal_depth(B->right);
	max = (left > right)? left : right;    //选择最大的

	return max+1;
}

//计算每个结点的平衡因子，遍历的应用
void cal_balance(BinTree *B)
{
    if(B) {
        int left = cal_depth(B->left);      //左子树的高度
        int right = cal_depth(B->right);    //右子树的高度
        B->bal = left-right;
        cal_balance(B->left);
        cal_balance(B->right);
    }
}