#include <stdio.h>

void bubble_sort(int*, int);
int main(void)
{
	int a[] = {2, 7, 9, 5, 3, 2, 1, 0, 10, 72};
	int n = 10;
	bubble_sort(a, n);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}

void bubble_sort(int* list, int size)
{
	int i, j,k, tmp;
	int sorted;
	for (i=0;i<size;i++)
	{
		sorted = 1;
		for(j=0;j<size-i-1;j++)
		{
			if(list[j]>list[j+1])
			{
				sorted = 0;
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
		}
		if (sorted) break;
	}
}
