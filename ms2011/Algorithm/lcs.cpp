// dynamic plan for LCS problem 20111020 23:50~
/* description:
    1. construct a matrix of LCS path
    2. find LCS in the path
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> row;
typedef vector<row> Matrix;

void pathLCS(string A,string B,Matrix& c);
void LCS(const Matrix& c);
void printMatrix(const Matrix& c);

int main(int argc,char *argv[]){
    // find "ACD"  & "BCS"
    string A = "ABCD";
    string B = "BACD";
    vector<int> t(A.size()+1,0);
    Matrix c(B.size()+1,t);   
    printMatrix(c);
    pathLCS(A,B,c);
    printMatrix(c);
    LCS(c);
    return 0;
}

void pathLCS(string A,string B,Matrix& c){
    cout << "path matrix.." << endl;
    int i,j;
    for (i=1; i<=B.size(); i++) {
        for (j=1; j<=A.size(); j++) {
            if (B[B.size()-i+1] == A[A.size()-j+1]) // reverse A & B
                c[i][j] = c[i-1][j-1] + 1;
            else if(c[i-1][j] > c[i][j-1]) c[i][j] = c[i-1][j];
            else c[i][j] = c[i][j-1];
        }
    }
}

void LCS(const Matrix& c){
    // print all the path from bottom to up by dfs
    if(c.size() == 0) return;
    int m = c[0].size(), r = c.size(); // columns & rows
    int i(r),j(m);
    
}

void printMatrix(const Matrix& c){
    for (int i=0; i<c.size(); i++) {
        for (int j=0; j<c[i].size(); j++) {
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }        
}










