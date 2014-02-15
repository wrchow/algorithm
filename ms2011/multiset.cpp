// STL(multiset) for max k problem
// refer to 何海涛-程序员面试100题,第<10题

#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef multiset<int,less<int> > IntHeap; // greater?
void printH(IntHeap &h);
void findMaxK(vector<int> &v, IntHeap &h, size_t k);

int main(int argc, char *argv[])
{
    assert(argc == 2);
    int k = atoi(argv[1]);
    int a[] = {1,3,8,9,7,5,11,12,18,6,4,12};
    int len = sizeof(a)/sizeof(int);
    vector<int> v(a,a+len);
    IntHeap h;
    findMaxK(v,h,k);
    printH(h);
    return 0;
} // main()

void printH(IntHeap &h)
{
    IntHeap::iterator it;    
    for (it=h.begin(); it!=h.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}

void findMaxK(vector<int> &v, IntHeap &h, size_t k)
{
    if (k == 0 || v.size() < k) return;
    h.clear();
    for (size_t i=0; i<v.size(); i++) {
        if (i < k) {
            h.insert(v[i]); //建堆
        } else if (v[i] > *h.begin()) {
            cout << "insert " << v[i] << endl;
            h.erase(h.begin());
            h.insert(v[i]);
        }
    }
    
} // void findMaxK()