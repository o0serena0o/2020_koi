#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
typedef long long ll;

struct Rank
{
    int x, y, z, i;

    bool operator < (const Rank& rhs) const
    {
        if (x == rhs.x) {
            if (y == rhs.y) return z > rhs.z;//
            return y > rhs.y;//
        }
        return x < rhs.x;
    }
};


struct edge
{
    int to;
    ll weight;
};

struct Node
{
    int index;
    ll dist;

    bool operator <(const Node& x) const
    {
        return dist > x.dist;
    }
};
struct SegmentTree
{
    int tree[400100];

    SegmentTree()
    {
        for (int i = 0; i < 400100; i++) tree[i] = INF;
    }
    int update(int node, int begin, int end, int index, int val)
    {
        if (index < begin || end < index) return tree[node];
        if (begin == end) return tree[node] = val;
        int mid = (begin + end) / 2;
        int v1 = update(node * 2, begin, mid, index, val);
        int v2 = update(node * 2 + 1, mid + 1, end, index, val);
        return tree[node] = min(v1, v2);
    }
    int query(int node, int begin, int end, int left, int right)
    {
        if (right < begin || end < left) return INF;
        if (left <= begin && end <= right) return tree[node];
        int mid = (begin + end) / 2;
        int v1 = query(node * 2, begin, mid, left, right);
        int v2 = query(node * 2 + 1, mid + 1, end, left, right);
        return min(v1, v2);
    }
};

vector<ll> D, E, F;
int N, M, T;
int x, y, z;
vector<ll> U, V, W;
vector<vector<edge>> graph;
vector<Rank> ranking;
SegmentTree seg;
int result[100001] = { 0, };

void dijkstra(int start, vector<ll>& result_dist)
{
    result_dist.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        result_dist[i] = INF;
    }

    result_dist[start] = 0;
    priority_queue<Node> pq;

    pq.push({ start, 0 });
    while (!pq.empty())
    {
        Node temp = pq.top();

        pq.pop();
        if (result_dist[temp.index] < temp.dist) continue;

        for (int i = 0; i < graph[temp.index].size(); ++i) //현재 탐색노드와 연결된 애들
        {
            edge neighbor = graph[temp.index][i];
            ll temp_new_dist = temp.dist + neighbor.weight; //현재탐색노드를 거쳐서 가는 것이 더 짧으면 최단 거리를 업데이트
            if (temp_new_dist < result_dist[neighbor.to])
            {
                result_dist[neighbor.to] = temp_new_dist;
                pq.push({ neighbor.to, temp_new_dist });
            }
        }
    }
}


void testing()
{
    sort(ranking.begin(), ranking.end());

    for (int i = 1; i <= N; i++)
    {
        int minwhilemaxval = seg.query(1, 1, N, 1, ranking[i].y - 1);//1부터 하나 이전것 까지
                         //query(int node, int begin, int end, int left, int right)
        if (minwhilemaxval >= ranking[i].z) // y가 순번이니까 1부터 pivot의 y까지 z의 최소보다  피봇의 z가 작으면 무조건 yes
        {
            result[ranking[i].i] = 1;  //yes -> 지을수있다. 모든 
        }
        seg.update(1, 1, N, ranking[i].y, min(ranking[i].z, seg.query(1, 1, N, ranking[i].y, ranking[i].y)));
        //update(int node, int begin, int end, int index, int val)
    }
}

bool compB(Rank i, Rank j)
{
    return i.y < j.y;
}
bool compC(Rank i, Rank j)
{
    return i.z < j.z;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    cin >> x >> y >> z;
    cin >> M;

    graph.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int u, v; ll w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    dijkstra(x, U);
    dijkstra(y, V);
    dijkstra(z, W);

    for (int i = 1; i <= N; i++)
    {
        D.push_back(U[i]);
        E.push_back(V[i]);
        F.push_back(W[i]);
    }
    sort(D.begin(), D.end());
    sort(E.begin(), E.end());
    sort(F.begin(), F.end());


    ranking.resize(N + 1);

    for (int i = 1; i <= N; i++) // i 번째 노드의 크기가 현재 몇번째인지 찾아준다.
    {
        ranking[i].x = lower_bound(D.begin(), D.end(), U[i]) - D.begin() + 1;
        ranking[i].y = lower_bound(E.begin(), E.end(), V[i]) - E.begin() + 1;
        ranking[i].z = lower_bound(F.begin(), F.end(), W[i]) - F.begin() + 1;
        ranking[i].i = i;
    }

    testing();


    cin >> T;
    vector<int> question(T);

    for (int i = 0; i < T; ++i)
    {
        cin >> question[i];
    }
    for (int i = 0; i < T; ++i)
    {
        if (result[question[i]]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


    return 0;
}
