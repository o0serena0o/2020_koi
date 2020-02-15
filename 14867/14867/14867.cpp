#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a, b, A, B;
int x, y;
int check[1000][1000];

void solve(int a, int b, int cnt)
{
	if (a == x && b == y)
	{
		printf("%d", cnt);
		return;
	}
	printf("%d %d %d", a, b, cnt);
	if (check[A][b] == 0)
	{
		check[A][b] = 1;
		solve(A, b, cnt+1);
	}
	if (check[a][B] == 0)
	{
		check[a][B] = 1;
		solve(a, B, cnt+1);
	}
	if (check[0][b] == 0)
	{
		check[0][b] = 1;
		solve(0, b, cnt+1);
	}
	if (check[a][0] == 0)
	{
		check[a][0] = 1;
		solve(a, 0, cnt+1);
	}
	if (check[0][a + b] == 0)
	{
		if (a < B - b)
		{
			check[0][a + b] = 1;
			solve(0, a + b, cnt+1);
		}
	}
	if (check[a - (B - b)][B] == 0)
	{
		if (a > B - b)
		{
			check[a - (B - b)][B] = 1;
			solve(a - (B - b), B, cnt+1);
		}
	}
}

int main()
{
	scanf_s("%d %d %d %d", &A, &B, &x, &y);
	solve(0, 0, 0);
}