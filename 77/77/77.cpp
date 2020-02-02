#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	int n = 0;
	int a[20];
    int o = 0;
    int pls = 0;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
        pls = pls + a[i];
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

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n%d", pls);
}