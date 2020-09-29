//判断是否为完全二叉树

typedef int ElementType;

typedef struct TreeNode {
	ElementType data;
	struct TreeNode *left;
	struct TreeNode *right;
}BinTree;

queue<struct TreeNode*> q;

int isCompleted(BinTree *BT)
{
    if(BT) {
        q.push(BT);

        while(!q.empty()) {
            BinTree *tmp = q.front();
            q.pop();
            if(tmp->left && tmp->right) {               //如果是度为2的结点，将它的孩子按部就班入队
                q.push(tmp->left);
                q.push(tmp->right);
            } else if(!tmp->left || !tmp->right) {      //如果度不为2，那么就是关键结点
                BinTree *nextCell = q.front();           //从队列中弹出关键结点的下一个结点
                if(!nextCell->left && !nextCell->right) //如果下一个结点是叶子结点，则说明该二叉树是
                    return 1;
                else 
                    return 0;
            }
        }
    }
    
}