/**
@20140221
08:54~09:29

1. cpp实现stack类；
2. 包含pop,top,push功能
3. 底层为数组；
*/

#include <iostream>
using namespace std;

class stack {
public:
	stack(int cap) {
		m_array = new int[m_capacity];
		m_top = 0;
		m_capacity = cap;
	}
	
bool isFull() {
		return (m_top >= m_capacity);
	}

	bool isEmpty() {
		return (m_top <= 0);
	}

	int pop() {
		m_top --;
		return m_array[m_top];
	}
	
	void push(int x) {
		m_array[m_top] = x;
		m_top ++;
	}
	
	void print() {
		if (m_top == 0) {
			cout << "stack is empty" << endl;
		} else {
			// error: i=m_top; i>=0; i++
			for (int i=m_top-1; i>=0; i--) {
				cout << m_array[i] << " ";
			}
			cout << endl;
		}
	}

private:
	int *m_array;
	int m_capacity;
	int m_top;	
};


int main()
{
	stack s(3);
	s.push(3); s.push(2); s.push(1);
	s.print();
	s.pop();
	s.print();
}
