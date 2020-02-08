#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	long jam = 0;
	int k = 0;

	scanf_s("%d", &jam);
	scanf_s("%d", &k);

	
	while (jam/10 != 0)
	{
		if (jam % 10 == k)
		{
			printf("저 여기있어요~");
			break;
		}
		else
		{
			jam = jam / 10;
		}
		if (jam / 10 == 0)
		{
			printf("여기 없어요~");
		}
	}
}