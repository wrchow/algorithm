// 链表实现Stack, refer to 《数据结构与算法分析（C语言）》

#include <iostream>
#include <string>

using namespace std;

class pStack{
public:
    struct node{
        char            data;
        struct node*    next;
    };
    typedef struct node *nodeptr;
    typedef nodeptr stack;
public:
    stack createStack(void) {   
        cout << "createStack().." << endl;
        m_s = new node;
        m_s ->next = NULL;
        makeEmpty();
        return m_s;
    }
    void makeEmpty(){
        cout << "makeEmpty().." << endl;
        if (m_s == NULL) 
            cout << "makeEmpty first!" << endl;
        else 
            while (!isEmpty()) pop();
    }
    void push(char X){
        cout << "push(X).." << X << endl;
        nodeptr p = new node;
        if ( NULL == p) 
            cout << "Out of space!" << endl;
        p->data = X;
        p->next = m_s->next;
        m_s->next = p;
    }
    void pop(){
        cout << "pop().." ;
        nodeptr p;
        if( isEmpty() )
            cout << "empty stack().." << endl;
        else{            
            p = m_s->next;
            cout << p->data << endl;
            m_s->next = p->next;
            delete[] p;
        }
    }
    char top(){
        cout << "top()..";
        if( !isEmpty() )
            return m_s->next->data;
        cout << "empty stack().." << endl;
        return NULL;
    }
    bool isEmpty(){
        return m_s->next == NULL;
    }
private:
    stack m_s;    
};// class pStack

int main(int argc, char* argv[])
{
    string s(argv[1]);
    pStack ps; 
    ps.createStack();
    for (int i=0; i<s.size(); i++) {
        ps.push(s[i]);
        //cout << ps.top() << ' ';
    }
    cout << endl;
    ps.pop();   
    cout << ps.top() << endl;
    return 0;
}

