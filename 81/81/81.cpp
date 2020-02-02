#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	int n = 0;
	int max = -1000, min = 1000;
	int o = 0;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &o);
		if (o > max) {
			max = o;
		}
		if (o < min) {
			min = o;
		}
	}
	printf("\n최댓값 : %d 최솟값 : %d 합 : %d", max, min, max + min);
}