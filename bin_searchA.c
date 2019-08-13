#include <stdio.h>

int bin_searchA(int*, int, int, int);
int main(void)
{
	int a[] = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a)/sizeof(int);
	printf("index=%d\n",bin_searchA(a, 8, n , 9));
	return 0;
}

int bin_searchA(int* a, int lo, int hi, int value)
{
	int mi;
	while(1<(hi-lo))
	{
		mi = (lo+hi)>>1;
		printf("mi=%d\n",mi);
		if (value<a[mi]) hi=mi;
		else lo=mi;
	}
	printf("lo=%d\n",lo);
	if (a[lo]==value) return lo;
	return -1;
}
