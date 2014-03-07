/**
@20140222
stack 写第二遍

13:07~13:20
error: 没有考虑异常，栈空不能pop，栈满不能push
*/

#include <iostream>
using namespace std;

class stack {
public:
	stack(int cap) {
		if (cap <= 0) {
			throw std::invalid_argument("the capacity of stack is invalid.");
		}
		m_capacity = cap;
		m_top = 0;
		m_array = new int[cap];
	}

	~stack() {
		delete[] m_array;
	}

	void push(int x) {
		if (m_top >= m_capacity) {
			throw std::overflow_error("stack is full");
		}
		m_array[m_top++] = x;
	}

	int pop(); 

	int top() {
		if (m_top <= 0) {
			throw std::underflow_error("stack is empty");
		}
		return m_array[m_top-1];
	}

	void print(); 

private:
	int *m_array;
	int m_top;
	int m_capacity;
}; 

int stack::pop() {
	if (m_top <= 0) {
		throw std::underflow_error("stack is empty");
	}
	if (m_top > 0 && m_top < m_capacity) {
		return m_array[--m_top];
	} else {
		return -1;
	}
}

void stack::print() {
	if (m_top == 0) {
		cout << "stack is empty()" << endl;
	} else {
		// error: i++ 数组越界很恐怖的
		for (int i=m_top-1; i>=0; i--) {	
			if (i > 0 && i < m_capacity) {
				cout << m_array[i] << "->";
			}
		}
		cout << endl;
	}
}
