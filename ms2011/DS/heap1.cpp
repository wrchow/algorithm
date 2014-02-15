// min heap for《编程之美》page 139
// by wrchow 20110917

#include <iostream>

#define PARAENT(i)  (i/2)
#define LEFT(i)     (2*i+1)
#define RIGHT(i)    (2*i+2)
using namespace std;

int t(0);

void printa(int a[],int n)
{
    for (int i=0; i<n; i++)
        cout << a[i] <<' ';
    cout << endl;
}
void swap(int* lhs, int* rhs)
{
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void minHeapify(int* a, int heapSize, int i)
{
    cout << ++t << ':'; //test   
    int l = LEFT(i);
    int r = RIGHT(i);
    int smallest;
    if(l < heapSize && a[l] < a[i])
        smallest = l;
    else
        smallest = i;
    if(r < heapSize && a[r] < a[smallest])
        smallest = r;
        
    if(smallest != i)
    {
        //cout << "smallest = " << smallest
        //        << ",i= " << i << endl;
        swap(a + i, a + smallest);
        printa(a, heapSize);
        minHeapify(a, heapSize, smallest); // 递归
    }    
    cout << endl;
}

// 创建最小堆
void buildMinHeap(int* a, int n)
{  
    //cout << "buildMinHeap.." << endl;
    for(int i = n/2-1; i >= 0; --i) {
        //cout << " minHeapify(a, n, i) " << i << endl;
        minHeapify(a, n, i);
    }
}

// 排序我也将着写了
void heapSort(int* a, int n)
{
    buildMinHeap(a, n);
    for(int i = n - 1; i >= 1; --i)
    {
        swap(a, a + i); // 取出头节点
        n -= 1;
        minHeapify(a, n, 0); // 重构第一个位置
    }
}

int main()
{   
    //int a[]  = {4,3,5,9,6,1,7,0,8,2};
    int a[] = {4,3,5,9,6,1};
    int n = sizeof(a)/sizeof(int);
    cout << "init.." ;
    printa(a,n);   
    //heapSort(a, n);
    buildMinHeap(a, n);
    cout << "build heap..";
    printa(a,n);
}