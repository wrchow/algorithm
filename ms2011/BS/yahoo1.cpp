//yahoo.cpp     创立一个复数域的数据结构并重载加法和乘法

#include <iostream>
using namespace std;

class conflex{
public:
    conflex(float a,float b):m_a(a),m_b(b){
    }
    conflex operator+(conflex& B){
        float a = m_a + B.a();
        float b = m_b + B.b();
        conflex A(a,b);
        return A;
    }
    float& a(){
        return m_a;
    }
    float& b(){
        return m_b;
    }
private:
    float m_a;
    float m_b;
};

int main()
{
    conflex A(1,2),B(3,4);
    conflex C(0,0);
    C = A + B;
    cout << C.a() << C.b() << endl;
}