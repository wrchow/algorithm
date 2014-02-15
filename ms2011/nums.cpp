// random nums
// by wrchow@20110830

#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> genv(int n); 
void Print1(int v[]);
void Print(const vector<int> v);
void Print(string s, const vector<int> v);
void BubbleSort(vector<int> &v); // note &
void QuickSort(int v[], int s, int e);
void QuickSort(vector<int> &v, int s, int e);
void Write(){};
void Read(){};

int main()
{
	vector<int> v1,v2;
	int N;
	cout << "N = " ; cin >> N;
	v1 = genv(N);
	v2 = v1;
	Print("v1: ", v1);
	BubbleSort(v1);
	Print("v1 after bubble sort: ", v1);	
	Print("v2: ", v2);
	QuickSort(v2,0,N-1);
	Print("v2 after Quick sort: ", v2);
    int v[] = {5,8,6,7,4,9}; 
    QuickSort(v,0,5);
    int len = sizeof(v)/sizeof(v[0]);
    for (int i=0; i<len; i++) 
        cout << v[i] << ' ';
    cout << endl;
    //Print1(v);
  
}

vector<int> genv(int n)
{
	vector<int> v;
	srand(time(0));
	for (int i=0; i<n; i++) {
		v.push_back(rand()%(2*n));
	}
	return v;
}
void Print1(int v[])
{
    int len = sizeof(v)/sizeof(v[0]);
    cout << "len = " << len << endl;
    for (int i=0; i<len; i++) 
        cout << v[i] << ' ';
    cout << endl;
}

void Print(const vector<int> v)
{
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void Print(string s,const vector<int> v)
{
	cout << s ;
	Print(v);
}

void BubbleSort(vector<int> &v)
{ // desending
	for (int i=0; i<v.size(); i++) {
		//int tmp;
		for (int j = v.size()-1; j>i; j--) {
			int tmp;
			//cout << tmp << " ";
			if (v[j] > v[j-1]) {
				tmp = v[j];
				v[j] = v[j-1];
				v[j-1] = tmp;
			}
		}
	}
	Print("bubblesort: ", v);
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
    if (s-e<=0) return;
    int i(s),j(e);
    int M = v[(s+e)/2];
    do {
        while(i<e && v[i]>M) i++;
        while(j>s && v[j]<M) j--;
        if (i<=j) {
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    } while(i<=j);
    if(s<j) QuickSort(v,s,j);
    if(i<e) QuickSort(v,i,e);
}






