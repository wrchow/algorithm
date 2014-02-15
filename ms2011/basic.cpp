// basic c++ for '&' and '*' and template 
// by wrchow at 20110913

// const 重载问题
// http://www.cnblogs.com/qingquan/archive/2010/10/21/1857444.html
// 重载是在编译阶段实现的，编译器根据函数不同的参数表，对同名函数的名称做修饰
/*
总结：
1.const重载主要是通过能否对传入的参数进行修改为判断的。
2.const参数重载和const函数重载机制都是一样的，因为对于const 函数重载可看做是对隐含的指针this的参数重载。
3.重载是在编译阶段已经完成，对于汇编和链接来说透明的。
*/
#include <iostream>
#include <string>

using namespace std;

// const string & print(const string& s);
// void print(string s);

const string & print(const string *s);
void print(string *s);
void print(int a[]);

int main()
{
    const string s("abc");
    print(&s);
    int a[] = {3,4,5};
    
    return 0;
}

const string & print(const string* s)
{
    cout << "const string & print(const string& s).." << endl;
    cout << *s << endl;
    return *s;
} 

void print(string s)
{
    cout << "void print(string s) .. " << endl
        << s << endl;
}

void print(int a[])
{
    
}



