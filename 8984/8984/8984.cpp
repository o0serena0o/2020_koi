#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int MXN = 100001;
int N, L;
ll T_dp[MXN];
ll D_dp[MXN];
pair<int, int> stick[MXN];
vector<int> tv, dv;

int main()
{
	scanf_s("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %d", &stick[i].first, &stick[i].second);
		tv.push_back(stick[i].first);
		dv.push_back(stick[i].second);
	}
	sort(stick, stick + N);
	sort(tv.begin(), tv.end());
	sort(dv.begin(), dv.end());
	tv.erase(unique(tv.begin(), tv.end()), tv.end());
	dv.erase(unique(dv.begin(), dv.end()), dv.end());
	ll ans = 0;
	for (int i = 0; i < N; i++)
	{
		int t_idx = lower_bound(tv.begin(), tv.end(), stick[i].first) - tv.begin();
		int d_idx = lower_bound(dv.begin(), dv.end(), stick[i].second) - dv.begin();
		int len = L + (abs(stick[i].first - stick[i].second));
		ll t = T_dp[t_idx], d = D_dp[d_idx];
		T_dp[t_idx] = max(t, d + len);
		D_dp[d_idx] = max(d, t + len);
		ans = max(T_dp[t_idx], max(ans, D_dp[d_idx]));
	}
	printf("%lld", ans);
	return 0;
}