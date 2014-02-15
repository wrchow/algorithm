// qsort again
// by wrchow 20110923

#include <iostream>
#include <vector>

using namespace std;

void qsort(vector<int>& v,int s, int e){
// Asending
    //cout << "qsort.. in Asending .." << endl;
    if(e-s <= 0) return;
    int i(s),j(e);
    int pivot = v[(s+e)/2];
    cout << "pivot = " << pivot << endl;
    do {
    while (v[i]<pivot && i<e) i++;
    while (v[j]>pivot && j>s) j--; // j--
        if (i <= j) {
            if(i != j){
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp; // note          
            }
            i++;
            j--;
        }
    } while (i <= j);      
    if(j>s) qsort(v,s,j);
    if(i<e) qsort(v,i,e);
}

void printv(vector<int>& v){
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int a1[] = {3,8,7,9,6};// swap(8,6), {3,6,{7},9,8}, swap(9,8)
    int a[] = {1,2,2,2,2};
    vector<int> v(a,a+5);
    printv(v);
    qsort(v,0,v.size()-1);
    cout << "after qsort .. " << endl;
    printv(v);
    return 0;
}

int Partition(vector<int> &A, int s, int e )
{// Asending 
    int p_pos,tmp,i,j;//中间点位置    
    p_pos = s; //假设中间点位置在第一位
    //假设中间点值为第一位元素的值 注意中间点元素的值是确定的 假设第一位 但是中间点元素的正确位置需要我们找
    int pivot = A[p_pos];
    for(i=s+1; i<=e; i++){    //从第二位开始查找 发现i位元素小于中间点值
        if(A[i] < pivot){
          p_pos++; //中间点位置右移一位        
          swap<int>(A[p_pos],A[i]);//交换此刻中间点位置所在元素与第i位元素的值
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
        QuickSort(A,p,r-1);
        QuickSort(A,r+1,q);
    }
}