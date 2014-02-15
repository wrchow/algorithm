// pTree.cpp
// by wrchow at 20110920
/*
描述：
   用链表实现一棵二叉查找树的类，作为许多编程题的基础用例；
子问题：
    1. 树的镜像，递归mirror(1)和非递归实现mirror(2);
    2. BST转换为双向链表toLink(),convertLink();
*/
#include <vector>
#include <iostream>
#include <deque>
#include <stack>
//#include "stack.cpp"
#include <vector>
using namespace std;

    
template <typename T>
class BST {
private:
    class node{
    public: // note private in default?
        node    *left,*right;
        T       data; // const?
        node(const T& d,node* l,node* r)
            :data(d),left(l),right(r){}
        node(const T& d):data(d),left(0),right(0){}
    };
public:
    BST():root(NULL){}
    node *find(T & x);
    bool isEmpty() const{
        return root == NULL;
    }
    void printTree(){
        printTree(root);
    }
    int depth()const{
        return depth(root);
    }
    void insert(const T x); // !const 
    void createBST(vector<T> & v);
      
    node *getRoot()const{
        return root;
    }
    void preOrder(int i=1){        
        if(i == 1){
            cout << "preOrder recursive.." << endl;
            preOrder(root);           
        }else{
            cout << "preOrder norecursive.." << endl;
            preOrder2(root);  
        }
        cout << endl;
    }
    void postOrder(){
        cout << "postOrder recursive.." << endl;
        postOrder(root);
        cout << endl;
    }
    void inOrder(){
        cout << "inOrder recursive.." << endl;
        inOrder(root);
        cout << endl;
    }
    void mirror(int i=1){
        if(i == 1) {
            cout << "mirror recursive.." << endl;
            mirror(root);
        } else if(i == 2) {
            cout << "mirror2 stack.." << endl;
            mirror2(root);
        }
    }
    node* toLink(){
        return convertToLink(root,true); // right->the leftest 
    }
    void printLink(){
        cout << "printLink..right.." << endl;
        node *head = toLink();       
        node *p = head;
        if(!p) return;
        else {
            cout << p->data << ' ';
            while (p->right) {
                p = p->right;
                cout << p->data << ' ';               
            }
        }
        cout << endl;
    }
private:
    void insert(node* &pNode, node* t);
    int depth(node* t)const{  /*返回树深*/
        int l=1,r=1;
        if (t==NULL) return 0;
        l += depth(t->left);
        r += depth(t->right);
        return l>r?l:r;
    } 
    void printTree(node* pNode) const{
    // 如何自上而下地遍历二叉树,用队列
        cout << "printTree..from top to bottom.." << endl;
        if (pNode == NULL) return; 
        deque<node*> d;   
        d.push_back(pNode);
        node* t;
        //int rh = depth(pNode); // root's depth
        while(d.size() > 0) {
            node* t = d.front();
            d.pop_front();
            // int ch = depth(t); // current depth
            cout << t->data << "   ";       
            if(t->left) d.push_back(t->left);
            if(t->right) d.push_back(t->right);               
        }
        cout << endl;
    }
    void preOrder(node* pNode){
        if(!pNode) return;
        cout << pNode->data << " ";
        preOrder(pNode->left); // 对于每一个分支后进先出
        preOrder(pNode->right);
    }
    void preOrder2(node* pNode){
    // 非递归先序遍历
        if(!pNode) return;
        stack<node*> s;
        s.push(pNode);
        node *ptmp;
        while (s.size() > 0) {
            ptmp = s.top(); 
            cout << ptmp->data << ' ';
            s.pop();           
            if(ptmp->right != NULL) s.push(ptmp->right);
            if(ptmp->left != NULL) s.push(ptmp->left);
        }
    }
    void postOrder(node* pNode){
        if(!pNode) return;        
        preOrder(pNode->left);
        preOrder(pNode->right);
        cout << pNode->data << " ";
    }
    void inOrder(node* pNode){
        if(!pNode) return;        
        inOrder(pNode->left);
        cout << pNode->data << " ";
        inOrder(pNode->right);       
    }
    void mirror(node* pNode){
        if(!pNode) return;
        node* t; // swap
        t = pNode->left;
        pNode->left = pNode->right;
        pNode->right = t;
        if (pNode->left) mirror(pNode->left);
        if (pNode->right) mirror(pNode->right);
    }
    void mirror2(node* pNode){
    // by Stack
        if(!pNode) return;
        vector<node*> stack;
        stack.push_back(pNode);
        while (stack.size() > 0) {
            node* t = stack.back(); // swap        
            stack.pop_back();
            node* tmp;
            tmp = t->left;
            t->left = t->right;
            t->right = tmp;
            if (t->left) stack.push_back(t->left);
            if (t->right) stack.push_back(t->right);
        }
    }
    node *convertToLink(node* pNode,bool isRight){
    // isRight: is on the right of pNode?
        if (!pNode) return NULL;
        node *pLeft(NULL),*pRight(NULL);
        if (pNode->left) 
            pLeft = convertToLink(pNode->left, false);
        if (pLeft) {
            pLeft->right = pNode;// 8->10
            pNode->left = pLeft; // 10<-8
        }
        if (pNode->right)
            pRight = convertToLink(pNode->right, true);
        if (pRight) {
            pRight->left = pNode;  //12->10
            pNode->right = pRight; //12<-10
        }
        node *p(pNode); // head or tail
        if (isRight)  
            while (p->left) p = p->left;
        else 
            while (p->right) p = p->right;
        return p;
    }
private:
    node *root;
}; // BST

 
template <typename T>
void BST<T>::insert(const T x){
    insert(root,new node(x));
    cout << "insert.. " << x << endl;
}
 
template <typename T>
void BST<T>::insert(node* &pNode, node* t){
    if (!pNode) pNode = t;
    else if (t->data < pNode->data) {
            insert(pNode->left, t);
    } else {
            insert(pNode->right, t);
    }  
}

template <typename T>
void BST<T>::createBST(vector<T> & v)
{
    cout << "createBST(v).." << endl;
    for (int i=0; i<v.size(); i++) {
        insert(v[i]);
    }        
}
  /* the tree demo :
                 8
            6        10
         5    7    9    11
      4                     13
    */
int main(int argc, char* argv[])
{
    int a[] = {8,6,10,5,7,9,11};
    vector<int> v(a,a+7);
    BST<int> bst;
    
    bst.createBST(v);
    bst.printTree();
    cout << "depth : " << bst.depth()<<endl;
    bst.insert(4);
    
    bst.preOrder();
    bst.preOrder(2); // 非递归遍历
    bst.inOrder();
    bst.postOrder();
    
    bst.mirror(2);
    bst.mirror(1);
    bst.printTree();
    bst.printLink();
        
    return 0;
}











