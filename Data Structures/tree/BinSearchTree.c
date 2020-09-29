#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct TreeNode *BinTree;
typedef BinTree Position;

struct TreeNode {
	ElementType data;
	BinTree left;
	BinTree right;
};

BinTree insert(ElementType x,BinTree BST)
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

Position find(ElementType x,BinTree BST)
{
	if(!BST) return NULL;
	if(BST) {
		if(BST->data > x) 
			return find(x,BST->left);
		else if(BST->data < x) 
			return find(x,BST->right);
		else if(BST->data == x) 
			return BST;
	}
}

Position find_loop(ElementType x,BinTree BST)
{
	while(BST) {
		if(BST->data > x)
			BST = BST->left;
		else if(BST->data < x) 
			BST = BST->right;
		else if(BST->data == x)
			return BST;
	}
	return NULL;
}

Position findMax(BinTree BST)
{
	while(BST->right)
		BST = BST->right;
	return BST;
}

Position findMin(BinTree BST)
{
	while(BST->left)
		BST = BST->left;
	return BST;
}

BinTree delete(ElementType x,BinTree BST)
{
	Position TmpCell;

	if(!BST) 
		printf("doesn't exist this Element!\n");
	else if(BST->data > x) 
		BST->left = delete(x,BST->left);
	else if(BST->data < x)
		BST->right = delete(x,BST->right);
	else
		if(BST->left && BST->right) {	
			TmpCell = findMin(BST->right);
			BST->data = TmpCell->data;
			BST->right = delete(BST->data,BST->right);
		} else if(BST->left || BST->right) {
			TmpCell = BST;
			if(!BST->left)
				BST = BST->right;
			else if(!BST->right)
				BST = BST->left;
			free(TmpCell);
		} else if(!BST->left && !BST->right) {
			TmpCell = BST;
			BST = NULL;
			free(TmpCell);
		}
	
	return BST;
}

void preOrderTraversal(BinTree BST)
{
	if(BST) {
		printf("%d ",BST->data);
		preOrderTraversal(BST->left);
		preOrderTraversal(BST->right);
	}
}

int main(int argc,char *argv[])
{
	freopen("data.txt","r",stdin);

	int n;
	int TmpCell;

	scanf("%d",&n);

	BinTree BST = NULL;

	scanf("%d",&TmpCell);
	BST = insert(TmpCell,BST);
	for(int i=0; i<n-1; i++) {
		scanf("%d",&TmpCell);
		insert(TmpCell,BST);
	}
	preOrderTraversal(BST);
	
	Position ret;
	ret = findMax(BST);
	printf("\nMax=%d\n",ret->data);
	ret = findMin(BST);
	printf("Min=%d\n",ret->data);

	int del; 
	scanf("%d",&del);
	delete(del,BST);
	preOrderTraversal(BST);
	
	return 0;
}
