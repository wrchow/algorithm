// plist refer to list.cpp
// by wrchow at 20110911

// node *p;//只是声明指针而并没有定义

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

typedef struct Node{
    char            data;
    struct Node*    next;
}node;

class MyList{
public:
    void init();
    void init(const string &s);
    void insert(const char &a);
    void insert(char a, int n);
    void erase();
    void erase(int n);
    void reverse();
    void reverse2();
    void printList();
    
public:   
    int  size(){
        return m_size;
    }
    
private:
    node    *head; // 指向链表第一个元素
    int     m_size;
};

int main(int argc,char *argv[])
{
    MyList mlist;
    string s(argv[1]);
    mlist.init(s);
    mlist.printList();
    mlist.reverse2();
    mlist.printList();
    mlist.insert('E');
    mlist.printList();
    mlist.insert('X',2);
    mlist.printList();
    mlist.reverse();
    mlist.printList();
    mlist.erase(2);
    mlist.printList();
    mlist.erase();
    mlist.printList();   
    return 0;
} // main()

void MyList::init()
{
    cout << "init().." << endl;
    m_size = 0;
    head = new node;
    head->next = NULL;
}

void MyList::init(const string &s)
{
    cout << "init(s).." << endl;
    m_size = 0;
    head = new node;
    head->next = NULL;
    for (int i=0; i<s.size(); i++) {
        node *link = new node;
        link->data = s[i];
        link->next = head->next;
        head->next = link;
        m_size++;
    }
}

void MyList::insert(const char &a)
{
    cout << "insert(a).." << a <<  endl;
    node *p = new node;
    p->data = a;
    p->next = head->next;
    head->next = p;
    cout << "test1 : " << &head << ", " << &p << endl;
    m_size++;
}

void MyList::insert(char a, int n)
{// 插入操作报错，貌似p,q指针问题
    cout << "insert(a,n).." << a << "," << n << endl;
    assert(n>=0&&n<=m_size);
    node *p=head,*m = new node; // &p=上一个insert里的&p
    for (int i=0; i<n-1; i++) {
        p = p->next;
    }
    cout << "p -> " << p->data << endl;
    m->next = p->next;
    cout << "test2 : " << &p << "," << &m << endl;
    p->next = m;
    m->data = a;
    m_size++;
}

void MyList::printList()
{
    cout << "Print List : ";
    node *p = new node;   
    for (p=head; p!=NULL; p=p->next) {
        cout << p->data << ' ';
    }
    cout << endl;
}


void MyList::reverse()
{ // p,q记录head前后指针，head从头挪到尾
    cout << "reverse().." << endl;
    node *p=head,*q=head->next;
    for (int i=0; i<m_size; i++) {
        head = q;
        q = q->next;         
        head->next = p;
        if(i==0) p->next = NULL;
        //cout << &head << ":" << head->data <<"->";
        p = head;
    }
}

void MyList::reverse2()
{ // p,q记录head前后指针，H从头挪到尾
    cout << "reverse2().." << endl;
    node *p=head, *q=head->next, *h=head;
    //p->next = NULL; // 头指针变尾指针
    //cout << h->data << '.' ; 
    int i=0;
    while(q != NULL){ // 未到尾部
        //if(++i>10) break;
        h = q;
        q = q->next;
        h->next = p;
        if(p == head) p->next = NULL;
        p = h;
    }
    head = h;    
}

void MyList::erase()
{
    cout << "erase() .. " << endl;
    assert(m_size>=1);
    node *p = head;
    head = p->next;
    delete[] p;
}

void MyList::erase(int n)
{
    cout << "erase .." << n << endl;
    assert(n<=m_size&&n>0);
    node *p=head,*m=new node;
    for (int i=0; i<n-2; i++){
        p = p->next;
        cout << "test1 " << endl;
    }   
    m = p->next;
    cout << "test2 " << m->data <<", " << m->next->data<< endl;
    p->next = m->next;
    cout << "test3 " << p->data << ", " << p->next->data << endl;
    delete[] m;
}







