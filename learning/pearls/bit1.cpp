// pearl practise 1.2
// 2014-01-31

#include <iostream>
#include <cstdlib>
using namespace std;

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000



int a[1 + N/BITSPERWORD];

void set(int i) {
	a[i>>SHIFT] |= (1<<(i & MASK)); 
}

void clr(int i) {
	[i>>SHIFT] &= ~(1<<(i & MASK));
}

int test(int i)
{
	return a[i>>SHIFT] & (1<<(i & MASK));
}

int main(void)
{
	int i = 10;
	cout << set(i) << endl
		<< clr(i) << endl
		<< test(i) << endl;		
}

