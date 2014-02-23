// msbd 13.1
// create/length/print single link
// 2014-01-31

#include <iostream>

using namespace std;

class Link {
public:
	Link() {
		m_head = new Node();
		m_length = 0; 
	}

	int size();
	void push_back(const char v);
	void print_link();
	void remove(int i);
	void insert(int i, const char v);

private:
	struct Node {
		char value;
		Node* next;
		Node():next(NULL){}
		Node(char v) {
			value = v;
		}
	};
private:
	Node* m_head;
	int m_length;
};

int Link::size()
{
	return m_length;	
}

void Link::remove(int i) 
{
	if (i < 0 || i >= m_length) {
		cout << "nothing to remove.." << endl;	
		return;
	}
	if (i == 0) {
		Node* p = m_head->next;
		m_head->next = NULL;
		delete p;
	} else {
		Node* p = m_head->next;
		while (--i) {
			p = p->next;	
		}
		Node* q = p->next;
		p->next = p->next->next;
		delete q;
	} 
	m_length --;
	cout << "remove success" << endl;	
} 

void Link::push_back(const char v)
{
	Node* p = m_head;
	Node* p2;	
	while(p != NULL) {
		p2 = p;
		p = p->next;
	}	
	Node* add = new Node(v);
	p2->next = add;
	m_length++;
} 

void Link::print_link() 
{
	Node* p = m_head;
	while(p != NULL) {
		cout << p->value << "->";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Link* link = new Link();
	link->push_back('a');	
	link->push_back('b');	
	link->push_back('c');	
	link->push_back('d');	
	link->print_link();	
	link->remove(2);
	link->print_link();
	cout << "len: " << link->size() << endl;
}


