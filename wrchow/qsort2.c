/**
@20140220
@qsort第二遍
*/

#include <stdio.h>

int partition(int a[], int begin, int end)
{
	int x = a[end];
	int q = begin;
	int j = begin;
	while (j < end) {
		if (a[j] < x) {
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
//error:	if (end > begin) {
	if (begin >= end) {
		return ;
	}
	int q = partition(a, begin, end);
	qsort(a, begin, q-1);
	qsort(a, q+1, end);
}

int main()
{
	const int len = 5;
	int a[len] = {3,5,1,4,3};
	qsort(a, 0, len-1);
	for (int i=0; i<len; i++)
		printf("%d ", a[i]);
	printf("\n");
}
