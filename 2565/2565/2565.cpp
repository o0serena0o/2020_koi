#include <bits/stdc++.h>

using namespace std;

int elec;
vector<int> dp;
vector<pair<int,int>> a;

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
	sort(a.begin, a.end);
	for (int i = 0; i < elec; i++)
	{
		a[i].second
	}
}