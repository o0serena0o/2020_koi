#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int a[10];

int main()
{
	long jam = 0;
	int non = 0;

	scanf_s("%d", &jam);


	while (jam != 0)
	{
		int o = jam % 10;
		a[o] = a[o] + 1;
		jam = jam / 10;
	}

	for (int i = 1; i < 10; i++)
	{
		if (a[i] >= non)
		{
			non = i;
		}
	}
	printf("%d", non);
}