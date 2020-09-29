#include "BinTree.h"

//先序创建二叉树
BTree *CreateBTree(string s,int* index)
{
	TreeEleType tmp;
	BTree *tmpCell;

	tmp = s[*index];
	(*index)++;
	if(tmp == '*')	return NULL;
	tmpCell = (BTree *)malloc(sizeof(struct BTNode));
	tmpCell->data = tmp;
	tmpCell->left = CreateBTree(s,index);
	tmpCell->right = CreateBTree(s,index);

	return tmpCell;
}

//先序遍历
void preOrderTraversal_BTree(BTree *T)
{
	if(T) {
		printf("%c",T->data);
		preOrderTraversal_BTree(T->left);
		preOrderTraversal_BTree(T->right);
	}
}
void preOrderTraversal_BTree_loop(BTree *T)
{
	BTree *p;
	stack<BTree *> s;

	p = T;

	while(p || !s.empty()) {
		while(p) {
			printf("%c",p->data);
			s.push(p);
			p = p->left;
		}
		if(!s.empty()) {
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

//中序遍历
void inOrderTraversal_BTree(BTree *T)
{
	if(T) {
		inOrderTraversal_BTree(T->left);
		printf("%c",T->data);
		inOrderTraversal_BTree(T->right);
	}
}
void inOrderTraversal_BTree_loop(BTree *T)
{
	BTree *p;
	stack<BTree *> s;

	p = T;
	
	while(p || !s.empty()) {
		while(p) {	/* 一路向左 走到底 */
			s.push(p);
			p = p->left;
		}
		if(!s.empty()) {	/* 访问 */
			p = s.top();
			s.pop();
			printf("%c",p->data);
			p = p->right;
		}
	}
}

//后序遍历
void postOrderTraversal_BTree(BTree *T)
{
	if(T) {
		postOrderTraversal_BTree(T->left);
		postOrderTraversal_BTree(T->right);
		printf("%c",T->data);
	}
}

//层次遍历
void levelOrderTraversal_BTree(BTree *T)
{
	queue<BTree *> q;
	BTree *tmpCell;

	if(!T)	return;
	q.push(T);
	while(!q.empty()) {
		tmpCell = q.front();
		q.pop();
		printf("%c",tmpCell->data);
		if(tmpCell->left)	q.push(tmpCell->left);
		if(tmpCell->right)  q.push(tmpCell->right);
	}
}

//计算深度
int getHeight_BTree(BTree *T)
{
	int left = 0;
	int right = 0;
	int max = 0;

	if(!T)	return 0;

	left = getHeight_BTree(B->left);
	right = getHeight_BTree(B->right);
	max = (left > right)? left : right;

	return max+1;
}

//计算结点个数
int getNodeNum_BTree(BTree *T)
{
	int left = 0;
	int right = 0;

	if(!T)	return 0;

	left = getNodeNum_BTree(T->left);
	right = getNodeNum_BTree(T->right);

	return left+right+1;
}

//计算度为2的结点个数
int getNodeTwoNum_BTree(BTree *T)
{
	if(!T) return 0;
	else {
		if(T->left && T->right) {
			return getNodeTwoNum_BTree(T->left)+getNodeTwoNum_BTree(T->right)+1;
		} else {
			return getNodeTwoNum_BTree(T->left)+getNodeTwoNum_BTree(T->right);
		}
	}	
}

//计算叶子结点个数
int getNodeZeroNum_BTree(BTree *T)
{
	if(!T) return 0;
	else {
		if(!T->left && !T->right) {
			return 1;
		} else {
			return getNodeZeroNum_BTree(T->left)+getNodeZeroNum_BTree(T->right);
		}
	}
}

//计算度为1的结点个数
int getNodeOneNum_BTree(BTree *T)
{
	if(!T) return 0;
	else {
		if(!T->left&&T->right || T->left&&!T->right) {
			return getNodeOneNum_BTree(T->left)+getNodeOneNum_BTree(T->right)+1;
		} else {
			return getNodeOneNum_BTree(T->left)+getNodeOneNum_BTree(T->right);
		}
	}
}

//判断是否为完全二叉树
bool isCompletedBTree(BTree *T)
{
    if(T) {
        queue<BTree *> q;
        q.push(T);             //压入队列

        while(!q.empty()) {
            BTree *tmpCell = q.front();
			q.pop();
			if(tmpCell) {
				printf("%c ",tmpCell->data);
			} else {
				printf("NULL ");
			}
            if(!tmpCell) {          //如果出队元素为空
				bool flag = false;	//默认里面没有非空元素
                //检查队列中是否还有非空元素
				while(!q.empty()) {
					BTree *t = q.front();	
					q.pop();
					if(t) {
						printf("%c ",t->data);
						flag = true;
						break;
					} else {
						printf("NULL ");
					}
				}
				//如果无非空元素，则为完全二叉树；反之不然。
				return !flag;
            }
			q.push(tmpCell->left);
			q.push(tmpCell->right);
        }
    }
}