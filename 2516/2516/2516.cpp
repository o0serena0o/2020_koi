#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[101010];

int pos[101010];

bool relax() {
    
    bool ret = 0;
    
    for (int i = 1; i <= n; i++)
    {
        if (pos[i]) continue;
        int cnt = 0;
        for (int j = 0; j < g[i].size(); j++) cnt += pos[g[i][j]] == 0;
        if (cnt > 1) pos[i] = 1, ret = 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!pos[i]) continue;
        int cnt = 0;
        for (int j = 0; j < g[i].size(); j++) cnt += pos[g[i][j]] == 1;
        if (cnt > 1) pos[i] = 0, ret = 1;
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        int cnt; cin >> cnt;
        while (cnt--)
        {
            int t; cin >> t; g[i].push_back(t);
        }
    }

    while (1)
    {
        if (!relax()) break;
    }

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pos[i]) b++;
        else a++;
    }
    cout << a << " ";
    for (int i = 1; i <= n; i++)
    {
        if (!pos[i]) cout << i << " ";
    }
    cout << "\n";
    cout << b << " ";
    for (int i = 1; i <= n; i++)
    {
        if (pos[i]) cout << i << " ";
    }
}