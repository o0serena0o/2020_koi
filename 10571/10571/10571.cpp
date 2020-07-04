#include <bits/stdc++.h>

using namespace std;

int t;
int n;
vector<pair<int, int>> d;
int w, c;
vector<int>dp;
int diamond;
int max_dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t >> n;
	while (t--)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> w >> c;
			d.push_back(make_pair(w, c));
		}
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (d[j].first<d[i].first && d[j].second>d[i].second)
				{
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
		}
		int ans = dp[0];
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, dp[i]);
		}
		cout << ans;
	}
}