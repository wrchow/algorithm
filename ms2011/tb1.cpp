// taobao±  ‘Ã‚@20110921

#include <iostream>
using namespace std;

int s(int x) {
    int cnt = 0;
    while (x) {
        cnt ++;
        cout << x << ',' << x-1 << '=';
        x = x&(x-1);
        cout << x << endl;
    }
    return cnt;
}

void to2(int n) {
    if(n < 2) {
        cout << n;
        return ;
    }   
    else if(n >= 2) {
        to2(n/2);
        cout << n%2;
    }
}

int main(int argc, char *argv[])
{
    cout << s(999) << endl;
    //cout << "768,512,511 : " <<endl; 
    to2(768);cout << endl;  
    to2(512);cout << endl;  
    to2(511);cout << endl;     
    return 0;
}

 