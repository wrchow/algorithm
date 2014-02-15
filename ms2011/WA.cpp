// for Works Aplication interview
// by wr-chow 20110920

#include <iostream>
#include <deque>
#include <vector>
#include <cassert>
#include <ctime>
#include <list>
#include <cstdlib>
using namespace std;

template <typename E> class IStack
{
public:
    IStack(void) {}
    virtual ~IStack(void) {
        m_data.clear();
        m_minIdx.clear();
        m_maxIdx.clear();
        m_datalist.clear();
        m_listIdx.clear();
    }
public:    
    void push(E& e);
    E& pop(void);
    E& peekMedian(void);
    E& peekMaximum(void);
    E& peekMinimum(void) ;
    int size(){
        return m_data.size();
    }
private:
    deque<E>        m_data;// the elements of stack
    deque<size_t>   m_minIdx;// the indices of minimum elements
    deque<size_t>   m_maxIdx;
    deque<size_t>   m_midIdx;
    list<size_t>    m_datalist;// list idx of data
    deque<list<size_t>::iterator>   m_listIdx;
}; // IStack

template <typename E>
void IStack<E>::push(E& e){
    m_data.push_back(e);
    //cout<< "push.." << e << endl;
    if(m_datalist.empty()) { // init..
        m_datalist.push_back(0);
        m_minIdx.push_back(0);
        m_maxIdx.push_back(0);
        m_midIdx.push_back(0);
        m_listIdx.push_back(m_datalist.begin());
    } else {
        list<size_t>::iterator it = m_datalist.begin();
        for (; it!=m_datalist.end(); it++) {
            if (m_data[*it] > e) break;
        }
        m_datalist.insert(it,m_data.size()-1);
        m_listIdx.push_back(--it);
        m_minIdx.push_back(*m_datalist.begin());
        m_maxIdx.push_back(*(--m_datalist.end())); 
        it = m_datalist.begin();
        for (size_t i=0; i < m_datalist.size()/2; i++) it++;
        m_midIdx.push_back(*it);
    }        
}

template <typename E>
E& IStack<E>::pop(){
    cout << "pop.." <<endl;    
    m_data.pop_back();
    m_maxIdx.pop_back();
    m_minIdx.pop_back();
    m_midIdx.pop_back();   
    m_datalist.erase(m_listIdx.back());
    m_listIdx.pop_back();    
    return m_data.back();
} 

template <typename E>
E& IStack<E>::peekMaximum(){
    cout << "peekMaximum..";
    assert(m_data.size() > 0);
    assert(m_maxIdx.size() > 0);
    return m_data[m_maxIdx.back()];
}

template <typename E>
E& IStack<E>::peekMinimum(){
    cout << "peekMinimum..";
    assert(m_data.size() > 0);
    assert(m_minIdx.size() > 0);
    return m_data[m_minIdx.back()];
}

template <typename E>
E& IStack<E>::peekMedian(){
    cout << "peekMedian..";
    assert(m_data.size() > 0);
    assert(m_midIdx.size() > 0);
    return m_data[m_midIdx.back()];
}

void genv(vector<size_t> &v,int n)
{
	srand(time(0));
	for (int i=0; i<n; i++) {
		v.push_back(rand()%(2*n));
	}
}

int main(int argc, char* argv[])
{
    //int a[] = {2,3,1,4,5};
    //vector<int> v(a,a+5);
    assert(argc == 2);
    int n = atoi(argv[1]);
    vector<size_t> v;
    genv(v,n);
    IStack<size_t> istack;
    long s0 = clock();	
    for (size_t i=0; i<v.size(); i++) {
        istack.push(v[i]);
    }    
    long e0 = clock();
    cout << "it takes :" << (double)(e0-s0)/CLOCKS_PER_SEC 
            << "s to push "<< n << " datas. " << endl;
    long s1 = clock();	
    cout << istack.peekMaximum() << endl;
    cout << istack.peekMinimum() << endl;
    cout << istack.peekMedian() << endl;
    long e1 = clock();
    cout << "it takes :" << (double)(e1-s1)/CLOCKS_PER_SEC 
            << "s to peek!"<<endl;
    return 0;
}

/*
    ./wa 2000   13.3s to push.. 0s to peek!
       
*/
