// pv014 《程序员面试100题》第14题
// 圆圈中最后剩下的数字
// 注意list的erase操作是需要两个指针或迭代器的

#include <iostream>
#include <list>
#include <cstdlib>
#include <cassert>
using namespace std;

int lastOneOfCircle(size_t n, size_t m)
{
    if(n < 1 || m < 1) return -1;
    list<int> interges;
    cout<< "interges: ";
    for (int i=0; i<n; i++) {
        cout << i << ' ';
        interges.push_back(i);
    }
    cout << endl;
    list<int>::iterator it = interges.begin(),it2;
    while (interges.size() > 1) {        
        for (int i=1; i<m; i++) { // note i=1
            it++;
            if(it == interges.end()){
                it = interges.begin();
            }
        }
        it2 = ++it;
        if(it2 == interges.end()){
            it2 = interges.begin();
        }
        --it;
        cout << "del: " << *it << endl;
        interges.erase(it);
        it = it2;
    }
    return *it;//interges.front();
}

int lastOneOfCircle2(size_t n, size_t m)
{
    int lastint = 0;
    for (int i=2; i<=n; i++)
        lastint = (lastint+m)%i;
    return lastint;
}
int main(int argc, char *argv[])
{
    assert(argc == 3);
    size_t n = atoi(argv[1]);
    size_t m = atoi(argv[2]);   
    cout << lastOneOfCircle(n,m) << endl;
    cout << lastOneOfCircle2(n,m) << endl;
    return 0;
}