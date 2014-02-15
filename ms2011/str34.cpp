//<beauty coding> page 223 
// 从无头单链表中删除节点

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <cassert>
using namespace std;

void delNode(list<char>,int);
void delNode(list<char>::iterator pCur);

void printList(list<char> mlist) {
    list<char>::iterator it;
    for (it = mlist.begin(); it != mlist.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;
}

int main(int argc,char *argv[])
{
    assert(argc == 3);
    string str = argv[1];
    int n = atoi(argv[2]);
    list<char> mlist;
    for (int i=0; i<str.size(); i++) {
        mlist.push_back(str[i]);
    }
    list<char>::iterator pCur = mlist.begin();
    advance(pCur,n-1); // advance
    //delNode(pCur);
    mlist.erase(pCur);
    cout << "After delNode ..." << endl;
    printList(mlist);
    return 0;
}

void delNode(list<char> mlist,int n)
{
    //...
}

void delNode(list<char>::iterator pCur)
{   
    // ...
}
















