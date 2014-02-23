/*
@20140219
@algorithm:
	1. 给出一个数，返回其在有序数组中得位置，不存在返回-1; 
	2. 注意防止整数溢出；
	3. 注意递归和非递归版本；	
	4. 注意边境条件；
	5. 注意查找方向；
*/

#include <stdio.h>

// 递归版本
int bsearch(int a[],int b, int e, int x) 
{
	int i = b + (e - b)/2;
	printf("i=%d, ", i);
	if (b > e) {
		return -1;
	}
	if (a[i] == x) {
		return i;
	} else if (a[i] < x) {
		return bsearch(a, i+1, e, x);
	} else {
		return bsearch(a, b, i-1, x);
	}		  	
}

// 非递归版本
int bsearch2(int a[], int len, int x)
{
	int low = 0; 
	int high = len;	
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2; // 防止整数溢出
		printf("mid=%d, ", mid);
		if (a[mid] == x) {
			return mid;
		} else if (a[mid] < x) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}	
	return -1;
}

int main()
{
	const int len = 10;
	int a[] = {-1, -2, -3, 2, 3, 8, 9, 12, 20, 100};
	int x = 100;
	int result = bsearch(a, 0, len-1, x);
	printf("%d is at index %d\n", x, result);
	int result2 = bsearch2(a, len-1, x);
	printf("%d is at index %d\n", x, result2);
}
