// stack by C++ class 
// by wrchow 20110913
// refer to http://my.oschina.net/zmjerry/blog/3652
// 数组实现Stack

#include <iostream>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <cassert>

#define INITSIZE 100
using namespace std;
 
template <typename Type>
class Stack
{
public:
        explicit Stack( int maxSize = INITSIZE );
        //~Stack();
        inline bool isEmpty() const;
        inline void makeEmpty();
        inline void push(const Type &x );
        inline Type& pop();
        inline void getTop( Type &x );
        inline int size(){
            return top+1;
        }
public:
        //void init(string s);
        void printStack(){
            Type x;
            getTop(x);
            cout << "Top : " << top+1 << ','<< x << endl;
        }
private:
        int top;
        int capacity;
        Type *elements;
        void handleOverflow();
        inline void handleUnderflow();
};// class Stack

/*
int main(int argc,char *argv[])
{
    assert(argc == 2);
    string s(argv[1]);
    Stack<char> sk;
    for (int i=0; i<s.size(); i++) {
        sk.push(s[i]);
    }
    sk.push('x');
    sk.printStack();  
    return 0;
}
*/

template <typename Type>
Stack<Type>::Stack( int maxSize ) : top (-1), capacity(maxSize)
{
    elements = new Type[maxSize];
    if( !elements )
    {
        cerr << "Out of memory!" << endl;
        exit(1);
    }
};
 
template <typename Type>
inline bool Stack<Type>::isEmpty() const
{
    return ( top == -1 );
}

template <typename Type>
inline void Stack<Type>::makeEmpty()
{
    top = -1;
}

 
template <typename Type>
inline void Stack<Type>::push( const Type &x )
{
    elements[++top] = x;
    if( top == capacity-1 )
        handleOverflow();
};


template <typename Type>
inline Type& Stack<Type>::pop()
{
    //Type x;
    if( !isEmpty() )
        return elements[top--];
    else
        handleUnderflow();
    return NULL;
};

template <typename Type>
inline void Stack<Type>::getTop( Type &x )
{
    if( !isEmpty() )
        x = elements[top];
    else
        handleUnderflow();
};

template <typename Type>
void Stack<Type>::handleOverflow()
{
    cerr << "Out of memory!" << endl;
    exit(1);
/*
    //capacity = EXTFACTOR * capacity ;
    capacity = int* capacity;

    Type *newArray = new Type[capacity];
    if( newArray == NULL )
    {
        cerr << "Out of memory!" << endl;
        exit(1);
    }

    for( int i=0; i<=top; ++i )
        newArray[i] = elements[i];

    delete []elements;
    elements = newArray;
*/
};

template <typename Type>
inline void Stack<Type>::handleUnderflow()
{
    cerr << "The stack is empty!" << endl << endl;
    exit( 1 );
};



