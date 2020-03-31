#include <bits/stdc++.h>

using namespace std;

struct edg
{
    int idx, type;
};

int unable, check[10001]; // 방문여부(1로 방문 OR -1로 방문)
pair<int, int> res[10001];  // 시도 횟수
bool dptable[5001][10001];
vector<edg> graph[10001];

vector<int> result;

void dfs(int now, int prv, int type, int& cnt)
{

    check[now] = check[prv] * type;

    if (check[now] == 1)
    {
        res[cnt].first++;
    }
    else
    {
        res[cnt].second++;
    }

    for (auto next : graph[now])
    {
        if (unable) return;

        if (!check[next.idx])
        {
            dfs(next.idx, now, next.type, cnt);
        }

        if (check[next.idx] == -check[now] * next.type)//
        {
            unable = true;
            return;
        }
    }
}

void process() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    memset(dptable, 0, sizeof(dptable));
    for (int i = 0; i <= 10000; i++)
    {
        graph[i].clear();
        check[i] = res[i].first = res[i].second = 0;
    }
    unable = 0;

    cin >> n >> m;
    for (int i = m; i > 0; i--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        graph[u].push_back({ v,t });
        graph[v].push_back({ u,t });
    }



    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = 1;
            dfs(i, i, 1, ++cnt);
        }
    }

    if (unable)
    {
        result.push_back(-1);
        return;
    }

    dptable[0][0] = 1;
    //cout << "cnt  " << cnt <<endl;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j - res[i].first >= 0)
            {
                if (!dptable[i][j] && !dptable[i - 1][j - res[i].first])
                {//i번째 그룹까지 고려했을 때, j명을 배치할 수 있는지 여부
                    //하나라도 true면 true이다
                    dptable[i][j] = false;
                }
                else dptable[i][j] = true;
            }

            if (j - res[i].second >= 0)
            {
                if (!dptable[i][j] && !dptable[i - 1][j - res[i].second])
                {
                    dptable[i][j] = false;
                }
                else dptable[i][j] = true;
            }



        }
    }



    int mn = 1e9;
    int no = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[i])
            no++; //양쪽아무곳이나 속할수 있는녀석
        if (!dptable[cnt][i]) //배치불가하면 넘겨버림
            continue;
        if (abs(n / 2 - i) < abs(n / 2 - mn))
            mn = i;
        if (abs((n + 1) / 2 - i) < abs((n + 1) / 2 - mn))
            mn = i;
    }


    int a = mn, b = n - mn - no;
    if (a > b)
        swap(a, b);
    if (a + no <= b)
        result.push_back(b - a - no);

    else
        result.push_back((no - (b - a)) % 2);


}

int main() {

    for (int t = 5; t > 0; t--)
    {
        process();
    }

    for (auto it : result) cout << it << '\n';
    return 0;
}
