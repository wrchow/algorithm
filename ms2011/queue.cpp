// 数组实现queue, refer to 《数据结构与算法分析（C语言）》

#include <iostream>
#include <string>
using namespace std;

class Queue{
public:
    Queue();
    bool empty(){
    }
    bool full(){
    }
    void makeEmpty(){
    }
    char front(){
    }
    void enqueue(){
    }
    void dequeue(){
    }
        
private:
    int capacity;
    int front;
    int rear;
    int size;
    char *m_q;
}; // class Queue

int main(int argc, char *argv[])
{
    string s(argv[1]);
    Queue qe;
    for (int i=0; i<s.size(); i++) {
        qe.enqueue(s[i]);
    }
    qe.dequeue();
    return 0;
}