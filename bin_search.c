#include <stdio.h>

int bin_search(int* a, int lo, int n, int);

int main(void)
{
	int a[] = {2, 3, 5, 6, 7, 10, 10, 13, 15};
	int n = sizeof(a)/sizeof(int);
	printf("%d\n", bin_search(a, 0, n, 15));
	return 0;
}

int bin_search(int* a, int lo, int hi, int value)
{
	int mi;
	while(lo<=hi)
	{
		mi = (lo+hi)>>1;
		if(a[mi]<value) lo = mi+1;
		else if (value<a[mi]) hi = mi-1;
		else return mi;
	}
	return -1;
}
