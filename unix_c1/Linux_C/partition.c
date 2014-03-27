#include <stdio.h>

#define LEN 11

int a[] = {2, 3, 8, 1, 0, 4, 7, 5, 6, 11, 9};

void swap(int index1, int index2)
{
	int tmp = a[index1];
	a[index1] = a[index2];
	a[index2] = tmp;
}


int  partition(int l, int e)
{
	if(l > e)
		return;
	int m = l;
	int i;
	for (i = l+1; i <= e; i++)
	{
		if(a[i] < a[l])
			swap(++m, i);
	}

	swap(l, m);
	return m;
}

void sort(int start, int end)
{
	int mid;
	if (end > start)
	{
		mid = partition(start, end);
		sort(start, mid - 1);
		sort(mid + 1, end);
	}
}

void print()
{
	int i;
	for (i = 0; i < LEN; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	sort(0, LEN - 1);
	print();
	return 0;
}
