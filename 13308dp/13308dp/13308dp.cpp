#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int n_ = 2500 + 10;

struct node
{
	int idx, cst;
	ll dst;
	node(int idx, int cst, ll dst) :idx(idx), cst(cst), dst(dst) {}
	bool operator < (node A)const { return dst > A.dst; }
};

bool vst[n_][n_];
int n, m, cst[n_];
vector<pii> gph[n_];
priority_queue<node> pq;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> cst[i];
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		gph[a].push_back({ b,c });
		gph[b].push_back({ a,c });
	}

	pq.push(node(1, cst[1], 0));
	while (!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if (vst[now.idx][now.cst])continue;
		if (now.idx == n)
		{
			cout << now.dst;
			break;
		}
		vst[now.idx][now.cst] = true;
		for (auto nxt : gph[now.idx])
		{
			pq.push(node(nxt.first, min(now.cst, cst[nxt.first]), now.cst * nxt.second + now.dst));
		}
	}

	return 0;
}