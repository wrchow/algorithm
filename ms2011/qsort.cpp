//
// const char * to char *
// http://apps.hi.baidu.com/share/detail/15395947
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Print(const vector<int> v);
void sort(int a[],int n);
void qs(char * items, int left, int right);
void QuickSort(vector<int> &v, int s, int e);
void QuickSort(int v[], int s, int e);

int main(int argc,char *argv[])
{
    // sort   
	int v[] = {5,7,6,4,8};
	int len = sizeof(v)/sizeof(int);
    cout << "len = " << len << endl;
    //cout << "1. &a = " << &a << endl;
	//sort(v,len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ",v[i]);
	} cout << endl;
	//printf("\nmax = %d\nmin = %d\n",a[0],a[n-1]);
    
    // Quicksort
    /*
    string str(argv[1]);   
    char *p1 = new char[str.size()+1]; 
    strcpy(p1,str.c_str()); 
    qs(p1,0,str.size()-1);
    cout << "1. After QuickSort: " << p1 << endl;
    */
    //int v[] = {5,7,6,4,8};
    //int len = sizeof(v)/sizeof(int);
    QuickSort(v,0,len-1);
    cout << "2. After QuickSort: " ;
    for (int i=0; i<len; i++) cout << v[i] << ' ';
    cout << endl;
    
    return 0;
} 

void Print(const vector<int> v)
{
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void sort(int a[],int n)
{
	int t;
	for (int i = 0; i < n;i++)
	{
		for (int j = i +1; j < n; j ++)
		{
			if(a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}


/* The Quicksort. */
void qs(char * items, int left, int right)
{
    register int i, j;
    char x, y;
    i=left;j=right;
    x=items[(left+right)/2];
    do
    {
        while((items[i]<x)&&(i<right))i++;
        while((x<items[j])&&(j>left))j--;
        if(i<=j)
        {
            y=items[i];
            items[i]=items[j];
            items[j]=y;
            i++;j--;
        }
    }while(i<=j);
    if(left<j)qs(items,left,j);
    if(i<right)qs(items,i,right);
}

void QuickSort(vector<int> &v, int s, int e)
{// desencding
    Print(v);
	if(e-s<=1) return;
	//srand(time(0));
	//int M = v[rand()%(e-s+1)]; // pivot
	int M = v[(e+s)/2]; //cout << "pivot: " << M << endl;
	int i(s);
	int j(e);
	do
	{
		while(v[i]>=M && i<e) i++;
		while(v[j]<=M && j>s) j--;
		if (i <= j) {
            //cout << "swap " << i+1 << "i" << v[i] << ", " << j+1 << "j" << v[j] << endl;
			int tmp = v[j];
			v[j] = v[i];
			v[i] = tmp;
			i++;
			j--;
		}
	} while(i<=j);
	if (s < j) {
        //cout << "s= " << s <<", j= " << j << endl;
		QuickSort(v,s,j);
	}
	if (e > i) {
        cout << "i= " << i <<", e= " << e << endl;
		QuickSort(v,i,e);
	}
}


void QuickSort(int v[], int s, int e)
{
    //cout << "v[]" << endl;
    if (e-s<=0) return;
    int i(s),j(e),tmp;
    int M = v[(s+e)/2];
    //cout << i << ", " << j << endl;
    do {
        while(i<e && v[i]>M) i++;
        while(j>s && v[j]<M) j--;
        //cout << i << ", " << j << endl;
        if (i<=j) {
            //cout << i << ", " << j << endl;
            if (i != j){
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            }
            i++;
            j--;
        }
    } while(i<=j);
    if(s<j) QuickSort(v,s,j);
    if(i<e) QuickSort(v,i,e);
}
