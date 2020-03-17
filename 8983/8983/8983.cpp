#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int M, N;
ll L;
vector<ll> arr_M;
vector<pair<ll,ll>> arr_N;

ll getAns(ll x, ll x1, ll y1)
{
	return abs(x - x1) + y1;
}

int main()
{
	scanf_s("%d %d %d", &M, &N, &L);
	ll MAX = 1000000001;
	for (int i = 0; i < M; i++)
	{
		ll x;
		scanf_s("%d", &x);
		arr_M.push_back(x);
	}
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		scanf_s("%d %d", &x, &y);
		arr_N.push_back({ x,y });
	}
	sort(arr_M.begin(), arr_M.end());
	sort(arr_N.begin(), arr_N.end());
	int ans = 0;
	for (int i = 0; i < arr_N.size(); i++)
	{
		ll x = arr_N[i].first;
		ll y = arr_N[i].second;
		auto left = lower_bound(arr_M.begin(), arr_N.end(), x);
		auto right = left - 1;
		if (min(getAns(*right, x, y), getAns(*left, x, y)) <= L) ans++;
	}
	printf("%d", ans);
}