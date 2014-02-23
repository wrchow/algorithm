// bit sort for pearls
// 2014-02-01

#include <stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0X1F
#define N 10000000

int a[1 + N/BITSPERWORD];

void set(int i) { a[i>>SHIFT] |= (1<<(i & MASK));} 
void clr(int i) { a[i>>SHIFT] &= ~(1<<(i & MASK));} 
int test(int i) {return a[i>>SHIFT] & (1<<(i & MASK));} 

int main()
{
	int i = 10;
	printf("test(i)=%d\n", test(i));
}
