//利用二叉链表的二叉树类的定义

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
struct BinTreeNode
{
     T data;
     BinTreeNode<T> *leftChild,*rightChild;
     BinTreeNode():leftChild(NULL),rightChild(NULL){}
     BinTreeNode(T x,BinTreeNode<T> *l = NULL,BinTreeNode<T> *r = NULL)
      :data(x),leftChild(l),rightChild(r){}
};
template <class T>
class BinaryTree
{
public:
     BinaryTree():root(NULL){}
     BinaryTree(T value):RefValue(value),root(NULL){}
     BinaryTree(BinaryTree<T> &s);
     bool IsEmpty(){return(root==NULL)?true:false;}
     BinaryTree<T> *Parent(BinTreeNode<T> *current)
     {
        return (root==NULL||root==current)?NULL:Parent(root,current);
     }
     BinaryTree<T> *LeftChild(BinTreeNode<T> *current)
     {
        return (current!=NULL)?current->leftChild:NULL;
     }
     BinaryTree<T> *RightChild(BinTreeNode<T> *current)
     {
        return (current!=NULL)?current->rightChild:NULL;
     }
     int Height() {return Height(root);}
     int Size() {return Size(root);}
     BinTreeNode<T> *getRoot()const{return root;}
     void PreOrder(void (*visit)(BinTreeNode<T> *p))
     {
      PreOrder(root,visit);
     }
     void inOrder(void (*visit)(BinTreeNode<T> *p))
     {
      inOrder(root,visit);
     }
     void postOrder(void (*visit)(BinTreeNode<T> *p))
     {
      postOrder(root,visit);
     }
     void leverOrder(void (*visit)(BinTreeNode<T> *P));
     int Insert(const T item);
     BinTreeNode<T> *Find(T item)const;
     void CreatBinTree(istream &in,BinTreeNode<T> *&subTree);
     
protected:
     BinTreeNode<T> *root;
     T RefValue;
     bool Insert(BinTreeNode<T> *subTree,const T &x);
     void Destory(BinTreeNode<T> *subTree);
     bool Find(BinTreeNode<T> *subTree,const T &x)const;
     BinTreeNode<T> *Copy(BinTreeNode<T> *orignode);
     int Height(BinTreeNode<T> *subTree);
     int Size(BinTreeNode<T> *subTree);
     BinTreeNode<T> *Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current);
     //bool Find(BinTreeNode<T> *subTree,const T &x)const;
     void Traverse(BinTreeNode<T> *subTree,ostream &out);
     void PreOrder(BinTreeNode<T> *subTree,void (*visit)(BinTreeNode<T> *p));
     void inOrder(BinTreeNode<T> *subTree,void (*visit)(BinTreeNode<T> *p));
     void postOrder(BinTreeNode<T> *subTree,void (*visit)(BinTreeNode<T> *p));
     //friend istream& operator>>(istream &in, BinaryTree<T> &Tree); // error
     //friend ostream& operator<<(ostream &out,BinaryTree<T> &Tree);
};

