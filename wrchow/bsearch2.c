/**
@20140220
二分查找第2次
23:07~
*/
#include <stdio.h>

int bsearch(int a[], int len, int x)
{
	int low = 0;
	int high = len - 1;
	int mid;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (a[mid] == x) {
			return mid;
		} else if (a[mid] > x) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1; 
}


int main()
{
	const int len = 5;
	int a[] = {1,3,8,9,12};	
	int x = 9;
	printf("%d is in %dth of a.", x, bsearch(a,len,x));
}
