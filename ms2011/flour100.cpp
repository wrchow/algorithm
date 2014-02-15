// by wr-chow at 20110806
//
// discription:
// for <Interview programmer>, page 316
// use two glass chessman to measure the critical floor 
// of a 100 floor building
//
// solution:
// span = 14; expt =9; worst = 19; 
// span = 14-- ; expt = 9; worst = 14;
#include <iostream>
#include <cassert>
using namespace std;

int twostep1(int span, int F);
int twostep2(int span, int F);
void work(int method);

int main()
{
    cout << "Floor 100 Problem !? " << endl << endl;
    cout <<endl << "work(1)" << endl;
    work(1);
    cout <<endl << "work(2)" << endl;
    work(2);
    return 0;
} // main()

// span1 = span, span2 = 1
int twostep1(int span, int F)
{
    int times = 0;
    assert(span > 0 && span < 101);
    assert(F > 0 && F < 101);
    times = F % span + F / span;
    return times;
} // int twostep(int span)

// span1 = span--, span2 = 1
int twostep2(int span, int F)
{
    int times = 0;
    assert(span > 0 && span < 101);
    assert(F > 0 && F < 101);  
    int cnt = 0;
    while(cnt < F && span > 0) {
        times ++;
        cnt += span--;
        //cout << cnt << ", " << span+1 << ";" ;
    }    
    //cout << endl;
    return times + F - cnt + span;
} // int twostep(int span)

void work(int method)
{
    for (int i = 10; i < 20; i++ ) {
        int worst_value = 0;  
        int worst_floor = 0;
        float expt = 0;
        int sum = 0;
        cout << ">>> span = " << i << endl;
        for (int j = 1; j <= 100; j++) {
            int times = 0;
            if (method == 1) {
                times = twostep1(i, j);
            } else if (method == 2) {
                times = twostep2(i, j);
            }
            //cout << "times: " << times << endl;
            if (worst_value < times) {
                worst_value = times;
                worst_floor = j;
            }
            sum += times;
        }
        expt = sum / 100;
        cout << "expt = " << expt << ", worst_value = " << worst_value  
              << ", worst_floor = " << worst_floor << endl << endl;
    }
}














