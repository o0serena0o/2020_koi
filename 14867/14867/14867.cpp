#include <bits/stdc++.h>
#define INF 0x7fffffff

using namespace std;

int a_max, b_max, a_to, b_to;

int ae[100001];
int af[100001];
int be[100001];
int bf[100001];

typedef struct _node {
	int a;
	int b;
	int n;
}node;

int main()
{
	scanf_s("%d %d %d %d", &a_max, &b_max, &a_to, &b_to);

	queue<node> q;
	node now;
	q.push(node{ 0,0,0 });
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (now.a == 0 && ae[now.b] == 1) continue;
		if (now.a == a_max && af[now.b] == 1)continue;
		if (now.b == 0 && be[now.a] == 1)continue;
		if (now.b == b_max && bf[now.a] == 1)continue;

		if (now.a == 0) ae[now.b] = 1;
		if (now.a == a_max) af[now.b] = 1;
		if (now.b == 0) be[now.a] = 1;
		if (now.b == b_max) bf[now.a] = 1;

		if (now.a == a_to && now.b == b_to)
		{
			printf("%d", now.n);
			return 0;
		}

		if (now.a != 0) q.push(node{ 0,now.b,now.n + 1 });//E(a)
		if (now.b != 0) q.push(node{ now.a,0,now.n + 1 });//E(b)
		if (now.a != a_max)q.push(node{ a_max,now.b,now.n + 1 });//F(a)
		if (now.b != b_max)q.push(node{ now.a,b_max,now.n + 1 });//F(b)
		if (now.a < b_max - now.b) q.push(node{ 0,now.b + now.a,now.n + 1 });//M(a,b)
		else q.push(node{ now.a - (b_max - now.b),b_max,now.n + 1 });
		if (now.b < a_max - now.a) q.push(node{ now.a + now.b,0,now.n + 1 });//M(b,a)
		else q.push(node{ a_max,now.b - (a_max - now.a),now.n + 1 });
	}
	printf("-1");

	return 0;
}