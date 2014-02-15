// by wr-chow at 2011-3-10
// refer to http://www.cppblog.com/goal00001111/archive/2009/01/20/72378.html
/*
函数名称：Permutation
函数功能：普通递归算法：输出n个数的所有全排列
输入变量：int n：1，2，3，...，n共n个自然数
输出变量：无
*/
#include <iostream>
using namespace std;

void Permutation(int n);
void Recursion(int a[], int n, int k, int dpn);
void Print(int a[], int n);
void Printn(int a[], int n);
void printdpn(int dpn);

void printdpn(int dpn)
{
	cout << dpn ;
	for (size_t i = 0; i < dpn; i++) {
		cout << "--";
	}
}

void Permutation(int n)
{
    int *a = new int[n];//用来存储n个自然数 
	for (int i = 0; i < n; i++){ //存储全排列的元素值
        a[i] = i + 1;  
	}
    Recursion(a, n, n-1, 0); //调用递归函数     
    delete []a;
}
/*
函数名称：Recursion
函数功能：递归输出n个数的所有全排列
输入变量：int a[]：存储了1，2，3，...，n共n个自然数的数组 
          int n：数组a[]的长度
          int k：正在处理的k个元素所组成的排列 
输出变量：无
*/
void Recursion(int a[], int n, int k, int dpn)
{
	dpn++; printdpn(dpn);
	if (k == 0) {//排列只有一个元素a[k]，直接输出 
        Print(a, n);
	}
    else {
        int temp;
        for (int i = 0; i <= k; i++) //穷举，依次让第k个元素与前面的元素交换 
        {
			cout << "			 (1)i: " << i << "	k: " << k << "	*"; Print(a, n); 
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;    
			cout << "			 (2)i: " << i << "	k: " << k << "	*"; Print(a, n); 
            Recursion(a, n, k-1, dpn); //递归生成k-1个元素的全排列 
            temp = a[i]; //再换回来 
            a[i] = a[k];
            a[k] = temp;
			cout << "			 (3)i: " << i << "	k: " << k << "	*"; Print(a, n); 
        }
    }
}
 

void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

 

int main()
{
	cout << "Input the no of the permutation you want : ";
	int n;
	cin >> n;
	Permutation(n);
	getchar();
	return 0;
}

//Input the no of the permutation you want : 3
//1--                      (1)i: 0        k: 2    *123
//                         (2)i: 0        k: 2    *321
//2----                    (1)i: 0        k: 1    *321
//                         (2)i: 0        k: 1    *231
//3------231
//                         (3)i: 0        k: 1    *321
//                         (1)i: 1        k: 1    *321
//                         (2)i: 1        k: 1    *321
//3------321
//                         (3)i: 1        k: 1    *321
//                         (3)i: 0        k: 2    *123
//                         (1)i: 1        k: 2    *123
//                         (2)i: 1        k: 2    *132
//2----                    (1)i: 0        k: 1    *132
//                         (2)i: 0        k: 1    *312
//3------312
//                         (3)i: 0        k: 1    *132
//                         (1)i: 1        k: 1    *132
//                         (2)i: 1        k: 1    *132
//3------132
//                         (3)i: 1        k: 1    *132
//                         (3)i: 1        k: 2    *123
//                         (1)i: 2        k: 2    *123
//                         (2)i: 2        k: 2    *123
//2----                    (1)i: 0        k: 1    *123
//                         (2)i: 0        k: 1    *213
//3------213
//                         (3)i: 0        k: 1    *123
//                         (1)i: 1        k: 1    *123
//                         (2)i: 1        k: 1    *123
//3------123
//                         (3)i: 1        k: 1    *123
//                         (3)i: 2        k: 2    *123



