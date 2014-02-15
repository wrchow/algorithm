// page 154 in  <<编程之美>> 寻找符合条件的整数N
// 任意给定一个正整数N，求一个最小的正整数M（M>1),使得N*M的十进制
// 表示形式里只含有1和0

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#define MAXINT 0x7fffffff
using namespace std;

bool isT(int x);
int findN1(int N);
void findN2(int N);
void printBigInt(vector<vector<int> > bg);

int main(int argc, char *argv[])
{
    const int N = atoi(argv[1]);
    cout << "FindN1: " << findN1(N) << endl;   
    cout << "FindN2: " << endl;
    findN2(N);
    //cout << "MAXINT = " << MAXINT;
    return 0;
}

bool isT(int x)
{
    while (x > 0) {
        if (x%10 != 1 && x%10 != 0) return false;
        x  = x/10;
    }
    return true;
}

int findN1(int N)
{
    int M;
    for ( M=2; M<MAXINT; M++) {
        if ( true == isT(M*N)) break;
        //cout << M << " ";
    }
    return M;
}

void findN2(int N)
{
    vector<int> tmp(0);
    vector<vector<int> > BigInt(N,tmp);
    for (int i=0; i<N; i++){
        BigInt[i].clear();
    }
    BigInt[1].push_back(0);
    
    int NoUpdate = 0; // 终止条件
    for (int i=1, j=10%N; ; i++, j=(j*10)%N) { // k次循环
        bool flag = false;
        if (BigInt[j].size() == 0) {
            flag = true;
            // bigInt[j] = 10^i, (10^i % N = j)
            BigInt[j].clear();
            BigInt[j].push_back(i);
        }
        for (int k = 1; k < N; k++) // N次循环
        {
            if ( (BigInt[k].size() > 0)
                  && (i > BigInt[k][BigInt[k].size() - 1])
                  && (BigInt[(k+j) % N].size() == 0)
                ) {
                // BigInt[(k+j)%N] = 10^i + BigInt[k]
                flag = true;
                BigInt[(k+j)%N] = BigInt[k];
                BigInt[(k+j)%N].push_back(i);
            }
        }
        if (flag == false) NoUpdate++;
        else NoUpdate = 0;
        if (NoUpdate == N || BigInt[0].size() > 0)
            break;
        cout << i << ":";
        printBigInt(BigInt);
    }
    if (BigInt[0].size() == 0)
    {
        cout << "M not exist" << endl;
    } else {
        //cout << "Find N * M = BigInt[0]" << endl;
    }
    int M = 0;
    for (int m = 0; m < BigInt[0].size(); m++) {
        M += pow(10,BigInt[0][m]);
        cout << BigInt[0][m];
    }
    cout << endl << " M = " << M << endl;
}

void printBigInt(vector<vector<int> > bg)
{
    for (int i=0; i<bg.size(); i++) {
        for (int j=0; j<bg[i].size(); j++) {
            cout << bg[i][j];
        }
        cout << endl;
    }
}












