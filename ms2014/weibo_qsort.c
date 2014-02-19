/**
* sina_weibo qsort.c 20140218
* 问题描述：
* @r: 要排序的数组
* @s: 排的起点，从0开始
* @e: 排得终点，从n-1开始
*/

#include <stdio.h>

void quicksort(int r[1001], int s, int e)
{
	int t = r[s]; // 哨兵，为开头的那个
	int f = s + 1;
	int b = e; // f为前向指针，从s+1开始，b为反向指针，从e开始
	int m = 0;
	if ( s >= e) return; // 退出条件

	while (f <= b)
	{
		while(f <= b && r[f] <= t) f++; //在前面找比哨兵大的元素
		while(f <= b && r[b] >= t) b--; //在后面找比哨兵小的元素
		// 交换这两个元素
		if (f < b) {
			m = r[f];
			r[f] = r[b];
			r[b] = m;
			f++;  b--;
		}	
	}
	// 交换哨兵和r[b],r[b]肯定比哨兵小
	r[s] = r[b];
	r[b] = t;
	// 排两边的
	quicksort(r, s, b-1);
	quicksort(r, b+1, e);
}

int main()
{
	const int L = 5;
	int array[L] = {3, 5, 2, 9, 1};

	quicksort(array, 0, L);

	for (int i=0; i<L; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
