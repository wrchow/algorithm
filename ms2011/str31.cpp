//<beauty coding> page 213 
// 字符串移位包含问题

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool strf1(string A,string B);


int main(int argc,char * argv[])
{
    assert(argc == 3);
    const string A(argv[1]), B(argv[2]);
    cout << "For strf1 is " << strf1(A,B) << endl;
    
    return 0;
}

bool strf1(string A,string B)
{
    string AA = A + A;
    for (int i=0; i<A.size(); i++) {
        if (AA.find(B)) return true;
    }
    return false;
}
