#include <bits/stdc++.h>

using namespace std;

bool table[2001][2001] = { 0, };

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	int x;
	int y;
	int result = 0;
	scanf_s("%d %d", &x, &y);

	result++;

	int temp_gcd;

	int tmp_a;
	int tmp_b;
	for (int i = x; i <= y; i++)
	{
		for (int j = 1; j < i; j++)
		{
			temp_gcd = gcd(i, j);
			tmp_a = i / temp_gcd;
			tmp_b = j / temp_gcd;

			if (table[tmp_a][tmp_b] == 0)
			{
				result++;
				table[tmp_a][tmp_b] = 1;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}