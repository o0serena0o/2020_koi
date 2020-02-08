#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	long jam = 0;
	int k = 0;
	int cnt = 0;

	scanf_s("%d", &jam);
	scanf_s("%d", &k);


	while (jam / 10 != 0)
	{
		if (jam % 10 == k)
		{
			cnt++;
			jam = jam / 10;
		}
		else
		{
			jam = jam / 10;
		}
	}
	printf("%d", cnt);
}