template<class T>
void BinaryTree<T>::Destory(BinTreeNode<T> *subTree)
{
     if (subTree!=NULL)
     {
      Destory(subTree->leftChild);
      Destory(subTree->rightChild);
      delete subTree;
     }
}
template <class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current)
{
     if (subTree==NULL)
     {
      return NULL;
     }
     if (subTree->leftChild==current||subTree->rightChild==current)
     {
      return subTree;
     }
     BinTreeNode<T> *p;
     if ((p=Parent(subTree->leftChild,current))!=NULL)
     {
      return p;
     }
     else return Parent(subTree->rightChild,current);
}
template <class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree,ostream &out)
{
     if (subTree!=NULL)
     {
      out<<subTree->data<<' ';
      Traverse(subTree->leftChild,out);
      Traverse(subTree->rightChild,out);
     }
}
/*
template <class T>
istream& operator>>(istream &in,BinaryTree<T> &Tree)//重载>>运算符，以实现树的输入
{
    Tree.CreatBinTree(in,Tree.root);
 return in;
}
template <class T>
ostream& operator<<(ostream&out,BinaryTree<T> &Tree)//重载<<运算符，以实现树的输出
{
 out<<"二叉树的前序遍历\n";
 Tree.Traverse(Tree.root,out);
 out<<endl;
 return out;
}
//递归方式建立二叉树，也有很多其它方式可以建立二叉树
template <class T>
void BinaryTree<T>::CreatBinTree(istream &in,BinTreeNode<T> *&subTree)
{

     T item;
     RefValue = 0;
     if (!in.eof())      //此处为输入结束的标记，windows以ctrl+z为结束标记。
     {
      in>>item;
      if (item!=RefValue)
      {
       subTree = new BinTreeNode<T>(item);
       if (subTree==NULL)
       {
        cerr<<"存储分配失败!"<<endl;
        exit(1);
       }
       CreatBinTree(in,subTree->leftChild);
       CreatBinTree(in,subTree->rightChild);
      }
     }
     else subTree = NULL;
}
*/
//简单的visit函数
template <class T>
void visit(BinTreeNode<T> *p)
{
 if (p)
 {
  cout<<p->data<<' ';
 }
}

template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *subTree,void (*visit)(BinTreeNode<T> *p))
{
 if (subTree!=NULL)
 {
  visit(subTree);
  PreOrder(subTree->leftChild,visit);
  PreOrder(subTree->rightChild,visit);
 }
}

template <class T>
 void BinaryTree<T>::inOrder(BinTreeNode<T> *subTree,void (*visit)(BinTreeNode<T> *p))
{
 if (subTree!=NULL)
 {
  inOrder(subTree->leftChild,visit);
  visit(subTree);
  inOrder(subTree->rightChild,visit);
 }
}

template <class T>
void BinaryTree<T>::postOrder(BinTreeNode<T> *subTree,void (*visit)(BinTreeNode<T> *p))
{
 if (subTree!=NULL)
 {
  postOrder(subTree->leftChild,visit);
  postOrder(subTree->rightChild,visit);
  visit(subTree);
 }
}

template <class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree)
{
 if (subTree==NULL)
 {
  return 0;
 }
 else return 1+Size(subTree->leftChild)+Size(subTree->rightChild);
}

template <class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree)
{
     if (subTree==NULL) return 0;
     else
     {
      int i = Height(subTree->leftChild);
      int j = Height(subTree->rightChild);
      return (i<j)?j+1:i+1;
     }
}
//以广义表的形式输出二叉树的算法
template <class T>
void PrintBTree(BinTreeNode<T> *bt)
{
     if (bt!=NULL)
     {
      cout<<bt->data;
      if (bt->leftChild!=NULL||bt->rightChild!=NULL)
      {
       cout<<'(';
      }
      PrintBTree(bt->leftChild);
      cout<<',';
      if (bt->rightChild!=NULL)
      {
       PrintBTree(bt->rightChild);
      }
      cout<<')';
     }
}

main()
{
     BinaryTree<int> tree;
     cin>>tree;
     cout<<tree;
     cout<<"二叉树节点个数为:";
     cout<<tree.Size();
     cout<<endl;
     cout<<"二叉树深度为:";
     cout<<tree.Height();
     cout<<endl;
     BinTreeNode<int> *p;
     p = tree.getRoot();
     cout<<"以广义表的形式输出二叉树:";
     PrintBTree(p);
     cout<<endl;
     cout<<"二叉树前序遍历结果:";
     tree.PreOrder(visit);
     cout<<endl;
     cout<<"二叉树的中序遍历结果:";
     tree.inOrder(visit);
     cout<<endl;
     cout<<"二叉树后序遍历的结果为:";
     tree.postOrder(visit);
     cout<<endl;
     return 0;
}