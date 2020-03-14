#include <bits/stdc++.h>

using namespace std;

int n, m;
int d[110][110];
bool nd[101];

void c(int day, int coupon, int price) //현재 day일이고, 쿠폰이 coupon개만큼 있고, 그날까지 price원 만큼의 돈을 쓴 상태
{
	if (day > n + 4) return;
	else {
		d[day][coupon] = price;
	}
	//dp값이 차있지 않은 때나(최초로 탐색) 또는 dp값보다 현재 price값이 작은 경우 여기까지 내려옴
	if (nd[day + 1])
	{
		if (d[day + 1][coupon] == 0) c(day + 1, coupon, price);
		else
		{
			if (d[day + 1][coupon] > price) c(day + 1, coupon, price);
		}
	}

	if (d[day + 1][coupon] == 0) c(day + 1, coupon, price + 10000);
	else {
		if (d[day + 1][coupon] > price + 10000) c(day + 1, coupon, price + 10000);
	}
	if (d[day + 3][coupon + 1] == 0) c(day + 3, coupon + 1, price + 25000);
	else {
		if (d[day + 3][coupon + 1] > price + 25000) c(day + 3, coupon + 1, price + 25000);
	}
	if (d[day + 5][coupon + 2] == 0) c(day + 5, coupon + 2, price + 37000);
	else {
		if (d[day + 5][coupon + 2] > price + 37000) c(day + 5, coupon + 2, price + 37000);
	}

	if (coupon >= 3)
	{
		if (d[day + 1][coupon - 3] == 0) c(day + 1, coupon - 3, price);
		else
		{
			if (d[day + 1][coupon - 3] > price) c(day + 1, coupon - 3, price);
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);

	// 예외 케이스: 모든 날을 리조트를 안가도 되는 경우
	if (n == m) {
		printf("0");
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		int ndn;
		scanf_s("%d", &ndn);
		nd[ndn] = true;
	}
	c(0, 0, 0);
	//n번째 날부터 n+7번째 날까지의 모든 값을 체크하면서 그중에 최솟값을 찾는다.
	int ans = 0x7FFFFFFF; //가능한 int의 최댓값
	for (int i = n; i < n + 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (d[i][j] != 0)
			{
				ans = min(ans, d[i][j]);
			}
		}
	}
	printf("%d", ans);
}
