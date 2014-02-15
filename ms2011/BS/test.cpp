//test just for test

// tree.cpp : Defines the entry point for the console application.
//

#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct node
{
    char data;
    struct node *lchild,*rchild;
}BinNode;
typedef BinNode *BinTree;

BinNode *CreateNode(char c)
{
    BinNode *n1=new BinNode;
    n1->data=c;
    n1->lchild=NULL;
    n1->rchild=NULL;
    return n1;
}
int searchchar(char c,char *order)
{
    for(int i=0;i<strlen(order);i++)
    {
        if(c==order[i])
        return i;
    }
    return -1;
}

BinNode* CreateTree(char *pre,char *in)
{
    char c=pre[0];
    char temppre[100];
    char tempin[100];
    char *p;
    int i=0;
    BinNode* bnode;
    if(pre=='\0')
    return NULL;

    memset(temppre,0,100);
    memset(tempin,0,100);

    bnode=CreateNode(c);
    i=searchchar(pre[0],in);
    if(i==-1)
    return 0;
    p=in;
    strncpy(tempin,p,i);
    p=pre;
    strncpy(temppre,p+1,i);
    bnode->lchild=CreateTree(temppre,tempin);//left

    memset(tempin,0,100);
    memset(temppre,0,100);

    p=in+i+1; 
    strncpy(tempin,p,strlen(in)-i);
    p=pre+i+1;
    strncpy(temppre,p,strlen(in)-i);
    bnode->rchild=CreateTree(temppre,tempin); //right
    return bnode;
}

void POSTORDER(BinNode *t) 
{ 
    if(t) /*二叉树t非空*/ 
    { 
        POSTORDER(t->lchild); /*后序遍历*t的左子树*/ 
        POSTORDER(t->rchild); /*后序遍历*t的右子树*/ 
        printf(" %c",t->data); /*访问结点*/ 
    } 
} 

int main(int argc, char* argv[])
{
    char preorder[100];
    char inorder[100];

    BinNode* Head;

    do{
        printf("Input preOrder..\n");
        scanf("%s",preorder);
        printf("Input inOrder..\n");
        scanf("%s",inorder);
    }while(strlen(preorder)!=strlen(inorder));

    Head=CreateTree(preorder,inorder);
    printf("The postOrder is:");
    POSTORDER(Head);
    printf("\n");
    // printf("%ld",strlen(readin));
    return 0;
}