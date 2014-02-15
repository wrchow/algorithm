// dianp1.cpp
// 大众点评第1题
// 描述：
//      Input:  一个n个数的数组,其中某个数字出现次数大于N/2;
//      Outpu:  找出那个数
//              

#include <iostream>
#include <vector>
using namespace std;

int findk(vector<int> a); // 计数法，连续相同则加，否则减
int rfindk(vector<int> a,int s,int e); // 快排划分法,传值,以中间值划分的方式不适合
int Partition(vector<int> &A, int s, int e );
void QuickSort2( vector<int>& A, int p, int q );

int main()
{
    int a[] = {1,2,3,2,2,2,5}; // test
    vector<int> v(a,a+7);
    cout << findk(v) << endl;
    cout << rfindk(v,0,7) << endl;
    return 0;
}

int findk(vector<int> a){
    if (a.size() < 0) return -1;   //设置记录找不到的状态;
    int i,vn(a[0]),cnt(1); 
    for (i=1; i< a.size(); i++) {        
        if(a[i] == a[i-1]) cnt ++;           
        else cnt --;    
        if(cnt == 0) vn = a[i];        
    }
    return vn;
}

int rfindk(vector<int> a,int s,int e){
    int r = Partition(a,s,e);
    if (e-s > a.size()/2) return a[(s+e)/2];
    if (e-r > r-s) rfindk(a,r+1,e);
    else rfindk(a,s,r-1);
}

int Partition(vector<int> &A, int s, int e )
{// Asending 
    int p_pos,tmp,i,j;//中间点位置    
    p_pos = s; //假设中间点位置在第一位
    //假设中间点值为第一位元素的值 注意中间点元素的值是确定的 假设第一位 但是中间点元素的正确位置需要我们找
    int pivot = A[p_pos];
    for(i=s+1; i<=e; i++){ //从第二位开始查找 发现i位元素小于中间点值
        if(A[i] < pivot){
          p_pos++; //中间点位置右移一位        
          if(p_pos != i) swap<int>(A[p_pos],A[i]);//交换此刻中间点位置所在元素与第i位元素的值
        }
    }
    //此时已经找到中间点元素所在正确位置 将中间点元素位置的值与假设第一位为中间点值交换 
    swap<int>(A[s],A[p_pos]);       
    return p_pos; //返回该中间点位置
}

void QuickSort2( vector<int>& A, int p, int q )
{
    if( p < q )
    {
        int r = Partition(A, p, q);
        QuickSort2(A,p,r-1);
        QuickSort2(A,r+1,q);
    }
}











