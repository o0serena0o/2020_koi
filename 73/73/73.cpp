#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

struct pos2D {
	float x;
	float y;
};

int main()
{
	struct pos2D p1;
	struct pos2D p2;

	scanf_s("%f %f", &p1.x, &p1.y);
	scanf_s("%f %f", &p2.x, &p2.y);
	float dis_x = p2.x - p1.x;
	float dis_y = p2.y - p1.y;
	float distance = dis_x * dis_x + dis_y * dis_y;
	float get_distance = sqrt(distance);
	printf("%f", get_distance);
}