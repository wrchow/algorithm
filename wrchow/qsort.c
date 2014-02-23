/**
* 20140219
*
* algorithm:
* 1. 给定数组a[len],起始点begin,终点end=len-1;
* 2. 选定最后一个数为划分点q；
* 3. j从0循环到end-1;
* 4. j++直到该数小于划分点，则进行swap,最后将数组划分为两部分；
* 5. 最后一个数和划分点位交换,从而完整地分为二个部分；
* 6. 递归调用划分q = partition(a,begin,end);
* 7. qsort(a,begin,q); qsort(a,q+1,end); 
* 8. 直到begin>=end结束；
*
*时间复杂度：
* 1. 最坏的情况下假设每次划分都不均匀：
*	T(n) = T(n-1) + O(n) = O(n^2);
* 2. 最好的情况下假设每次都均分：
*	T(n) <= 2T(n/2) + O(n) = O(n*log(n));
*/


#include <stdio.h>

int partition(int a[], int begin, int end)
{
	int x = a[end];
	int q = begin;
	int j = begin;
	while (j < end) {
		if (a[j] > x) {
			int tmp = a[q];
			a[q] = a[j];
			a[j] = tmp;
			q++;
		}	
		j++;
	}
	int tmp = a[end];
	a[end] = a[q];
	a[q] = tmp; 
	return q;
}

void qsort(int a[], int begin, int end)
{
	if (begin >= end) {
		return;
	}
	int q = partition(a, begin, end);
	//printf("q:%d\n", q);
	qsort(a, begin, q-1);
	qsort(a, q+1, end);
}

int main()
{
	const int len = 5;
	int a[len] = {3,2,9,8,3};
	qsort(a, 0, len-1);
	for (int i=0; i<len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

