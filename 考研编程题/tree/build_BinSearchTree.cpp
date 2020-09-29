//建立一棵二叉排序树

typedef int ElementType;

typedef struct TreeNode {
	ElementType data;
	struct TreeNode *left;
	struct TreeNode *right;
}BinTree;

BinTree insert(ElementType x,BinTree *BST)
{
	if(!BST) {
		BST = malloc(sizeof(struct TreeNode));
		BST->data = x;
		BST->left = BST->right = NULL;
	} else {
		if(BST->data > x) 
			BST->left = insert(x,BST->left);
		else 
			BST->right = insert(x,BST->right);
	}

	return BST;
}

int main(int argc, char const *argv[])
{
    int x;
    BinTree *BST = malloc(sizeof(struct TreeNode));

    while(1) {
        cin >> x;    
        if(x == 9999) break;
        insert(x,BST);
    }
    
    return 0;
}

