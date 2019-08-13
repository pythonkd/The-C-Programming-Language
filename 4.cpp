#include <stdio.h>

void merge(int* a, int lo, int mi, int hi);
int main(void)
{
	int a[] = {7, 8, 9, 10, 1, 2, 3, 4, 5};
	int n = sizeof(a)/sizeof(int);
	merge(a, 0, 4, n);
	for(int i=0;i<n;i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
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
