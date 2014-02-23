/**
@20140220

1. 链表有个头指针；
2. 链表插入，删除操作；
3. 链接反转；
*/

#include <iostream>
using namespace std;

class Node {
public:
	Node() {
		next = NULL;
	}
	char value;
	Node* next;
};

class Link {
public:
	Link() {
	// error1: 初始化
		m_head = new Node();
	}

	void add(char x) {
		Node* p = m_head;
		while (p->next != NULL) {
			p = p->next;
		}	
		Node* q = new Node();
		q->value = x;
		p->next = q;
	}	

	void print() {
	// error2: 头指针不清晰
		Node* p = m_head->next;
		while (p != NULL) {
			cout << p->value << "->";
			p = p->next;
		}
		cout << endl;
	}
	
	int del(char x) {
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
		return 0;
	}

	void reverse() {
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

private:
	Node* m_head;
};

int main()
{
	Link link;
	link.add('a');
	link.add('b');
	link.add('c');
	link.add('d');
	link.print();
	link.del('c');
	link.print();
	link.reverse();
	link.print();
}	
