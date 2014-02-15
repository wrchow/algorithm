//<beauty coding> page 221
//计算字符串的相似度（求编辑距离）

#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;

int editdst(string A, string B, int dst);
int editdst2(string A, string B);// optimised by adding space
void PrintArray(vector<vector<int> >);
int min3(int t1,int t2,int t3){
    return (t1>t2?t2:t1)>(t2>t3?t3:t2)?(t2>t3?t3:t2):(t1>t2?t2:t1);
}

int main(int argc, char* argv[])
{
    assert(argc == 3);
    string A(argv[1]), B(argv[2]);
    long s,e;
    // editdst2
    s = clock();
    cout << "The distance between '" << A << "' and '" 
        << B << "' is " << 1.0/editdst2(A,B) << endl; 
    e = clock();
    cout << "editdst2>It takes " << (double)(e-s)/CLOCKS_PER_SEC << "s." <<endl;
    // editdst1
    s = clock();
    cout << "The distance between '" << A << "' and '" 
        << B << "' is " << 1.0/editdst(A,B,0) << endl; 
    e = clock();
    cout << "editdst1>It takes " << (double)(e-s)/CLOCKS_PER_SEC << "s." <<endl;
    return 0;
} 

// 有删除，修改，增加三种走法，挑出距离最小的
// 无论怎么走只有 t1,t2,t3三种情况
int editdst(string A, string B, int dst)
{
    if (A == B) return (1 + dst);
    else if (A.size() == 0) return (1 + B.size() + dst);
    else if (B.size() == 0) return (1 + A.size() + dst);
    else if (A[0] == B[0]) return editdst(A.erase(0,1),B.erase(0,1),dst);
    else {
        int t1 = editdst(A.erase(0,1),B,dst+1); // insert || delete
        int t2 = editdst(A,B.erase(0,1),dst+1); // insert || delete
        int t3 = editdst(A.erase(0,1),B.erase(0,1),dst+1); // change
        // min3(t1,t2,t3)
        return min3(t1,t2,t3) + 1;
    }
}

int editdst2(string A, string B)
{
    int i,j;
    vector<int> cc(B.size()+1,0); 
    vector<vector<int> > c(A.size()+1,cc); // Record dst
    
    for (i=0; i<A.size(); i++) c[i][B.size()] = A.size() - i + 1;
    for (j=0; j<B.size(); j++) c[A.size()][j] = B.size() - j + 1;
    c[A.size()][B.size()] = 0;
 
    for (i=A.size()-1; i>=0; i--) {
        for (j=B.size()-1; j>=0; j--) {
            if (A[i] == B[j]) c[i][j] = c[i+1][j+1];
            else 
                c[i][j] = min3(c[i][j+1], c[i+1][j], c[i+1][j+1])+1;
        }
    }     
    PrintArray(c);
    return c[0][0];
}

void PrintArray(vector<vector<int> > a)
{
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}









