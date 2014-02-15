// fibonacci <beauty coding> page 159

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int fb1(int N); // original recursion
int fb2(int N); // vector
int fb3(int N); // formula

int main(int argc, char* argv[])
{
    if (argc > 2) return -1;
    int N = atoi(argv[1]);
    long s0,e0;
    
    // fb3
    s0 = clock();
    cout << "fb3: " << fb3(N) << endl;
    e0 = clock();
	cout << "it takes :" << (double)(e0-s0)/CLOCKS_PER_SEC << "s. "<< endl;
    
    // fb2
    s0 = clock();
    cout << "fb2: " << fb2(N) << endl;
    e0 = clock();
	cout << "it takes :" << (double)(e0-s0)/CLOCKS_PER_SEC << "s. "<< endl;
    
    // fb1
    s0 = clock();
    cout << "fb1: " << fb1(N) << endl;
    e0 = clock();
	cout << "it takes :" << (double)(e0-s0)/CLOCKS_PER_SEC << "s. "<< endl; 
    
    return 0;
}

int fb1(int N)
{
    if (N <= 0) return 0;
    if (N == 1) return 1;
    else return fb1(N-1) + fb1(N-2);
}

int fb2(int N)
{
    vector<int> v2;
    v2.clear();
    v2.push_back(0);
    v2.push_back(1);
    for (int i=2; i<=N; i++) {
        v2.push_back(v2[i-1]+v2[i-2]);
    }
    return v2[N];
}

int fb3(int N)
{
    if (N <= 0) return 0;
    if (N == 1) return 1;
    else {
        float A = sqrt(5);
        float B = (1+A)/2;
        float C = (1-A)/2;
        return (A*pow(B,N) - A*pow(C,N))/5;
    }
}








