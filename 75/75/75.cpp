#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	int a[20];
	int n = 0;
    int o = 0;
	
    scanf_s("%d", &n);
	
    for (int i = 0; i < n; i++)
    {
		scanf_s("%d", &a[i]);
	}

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
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

    return 0;
}