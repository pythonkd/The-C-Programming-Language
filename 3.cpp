#include <stdio.h>

void merge_sort(int*, int, int);
void merge(int*, int, int, int);
int main(void)
{
	int a[] = {1, 3, 2, 9, 7, 4, 0, 3, 2, 5, 1, 6};
	int n = sizeof(a)/sizeof(int);
	merge_sort(a, 0, n);
	for (int i=0;i<n;i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}

void merge_sort(int* a, int lo, int hi)
{
	if(hi-lo<2) return;
	int mi = (lo + hi)/2;
	merge_sort(a, lo, mi);
	merge_sort(a, mi, hi);
	merge(a, lo, mi, hi);
}

void merge(int* a, int lo, int mi, int hi)
{
	int left[mi-lo];
	int right[hi-mi];
	int i, j, k;
	for (i=lo;i<mi;i++)
	{
		left[i-lo] = a[i];
	}
	for (j=mi;j<hi;j++)
	{
		right[j-mi] = a[j];
	}
	i = j = 0;
	k = lo;
	while(i<(mi-lo) && j<(hi-mi))
	{
		if(left[i]<right[j])
		{
			a[k] = left[i];
			i++;
			k++;
		}
		else
		{
			a[k] = right[j];
			j++;
			k++;
		}
	}
	while (i<(mi-lo))
	{
		a[k] = left[i];
		k++;
		i++;
	}
	while(j<(hi-mi))
	{
		a[k] = right[j];
		k++;
		j++;
	}
}
