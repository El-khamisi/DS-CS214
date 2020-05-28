//
// Created by Mohammed El-khamisi on 2020-05-22.
//

#include "tree.h"

void inOrderAux(Node **pn,void (*pf) (TreeEntry));
void clearAux(Node **pn);
void InsertTreeAux(Node **pn, TreeEntry *e);
int DeleteTreeAux(Node **pt,TreeEntry *e, TreeEntry key);
void DeleteNode(Node **pn);



void initTree(Tree *pt) {
    pt->root=NULL;
    pt->size=0;
}


void InsertTree(Tree *pt, TreeEntry *e)
{

    int d=0;
    InsertTreeAux(&pt->root,e);
    pt->size++;
}
void InsertTreeAux(Node **pn, TreeEntry *e)
{
    if (!*pn)
    {
        *pn=(Node *)malloc(sizeof(Node));
        (*pn)->entry=*e;
        (*pn)->left=(*pn)->right=NULL;
    } else if(*e < ((*pn)->entry))
    {
        InsertTreeAux(&(*pn)->left,e);
    }else
    {
        InsertTreeAux(&(*pn)->right,e);
    }

}




int DeleteTree(Tree *pt,TreeEntry *e, TreeEntry key)
{
    return DeleteTreeAux(&pt->root,e, key);
}


int DeleteTreeAux(Node **pn,TreeEntry *e, TreeEntry key)
{
    int found=0; Node *q=*pn,*r=NULL;
    while (q  && !(found=(key == q->entry)))
    {
        r=q;
        if (key < q->entry)
            q=q->left;
        else
            q=q->right;
    }

    if(found)
    {
        *e=q->entry;
        if (!r)
            DeleteNode(pn);
        else if (key < r->entry)
            DeleteNode(&r->left);
        else
            DeleteNode(&r->right);

    }
    return found;
}

void DeleteNode(Node **pn)
{
    Node *q=*pn, *r;
    if (!(*pn)->left)
        *pn=(*pn)->right;
    else if ((*pn)->right)
        *pn=(*pn)->left;
    else
    {
        q=(*pn)->left;
        if (!q->right)
        {
            (*pn)->entry = q->entry;
            (*pn)->left=q->left;
        } else
        {
            do{
                r=q;
                q=q->right;
            }while (q->right);
            (*pn)->entry=q->entry;
            r->right=q->left;
        }

    }
    free(q);
}


void clearTree(Tree *pt)
{
    clearAux(&pt->root);
    pt->root=NULL;
    pt->size=0;
}
void clearAux(Node **pn)
{
    if (*pn)
    {
        clearAux(&(*pn)->left);
        clearAux(&(*pn)->right);
        free(*pn);
    }

}



int treeEmpty(Tree *pt)
{
    return (!pt->root);
}
int treeFull(Tree *pt)
{
    return 0;
}


int treeSize(Tree *pt)
{
    return pt->size;
}





void inOrder(Tree *pt, void (*pf) (TreeEntry))
{
  inOrderAux(&pt->root,pf);
}
void inOrderAux(Node **pn,void (*pf) (TreeEntry))
{
    if (*pn)
    {
        inOrderAux(&(*pn)->left,pf);
        (*pf) ((*pn)->entry);
        inOrderAux(&(*pn)->right,pf);
    }
}




int find(Tree *pt, TreeEntry *e, TreeEntry key)
{
    int found=0;
    Node *pn=pt->root;
    while ( pn && !(found=(key == pn->entry)))
    {
        if (key < pn->entry)
            pn=pn->left;
        else
            pn=pn->right;
    }
    if (found)
        *e=pn->entry;
    return found;
}