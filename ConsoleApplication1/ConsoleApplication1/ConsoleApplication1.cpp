#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void plus_print(int n, int m, int i)
{
	n = n + (i - 1);
	if (n > m) {
		return;
	}
	if (i % 2 == 0) {
		if (n % 2 != 0) {
			printf("%d ", n);
		}
	}
	if (i % 2 != 0) {
		if (n % 2 == 0) {
			printf("%d ", n);
		}
	}
	plus_print(n,m,++i);
}

int main()
{
	int n = 0, m = 0;
	scanf_s("%d %d", &n, &m);
	plus_print(n, m,1);
}