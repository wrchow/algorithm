// hht17.cpp  by wrchow 20110926 23:30~24:08
/*
程序员面试题精选100 题(17)－把字符串转换成整数
题目：输入一个表示整数的字符串，把该字符串转换成整数并输出。
例如输入字符串"345"，则输出整数345。
*/

#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int main(int argc, char* argv[])
{
    assert(argc == 2);
    string a = argv[1];
    if(a.empty()) return -1;
    int num,i=0,flag=1;
    if (a[i] == '+') {
        i++;
        num = a[i++] - '0';
    } else if(a[i] == '-'){
        flag = -1;
        i++;
        num = a[i++] - '0';
    } else {
        num = a[i++] - '0';
    }
    for (; i<a.size(); i++) {
        num *= 10;
        num += (a[i]-'0');
    }    
    cout << num*flag << endl;
    return 0;
}