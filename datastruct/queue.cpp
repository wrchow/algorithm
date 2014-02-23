/**
@20140223 14:50~17:10
1. push, pop, empty, front, back, size
2. link_list 实现队列
*/

#include <iostream>
#include "Link.cpp"
using namespace std;

class Queue {
public:
	Queue() {
		m_link = new Link();
	}

	bool empty() {
		return m_link->empty();
	}

	void push(int x) {
		m_link->add(x);	
	}

	void pop() {
		if (!empty()) {
			m_link->remove(0);
		}
	}
	
	int front() {
		return m_link->get(0);
	}

	int size() {
		return m_link->size();
	}

	void print() {
		m_link->print();
	}

private:
	Link *m_link;
};


int main()
{
	Link link; // add,print,del,empty
	Queue queue;
	queue.pop();
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.print();
	queue.pop();
	queue.print();
	cout << "queue.front = " << queue.front() << endl;
	return 0;
}
