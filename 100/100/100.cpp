#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int map[5][5] = {
	{1,3,2,4,1},
	{5,6,8,5,0},
	{6,7,4,2,4},
	{5,4,5,3,2},
	{5,4,0,0,9}
};

int cross_number = 0;

void cn(int x, int y)
{
	cross_number = map[x][y - 1] + map[x][y + 1] + map[x - 1][y] + map[x + 1][y] + map[x][y];
	printf("(%d,%d) 십자수는 %d입니다", x, y, cross_number);
}

int main()
{
	int k = 0;
	int x = 0, y = 0;
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf_s("%d %d", &x, &y);
		cn(x, y);
		x = 0, y = 0;
	}
}