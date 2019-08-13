#include <stdio.h>

void bubble_sort(int*, int);
int main(void)
{
	int a[] = {2, 4, 3, 7, 9, 19, 32, 6, 4, 1, 0};
	int hi = sizeof(a)/sizeof(int);
	bubble_sort(a, hi);
	for (int i=0;i<hi;i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}

void bubble_sort(int* list, int hi)
{
	for(int i=0;i<hi;i++)
	{
		for(int j=0;j<hi-1-i;j++)
		{
			if(list[j]>list[j+1])
			{
				int tmp;
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
				 
			}
		}
	}
}
