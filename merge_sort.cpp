#include <stdio.h>

void merge_sort(int*, int, int);
void merge(int*, int, int, int);

int main(void)
{
	int a[] = {2, 10, 12, 0, 8, 34, 65,90, 23,7, 5, 4, 8, 5, 9, 6, 1, 23, 5, 8};
	int n = sizeof(a)/sizeof(int);
	merge_sort(a, 0, n);
	for(int i=0;i<n;i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}

void merge_sort(int* a, int lo, int hi)
{
	if (hi -lo <2) return;
	int mi = (lo + hi) >> 1;
	merge_sort(a, lo, mi);
	merge_sort(a, mi, hi);
	merge(a, lo, mi, hi);
}

void merge(int* a, int lo, int mi, int hi)
{
	int left[mi-lo];
	int right[hi-mi];
	int i;
	
	for (i=lo;i<mi;i++) left[i-lo] = a[i];
	
	for (i=mi;i<hi;i++) right[i-mi] = a[i];
	
	int j, k;
	i = 0; j = 0; k = lo;
	while (i<(mi-lo) && j<(hi-mi))
	{
		if(left[i]<right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<(mi-lo))
	{
		a[k] = left[i];
		k++;
		i++;
	}
	while (j<(hi-mi))
	{
		a[k] = right[j];
		k++;
		j++;
	}
}
