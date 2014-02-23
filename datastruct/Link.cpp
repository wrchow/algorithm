/**
@20140220

1. 链表有个头指针；
2. 链表插入，删除操作；
3. 链接反转；

api:get(x);remove(x);add(x);print();del(x);reverse();
*/

#include <iostream>
using namespace std;

class Node {
public:
	Node() {
		next = NULL;
	}
	int value;
	Node* next;
};

class Link {
public:
	Link() {
	// error1: 初始化
		m_head = new Node();
		m_size = 0;
	}

	bool empty() {
		return m_head->next == NULL;
	}

	int get(int x);

	void add(int x); 

	void print(); 
	
	// 删除位于x的元素
	bool remove(int x); 

	// 删除第一个值为x的元素
	int del(int x); 

	void reverse(); 

	int size() {
		return m_size;
	}

private:
	int m_size;
	Node* m_head;
};

int Link::get(int x) {
	if (x >= 0 && x < m_size) {
		Node* p = m_head->next;
		while (x > 0 && p->next != NULL) {
			p = p->next;
			x --;
		}
		if (x == 0) {
			return p->value;
		}
	} else {
		throw std::overflow_error("x is exceed index!");
	}
// implicit conversion of NULL constant to 'int'
	return NULL;
}

bool Link::remove(int x) {
	if (x >= 0 && x < m_size) {
		Node* p = m_head->next;
		Node* pre = m_head;
		while (x > 0) {
			pre = p;
			p = p->next;
			x--;
		}		
		if (x == 0 && p != NULL) {
			pre->next = p->next;
		} else {
			pre->next = NULL;
		}
		delete p;
	}
	m_size--;
	return false;	
}


void Link::reverse() {
	Node* p = m_head->next;
	Node* pre = NULL; 
	while (p != NULL) {
		Node* pNext = p->next;
		if (pNext == NULL) {
			//error: m_head = pNext;
			m_head->next = p;
		}
		p->next = pre; 	
		pre = p;
		p = pNext;
	}	
}

void Link::print() {
	// error2: 头指针不清晰
	Node* p = m_head->next;
	while (p != NULL) {
		cout << p->value << "->";
		p = p->next;
	}
	cout << endl;
}


void Link::add(int x) {
	Node* p = m_head;
	while (p->next != NULL) {
		p = p->next;
	}	
	Node* q = new Node();
	q->value = x;
	p->next = q;
	m_size++;
}	

int Link::del(int x) {
	Node* p = m_head->next;
	// error3: || -> &&
	while (p->next != NULL && p->next->value != x) {
		p = p->next;
	}
	if (p->next == NULL) {
		return -1;
	} else {
		Node* q = p->next;
		p->next = q->next;
		delete q;
	}
	m_size--;
	return 0;
}
