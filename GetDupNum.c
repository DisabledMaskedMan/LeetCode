#include <stdio.h>

int GetDupNum(int* a, int n, int* Index)
{
	for (int i = 0; i < n; i++)
	{
		while (a[i] != i)
		{
			if (a[a[i]] == i)
			{
				Swap(&a[a[i]], &a[i]);
				break;
			}
			if (a[a[i]] == a[i])
			{
				*Index = i;
				return a[i];
			}
			Swap(&a[a[i]], &a[i]);
		}
	}
	return -1;
}

void Text1()
{
	/*int a = 1;
	int b = 2;
	int c = a > b ? a++ : b++;
	printf("%d %d %d", a, b, c);*/

	int a[] = { 2, 3, 1, 0, 6, 5, 3 };
	int Index1 = 0;
	int Index2 = GetDupNum(a, sizeof(a) / sizeof(a[0]), &Index1);
	printf("Index1 %d = %d , Index2 %d = %d", Index1, a[Index1], Index2, a[Index2]);
}
