// test

#include <iostream>
using namespace std;

float f; // globle

float f1(float r)
{
    f= r*r;// ¡Ÿ ±±‰¡ø
    return f;
}

float& f2(float r)
{
    f = r*r;
    return f;
}

int main()
{
    float f1(float=5);
    float &f2(float=5);
    float a=f1();
    //float &b=f1(); //invalid initialization
    float b=f2();
    float &d=f2();
    
    cout << "a = " << a << endl
         << "b = " << b << endl;
         
    return 0;
}