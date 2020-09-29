//在二叉树中查找data域为x的结点
typedef int ElementType;

typedef struct TreeNode {
	ElementType data;
	struct TreeNode *left;
	struct TreeNode *right;
}BinTree;

BinTree *find(ElementType x,BinTree *BST)
{
	if(!BST) return NULL;
	if(BST) {
		if(BST->data > x) 
			return find(x,BST->left);
		else if(BST->data < x) 
			return find(x,BST->right);
		else  
			return BST;
	}
}