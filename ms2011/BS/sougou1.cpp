// sougou1.cpp by wrchow at 20110926-21:37~23:09
// 给出一个数组，求除va[i]的所有数之积组成对应数组ov[]
/*算法描述：
    设左右两个数组，left[],right[],ov[i]=left[i]*right[i]
*/
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void printv(vector<T> v){
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> va;
    vector<long long> left,right,ov;
    cout << "Input n: ";
    int a,n;
    cin >> n;
    for(int m=0; m<n; m++) {
        cin >> a;
        va.push_back(a);
    }
    long long l_mult=1;
    left.push_back(l_mult);
    for (int i=0; i<va.size()-1; i++) {
        l_mult *= va[i];     
        left.push_back(l_mult);
    }
    long long r_mult=1;
    right.push_back(r_mult);
    for (int j=va.size()-1; j>0; j--) {
        r_mult *= va[j];
        right.push_back(r_mult);
    }
    for (int k=0; k<va.size(); k++) {   
        ov.push_back(left[k]*right[va.size()-k-1]);
    }
    cout << "print left.." << endl;
    printv(left);
    cout << "print right.." << endl;
    printv(right);
    cout << "print ov.." << endl;
    printv(ov);
    return 0;
}