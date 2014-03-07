/**
@20140223 18:31~20:20

1. 二叉树的遍历；
2. 非递归遍历，想想栈是用来干什么的：
	后进先出，用来倒序的,用来实现递归的；
3. 使用队列（数组）来实现层序遍历；
*/

#include <iostream>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

class TreeNode {
public:
	TreeNode() {
		lchild = NULL;
		rchild = NULL;
	}
// error: TreeNode* lchild, rchild;
	TreeNode* lchild;
	TreeNode* rchild;
	char value;
};

class TreeNodeAndBool {
public:
	TreeNodeAndBool() {
		node = NULL;
		isFirst = false;
	}
	TreeNode* node;
	bool isFirst;
};

class BinTree {
public:
	BinTree() {
		m_root = new TreeNode();
	}

	void createTree(const string s);	
	void preOrder();
	void inOrder();
	void postOrder();
	
	void layerOrder();

private:
	TreeNode* m_root;
};


int main()
{
	BinTree btree;
	cout << "A(B(C,D),E))" << endl;
	btree.createTree("A(B(C,D),E))");
	btree.preOrder();
	btree.inOrder();
	btree.postOrder();
	btree.layerOrder();
	return 0;
}

/*
非递归前序遍历:
1. 访问根节点并压栈；
2. 访问左子树不为空则压栈；
3. 为空则出栈；
4. 访问右子树不为空压栈；
5. 为空则出栈；
*/
void BinTree::preOrder() {
	cout << "preOrder: ";
	stack<TreeNode*> st;
	//error: st.push(m_root);
	TreeNode* p = m_root;
	
	while (p != NULL || !st.empty()) {
	//error: while (p != NULL && !st.empty()) {
		while (p != NULL) {
			cout << p->value << "->";
			st.push(p);
			p = p->lchild;
		}	
		if (!st.empty()) {
			p = st.top();
			st.pop();
			p = p->rchild;	
		}
	}
	cout << endl;
}

/*
1. 把从根一直到到最左的叶子的所有根节点压栈；
2. 出栈前，先打印；
*/
void BinTree::inOrder() {
	cout << "inOrder: ";
	stack<TreeNode*> st;
	TreeNode* p = m_root;
	while (p != NULL || !st.empty()) {
		while (p != NULL) {
			st.push(p);
			p = p->lchild;
		}
		if (!st.empty()) {
			p = st.top();
			cout << p->value << "->";
			st.pop();
			p = p->rchild;
		}
	}
	cout << endl;
}

/*
1. 节点新增一个isFirst；
2. 先左子树并压栈，isFirst->true知道为空到栈顶；
3. 访问左子树和根改为false；
4. 访问右子树，如果根为false则出栈，并访问根； 
error: pb->isFirst控制混乱；
*/
void BinTree::postOrder() {
	cout << "postOrder: ";
	stack<TreeNodeAndBool*> st;
	TreeNodeAndBool* pb = new TreeNodeAndBool();
	TreeNode* p = m_root;
	while (p != NULL || !st.empty()) {
		while (p != NULL) {
			// error: if use pb not new tpb
			TreeNodeAndBool* tpb = new TreeNodeAndBool();
			tpb->isFirst = true;
			tpb->node = p;
			st.push(tpb);
			//cout << "push1:" << tpb->node->value << endl;
			p = p->lchild;
		}
		if (!st.empty()) {
			pb = st.top();
			st.pop();
			//cout << "pop:" << pb->node->value << endl;
			if (pb->isFirst == true) {
				pb->isFirst = false;
				st.push(pb);
				//cout << "push2:" << pb->node->value << endl;
				p = pb->node->rchild;
			} else {
				cout << pb->node->value << "->";
				p = NULL;
			}
		}
	}	
	cout << endl;
}

/*
1. queue先进先出，自上而下地遍历；
2. cur_layer_num  每层的节点数；
*/
void BinTree::layerOrder() {
	cout << "layerOrder: " ;
	queue<TreeNode*> qu;
	qu.push(m_root);
	int cur_layer_num = 0;
	while (!qu.empty()) {
		cur_layer_num = qu.size();
		while (cur_layer_num--) {
			TreeNode* p = qu.front();
			// error forget pop
			qu.pop();
			cout << p->value << "->";
			if (p->lchild != NULL) qu.push(p->lchild);
			if (p->rchild != NULL) qu.push(p->rchild);
		}
	}		
	cout << endl;
}

//创建二叉树，s为形如A(B(C,D),E))形式的字符串 
/*
1. 为什么选用堆栈?保证E成为A的右子树；
2. (则进栈，)则出栈；
3. ,前为左子树，,后为右子树；
4. 遍历字符串s，将所指字符挂到树上；
*/
void BinTree::createTree(const string s) {
	// error: s == NULL ?
	if (s.length() == 0) {
		return;
	}
	stack<TreeNode*> st;
	m_root->value = s[0];
	st.push(m_root);
	bool isRight = false;
	TreeNode* pCurrent = NULL;
	for (int i=1; i<s.length()-1; i++) {
		if (s[i] == '(') {
			isRight = false;
		} else if (s[i] == ',') {
			isRight = true;
		} else if (s[i] == ')') {
			st.pop();
		} else if (isalpha(s[i])) {
			pCurrent = new TreeNode();
			pCurrent->value = s[i];
			if (isRight) {
				st.top()->rchild = pCurrent;
				cout << st.top()->value << "'s rchild is " << s[i] << endl;
			} else {
				st.top()->lchild = pCurrent;
				cout << st.top()->value << "'s lchild is " << s[i] << endl;
			}					
		}
		if (s[i+1] == '(') {
			st.push(pCurrent);
		}
	}
}



