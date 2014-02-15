// °∂±‡≥Ã÷Æ√¿°∑ page 233
//  by wrchow at 20110913
// int atoi(const char *nptr); 
#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
#include <string>
#include <cstdlib>

#define STACKSIZE 10
using namespace std;

class Stack{
public:
    Stack(){
        stackTop = -1;
        maxIdx  = -1;
    }
    ~Stack(){
        delete[] stackItem;
        delete[] maxItem;
    }
    void push(int x){
        stackTop++;
        if (stackTop >= STACKSIZE){ 
            cout << "Overflow!" << endl;
        } else {
            stackItem[stackTop] = x;
            if (x > max()) {
                maxItem[stackTop] = maxIdx;
                maxIdx = stackTop;
            } else {
                maxItem[stackTop] = -1;
            }
        }
    }
    int pop(){
        cout << "pop.." << stackItem[stackTop]<< endl;
        int ret;
        if (stackTop < 0) {
            cout << "no elements to pop!" << endl;
        } else {
            ret = stackItem[stackTop];
            if (stackTop == maxIdx) {
                maxIdx = maxItem[stackTop];
            }
            stackTop--;
        }
        return ret;
    }
    int max() {
        if (maxIdx >= 0) {
            return stackItem[maxIdx];
        } else {
            return -INT_MAX;
        }
    }
    void printTop(){
        cout << "Top: " << stackItem[stackTop] <<","
            << stackTop+1 << endl;
    }
private:
    int     stackTop;
    int     stackItem[STACKSIZE];
    int     maxIdx;
    int     maxItem[STACKSIZE];
}; // class Stack

int main(int argc, char *argv[])
{
    assert(argc == 2);
    const string s(argv[1]);
    Stack stk;
    for (int i=0; i<s.size(); i++) {
        cout << atoi(&s[i]);
        stk.push(atoi(&s[i]));
    }
    stk.printTop();
    stk.pop();
    stk.printTop();
    return 0;
}