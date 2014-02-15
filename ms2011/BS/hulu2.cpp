// hulu2.cpp by wrchow at 20110924-20:05~21:33
// 已知树的前序遍历和中序遍历求后序遍历
/* 算法描述：
    1. 前序/后序遍历求树根
    2. 中序遍历求左右子树(中序是必须的)
    3. 递归左右子树..
*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
    int     data;
    node*   left;
    node*   right;
};

node* createTreeNode(int d);
node* createTree(vector<int> &pre, vector<int> &in); // 前序中序建树
void postOrder(vector<int> &post,node *t); // 后续打印树
int findv(vector<int> &v, int x);

int main()
{
    int prea[] = {8,6,5,7,10,9,11};
    int ina[] = {5,6,7,8,9,10,11};
    vector<int> pre(prea,prea+7),in(ina,ina+7);
    node* head = createTree(pre,in);
    vector<int> post;
    cout << "postOrder : ";
    postOrder(post,head);
    //vector<int>::iterator it = post.end();
    //cout<< post.at(it) << endl; // error
    return 0;
}

node* createTreeNode(int d){
    node* tn = new node;
    tn->data = d;
    tn->left = NULL;
    tn->right = NULL;
    return tn;
}

node* createTree(vector<int> &pre,vector<int> &in){
    if(pre.empty() && in.empty()) return NULL;
    // 1. 前序/后序遍历求树根
    node *head = createTreeNode(pre[0]);
    if (pre.size() == 1 && in.size() == 1) return head;
    int div = findv(in,head->data);                     cout << "div = " << div << endl;
    // 2. 中序遍历求左右子树
    vector<int> leftin(in.begin(), in.begin()+div);     cout << "leftin size = " << leftin.size() << endl;
    vector<int> rightin(in.begin()+div+1, in.end());    cout << "rightin size = " << rightin.size() << endl;
    vector<int> leftpre(pre.begin()+1, pre.begin()+1+leftin.size()); cout << "leftpre size = " << leftpre.size() << endl;
    vector<int> rightpre(pre.end()-rightin.size(), pre.end()); cout << "rightpre size = " << rightpre.size() << endl;
    // 注意pre.end()并非指向最后一个元素
    head->left = createTree(leftpre,leftin);   
    head->right = createTree(rightpre,rightin);
    return head;
}

void postOrder(vector<int> &post, node* t){
    if (t) {
        postOrder(post,t->left);
        postOrder(post,t->right);
        post.push_back(t->data);
        cout << t->data << ' ';
    }
}

int findv(vector<int> &v,int x){
    for (int i=0; i<v.size(); i++) {
        if (v[i] == x) return i;
    }
    return -1;
}




