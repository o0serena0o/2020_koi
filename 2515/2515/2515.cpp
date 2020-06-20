#include <bits/stdc++.h>
using namespace std;

int n, s;

typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> s;
	
	vector<p> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin() + 1, v.end());
	
	vector<int> d(n + 1), dd(n + 1);

	for (int i = 1; i <= n; i++)
	{
		for (dd[i] = dd[i - 1] + 1; dd[i] < i; dd[i]++)
		{
			if (v[i].first - v[dd[i]].first < s) break;
		}
		dd[i]--;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		d[i] = d[dd[i]] + v[i].second;
		d[i] = max(d[i], d[i - 1]);
	}

	cout << d[n];
}