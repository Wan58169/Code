//计算树中所有结点的度的算法

typedef char ElementType;

typedef struct TreeNode {
    ElementType data;
    struct TreeNode *firstchild;    //第一个孩子结点
    struct TreeNode *nextsibling;   //兄弟结点
    int degree;                     //度数=第一个孩子的兄弟结点的个数+1
}Tree;

void cal_TreeDegree(Tree *T)
{
    if(T == NULL)   return;         //如果为空结点，返回NULL

    T->degree = 0;                  //初始
    //计算连在第一个孩子上的兄弟结点个数
    for(Tree *p = T->firstchild; p; p = p->nextsibling) 
        T->degree++;
    cal_TreeDegree(T->firstchild);
    cal_TreeDegree(T->nextsibling);
}
