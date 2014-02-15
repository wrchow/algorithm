// test2 
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string a = "abc";
    string b = a;
    a += "def";
    cout << a << endl << b << endl;
    return 0;
}


