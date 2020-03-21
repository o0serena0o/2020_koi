#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int m, n;
ll l;
int cnt;
vector<ll> m_x, m_right, m_left, n_right, n_left, n_lcnt, n_rcnt;
vector<pair<ll, ll>> n_xy;

int main()
{
	scanf_s("%d %d %lld", &m, &n, &l);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%lld", &m_x[i]);
		m_right[i] = m_x[i] + l;
		m_left[i] = m_x[i] - l;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lld %lld", &n_xy[i].first, &n_xy[i].second);
		n_right[i] = n_xy[i].first + n_xy[i].second;
		n_left[i] = n_xy[i].first - n_xy[i].second;
	}

	sort(m_right.begin(), m_right.end());
	sort(n_right.begin(), n_right.end());
	sort(m_left.begin(), m_left.end());
	sort(n_left.begin(), n_left.end());
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m_right[i] >= n_right[j]&&n_rcnt[i]==0)
			{
				cnt++;
				n_rcnt[i] = 1;
			}
			if (m_left[i] <= n_left[i] && n_lcnt[i] == 0)
			{
				cnt++;
				n_lcnt[i] = 1;
			}
		}
	}
	printf("%d", cnt);
}
