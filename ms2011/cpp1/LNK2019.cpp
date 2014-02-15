// LNK2019
// by wr-chow at 2011-3-6
// refer to http://msdn.microsoft.com/en-us/library/799kze2z(v=vs.80).aspx

// LNK2019b.cpp
// LNK2019 expected
struct C {
   static int s;
};

// Uncomment the following line to resolve.
// int C::s;
//
//int main() {
//   C c;
//   C::s = 1;
//}

// LNK2019e.cpp
// compile with: /EHsc
// LNK2019 expected
#include <iostream>
using namespace std;

template<class T> 
class Test {
   // friend ostream& operator<<(ostream&, Test&);
   // Uncomment the following line to resolve.
   template<typename T> friend ostream& operator<< (ostream&, Test<T>&);
}; // class Test

template<typename T>
ostream& operator<<(ostream& os, Test<T>& tt) {
   return os;
}

int main() {
   Test<int> t;
   cout << "Test: " << t << endl;   // unresolved external
}
