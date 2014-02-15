// refer to http://zhedahht.blog.163.com/blog/static/254111742011012111557832/
// by wr-chow at 2011-0829
#include <iostream>
#include <stdio.h>

// ----------------------1--------------------------//
// static & const

// ----------------------2--------------------------//
class A {};

class B 
{
public:
	B() {}
	~B() {}
};

class C
{
public:
	C() {}
	virtual ~C() {}
};
// ----------------------3--------------------------//
/*
答案是Print1调用正常，打印出hello world，但运行至Print2时，程序崩溃。
调用Print1时，并不需要pA的地址，因为Print1的函数地址是固定的。
编译器会给Print1传入一个this指针，该指针为NULL，但在Print1中该this指针并没有用到。
只要程序运行时没有访问不该访问的内存就不会出错，因此运行正常。在运行print2时，
需要this指针才能得到m_value的值。由于此时this指针为NULL，因此程序崩溃了。	
*/
class D
{
private:
		int m_value;

public:
		D(int value)
		{
			m_value = value;
		}
		void Print1()
		{
			printf("hello world");
		}
		void Print2()
		{
			printf("%d", m_value);
		}
// ----------------------4--------------------------//
		virtual void Print3()
		{
			printf("hello world");
		}
};

//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	printf("%d, %d, %d\n", sizeof(A), sizeof(B), sizeof(C));
	
	D* pD = NULL;
	pD -> Print1();
	pD -> Print3();
	//pD -> Print2();
	
	return 0;
}



