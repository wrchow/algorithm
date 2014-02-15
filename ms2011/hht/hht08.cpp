// hht03.cpp 不用for,while等求1..n的和

#include <iostream>
 
using namespace std;
class A;

A* Array[2];

class A
{
public:
    virtual int Sum (int n) { return 0; }
};

class B: public A
{
public:
    virtual int Sum (int n) { return Array[!!n]->Sum(n-1)+n; }
};

int solution2_Sum(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;
    int value = Array[1]->Sum(n);
    return value;
}
 
int main()
{
    cout << solution2_Sum(10) << endl;
    return 0;
}