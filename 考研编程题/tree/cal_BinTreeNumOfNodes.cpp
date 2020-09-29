//计算二叉树中度为2、1、0结点的个数

typedef char ElementType;

typedef struct TreeNode {
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right;
}BinTree;

//计算二叉树总结点个数
int cal_nodes(BinTree *BT)
{
	int left = 0;
	int right = 0;

	if(!BT)	return 0;

	left = cal_nodes(BT->left);
	right = cal_nodes(BT->right);

	return left+right+1;
}

//计算叶子结点个数
int cal_leaves(BinTree *BT)
{
	int left = 0;
	int right = 0;

	if(BT) {
		if(!BT->left && !BT->right)
			return 1;
		left = cal_leaves(BT->left);
		right = cal_leaves(BT->right);
	}

	return left+right;
}

//计算度为2的结点个数
int cal_degree2(BinTree *BT)
{
    return cal_leaves(BT) - 1;
}

//计算度为1的结点个数
int cal_degree1(BinTree *BT)
{
    return cal_nodes(BT) - 2*cal_degree2(BT) - 1;
}