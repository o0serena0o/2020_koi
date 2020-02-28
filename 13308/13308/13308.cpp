#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

struct asdf {
	ll node, cost, dst;
	asdf(int a, int b, ll c) : node(a), cost(b), dst(c) {}
	bool operator < (asdf r) const { return dst > r.dst; }
};

bool chk[3000][3000];
ll n, m, node[3000];
vector<p> g[3000];


ll dijkstra() {
	priority_queue<asdf> pq;
	pq.push(asdf(1, node[1], 0));
	while (!pq.empty()) {
		asdf now = pq.top();
		ll idx = now.node, cost = now.cost, dist = now.dst;
		pq.pop();
		if (chk[idx][cost]) continue;
		if (idx == n) return dist;

		chk[idx][cost] = 1;
		for (auto nxt : g[idx]) {
			pq.push(asdf(nxt.first, min(cost, node[nxt.first]), cost * nxt.second + dist));
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> node[i];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}

	cout << dijkstra();
}