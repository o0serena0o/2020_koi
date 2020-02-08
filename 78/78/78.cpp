#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	int n = 0;
	int a[20];
	int min_b = 0;
	int min_a = 0;
	int o = 0;
	int min = 10000;

	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] < min)
		{
			min = a[i];
			min_b = i;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				o = a[j];
				a[j] = a[j + 1];
				a[j + 1] = o;
			}
		}
	}

	min_a = n - 1;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n%d", min_a - min_b);
}