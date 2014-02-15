#include <iostream>
#include <list>
#include <vector>
using namespace std;

void insertSortList(list<size_t> &lt, int x)
{
    if(lt.empty()) {
        lt.push_back(x);
    } else {
        list<size_t>::iterator it = lt.begin();
        cout << "begin: " << *it << endl;
        for (; it!=lt.end(); it++) {
            if (*it > x) {
                cout << "break: " << *it << endl;
                break;
            }
        }
        cout << endl;
        lt.insert(it,x);
    }   
}

void printl(list<size_t> &lt) {
    if( lt.empty() ) return;
    list<size_t>::iterator it = lt.begin();
    for (; it != lt.end(); it++)
        cout << *it << ' ';
    cout << endl;
}

int main()
{
    int a[] = {2,3,1,5,6};
    vector<size_t> v(a,a+5);
    list<size_t> lt;
    for (size_t i=0; i<v.size(); i++) {
        insertSortList(lt,v[i]);
    }
    cout << "after insert sort.." << endl;
    list<size_t>::iterator it = lt.begin();;
    cout << *it << enl;
    printl(lt);
    
    return 0;
}
