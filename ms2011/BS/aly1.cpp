// 不用任何循环语句，库函数求一个输入字符串的长度

#include <iostream>
using namespace std;

int lens(char *s){
     if(*s == '\0') return 0;
     else return 1+lens(++s);
}

int main(int argc,char *argv[])
{
    char * s = argv[1];
    cout << lens(s) << endl;
    return 0;
}
