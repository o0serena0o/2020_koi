#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	int a = 0, b = 0;
	int k = 0, j = 0;

	scanf_s("%d %d", &a, &b);
	for (int i = a; i <= b; i++)
	{
		if (i % 2 == 0)
		{
			k = k + i;
		}
		if (i % 2 != 0)
		{
			j = j + i;
		}
	}
	printf("짝수합 : %d 홀수합 : %d", k, j);
}