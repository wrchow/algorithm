//<beauty coding> page 217 
// 电话号码对应英文单词

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

char c[10][10] = 
{
    "",            //0
    "",            //1
    "ABC",         //2
    "DEF",         //3
    "GHI",         //4
    "JKL",         //5
    "MNO",         //6
    "PQRS",        //7
    "TUV",         //8
    "WXYZ",        //9 
};

const int total[10] = {0,0,3,3,3,3,3,4,3,4};
vector<int> num;
int ans[] = {0,0,0, 0,0,0, 0,0,0, 0};

void phwords1(); // 循环
void phwords2(int index, int n); // 递归

int main(int argc, char* argv[])
{
    assert(argc == 2);
    int n = atoi(argv[1]);
    int cnt=0; // the num of words
    if (n < 10) num.push_back(n);
    else {
        while ( n > 0) {
            num.push_back(n%10);
            n /= 10;
        }
    }
    if (num.size() > 0) {
        cnt = 1;
        int flag = 0;
        for (int i=0; i<num.size(); i++) {
            int tmp = 1;
            if(total[num[i]] > 1) {
                flag = 1;
                tmp = total[num[i]];
            }
            cnt *= tmp;
        }
    }
    cout << ">phwords1: " << cnt << endl;
    phwords1();
    cout << endl << ">phwords2: " << cnt << endl;
    phwords2(0, num.size());
    return 0;
}

void phwords1()
{
    while (true) {
        for (int i=0; i<num.size(); i++) {
            cout << c[num[i]][ans[i]] ;
        }
        cout << ", ";
        int k = num.size() - 1;
        while (k >= 0) {
            if (ans[k] < total[num[k]] - 1) {
                ans[k]++;
                break;
            } else {
                ans[k] = 0; k--;
            }
        }
        if (k < 0) break;
    }
}

// index 说明在号码的第几位进行循环
// n为
void phwords2(int index, int n)
{
    if (index == n) {
        for (int i=0; i<num.size(); i++) {
                cout << c[num[i]][ans[i]] ;
        }
        cout << ", ";
        return ;
    } 
    for (ans[index] = 0;
         ans[index] < total[num[index]];
         ans[index]++
        ) {
        phwords2(index+1,n);
    }
}














