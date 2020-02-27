#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v(110);
int dp[110][110];

int solve(int day, int coupon, int price) {
	if (n < day) return price; //범위 초과 시 현재 가격 반환
	if (dp[day][coupon]) return dp[day][coupon] + price; //이미 탐색했을 경우
	if (v[day]) return solve(day + 1, coupon, price); //불가능한 날짜면 다음날을 탐색

	int ans = (1 << 31) - 1;
	ans = min(ans, solve(day + 1, coupon, price + 10000)); //1일권 구매
	ans = min(ans, solve(day + 3, coupon + 1, price + 25000)); //3일권 구매 + 쿠폰 1개
	ans = min(ans, solve(day + 5, coupon + 2, price + 37000)); //5일권 구매 + 쿠폰 2개

	if (coupon >= 3) { //쿠폰 사용 가능 시
		ans = min(ans, solve(day + 1, coupon - 3, price));
	}

	dp[day][coupon] = ans - price;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t; cin >> t; v[t] = 1;
	}
	cout << solve(1, 0, 0);
}