//
// Created by Mohammed El-khamisi on 2020-05-22.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <iostream>
using  namespace std;


#define TreeEntry int  //first is Value of Element AND second is Key

typedef struct treeNode
{
    TreeEntry entry;
    struct treeNode *left, *right;
}Node;

typedef struct tree
{
    Node *root;
    int size;
}Tree;

void initTree(Tree *pt);
void InsertTree(Tree *pt, TreeEntry *e);
int DeleteTree(Tree *pt,TreeEntry *e, TreeEntry key);
void clearTree(Tree *pt);
int treeEmpty(Tree *pt);
int treeFull(Tree *pt);
int treeSize(Tree *pt);
void inOrder(Tree *pt, void (*pf) (TreeEntry));
int find(Tree *pt, TreeEntry *e, TreeEntry key);


#endif //TREE_TREE_H
