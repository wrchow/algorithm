// refer to http://zhedahht.blog.163.com/blog/static/25411174201102642136998/
// by wr-chow at 20110830
// two questions a day
#include<cstdio>

class B;
class A;

struct Point3D
{
	int x,y,z;
};

int main()
{
	Point3D* pPoint = NULL;
	int offset1 = (int)(&(pPoint)->z);
	int offset2 = (int)(&(pPoint)->x);
	int offset3 = (int)(&(pPoint)->y);
	/*
	输出8。由于在pPoint->z的前面加上了取地址符号，运行到此时的时候，
	会在pPoint的指针地址上加z在类型Point3D中的偏移量8。由于pPoint的地址是0，
	因此最终offset的值是8。
	&(pPoint->z)的语意是求pPoint中变量z的地址（pPoint的地址0加z的偏移量8），
	并不需要访问pPoint指向的内存。只要不访问非法的内存，程序就不会出错。
	*/
	printf("%d, %d, %d", offset1,offset2,offset3);
	// 一个int 是4个字节
	//----------2-----------//
	A* pA = new A(); //??? no appropriate default constructor available
	delete pA;
	return 0;
}

//------------------------2-------------------------------//
/*
先后打印出两行:A is constructed. B is constructed. 调用B的构造函数时，
先会调用B的基类及A的构造函数。然后在A的构造函数里调用Print。
由于此时实例的类型B的部分还没有构造好，本质上它只是A的一个实例，
他的虚函数表指针指向的是类型A的虚函数表。因此此时调用的Print是A::Print，
而不是B::Print。接着调用类型B的构造函数，并调用Print。此时已经开始构造B，
因此此时调用的Print是B::Print。
同样是调用虚拟函数Print，我们发现在类型A的构造函数中，调用的是A::Print，
在B的构造函数中，调用的是B::Print。因此虚函数在构造函数中，
已经失去了虚函数的动态绑定特性。
*/
class A
{
public:
	A()
	{
		Print();
	}
	virtual void Print()
	{
		printf("A is constructed.\n");
	}
};

class B: public A
{
	public:
		B()
		{
			Print();
		}
		virtual void Print()
		{
			printf("B is constructed.\n");
		}
};

/*
题目（九）：在C++和C#中，struct和class有什么不同？

答案：在C++中，如果没有标明函数或者变量是的访问权限级别，
在struct中，是public的；而在class中，是private的。

                在C#中，如果没有标明函数或者变量的访问权限级别，
				struct和class中都是private的。struct和class的区别是：
				struct定义值类型，其实例在栈上分配内存；class定义引用类型，
				其实例在堆上分配内存。
*/



