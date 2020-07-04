#include <bits/stdc++.h>

using namespace std;

int elec;
vector<int> dp;
vector<pair<int,int>> a;
int max_dp = 0;
int lis;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> elec;
	for (int i = 0; i < elec; i++)
	{
		int r, k;
		cin >> r >> k;
		a.push_back(make_pair(r, k));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < elec; i++)
	{
		max_dp = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j].second<a[i].second && dp[j]>max_dp)
			{
				max_dp = dp[j];
			}
		}
		dp.push_back(max_dp+1);
	}
	for (int i = a.size()-1; i >= 0; i--)
	{
		if (lis < dp[i]) lis = dp[i];
	}
	cout << elec-lis;
}