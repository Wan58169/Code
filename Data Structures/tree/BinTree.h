#ifndef BINTREE_H
#define BINTREE_H

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#include<queue>
#include<stack>
using namespace std;

//二叉树声明
typedef char TreeEleType;
typedef struct BTNode {         
    TreeEleType data;
    struct BTNode *left;
    struct BTNode *right;
}BTree;

//先序创建二叉树
BTree *CreateBTree(string s,int* index);

//先序遍历
void preOrderTraversal_BTree(BTree *T);
void preOrderTraversal_BTree_loop(BTree *T);

//中序遍历
void inOrderTraversal_BTree(BTree *T);
void inOrderTraversal_BTree_loop(BTree *T);

//后序遍历
void postOrderTraversal_BTree(BTree *T);

//层次遍历
void levelOrderTraversal_BTree(BTree *T);

//计算深度
int getHeight_BTree(BTree *T);

//计算结点个数
int getNodeNum_BTree(BTree *T);

//计算度为2的结点个数
int getNodeTwoNum_BTree(BTree *T);

//计算叶子结点个数
int getNodeZeroNum_BTree(BTree *T);

//计算度为1的结点个数
int getNodeOneNum_BTree(BTree *T);

//判断是否为完全二叉树
bool isCompletedBTree(BTree *T);

#endif