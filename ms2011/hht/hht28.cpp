//hht28 打印字符串的所有排列

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void permutation(char *s,char *begin);

int main(int argc,char *argv[])
{
    assert(argc==2);
    char* s = argv[1];
    permutation(s,s);
    return 0;
}

void permutation(char *s,char *begin) {
    if(!s || !begin) return;
    //cout << *begin << endl;
    if(*begin == '\0') cout << s <<' ';   
    else {
        for(char *pch = begin; *pch != '\0'; pch++) { 
            //swap(*pch, *begin);
            char temp = *pch;
            *pch = *begin;
            *begin = temp;
            permutation(s, begin+1); // note ++begin 不能改变begin本身
            //swap(*pch, *begin);
            temp = *pch;
            *pch = *begin;
            *begin = temp;
        }
    }
}
 