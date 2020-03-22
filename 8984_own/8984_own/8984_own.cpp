#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct UpDown
{
    ll up;
    ll down;

    bool operator<(UpDown x)
    {
        if (up == x.up)
        {
            return down < x.down;
        }
        return up < x.up;
    }
};

int n;
int l;
unordered_map <int, int> t_hash, d_hash;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;
    vector < UpDown > stick(n);
    vector <int> t_point(n), d_point(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stick[i].up >> stick[i].down;
        t_point[i] = stick[i].up;
        d_point[i] = stick[i].down;
    }

    sort(stick.begin(), stick.end());
    sort(t_point.begin(), t_point.end());
    sort(d_point.begin(), d_point.end());

    t_point.erase(unique(t_point.begin(), t_point.end()), t_point.end());
    d_point.erase(unique(d_point.begin(), d_point.end()), d_point.end());

    vector <ll> t_ans(t_point.size());
    for (int i = 0; i < t_point.size(); i++)
        t_hash[t_point[i]] = i;

    vector <ll> d_ans(d_point.size());
    for (int i = 0; i < d_point.size(); i++)
        d_hash[d_point[i]] = i;

    ll distance = 0;
    ll temp_t = 0;
    ll result = 0;
    int  index_t, index_d;
    for (int i = 0; i < n; i++)
    {
        distance = abs(stick[i].up - stick[i].down) + l;
        index_t = t_hash[stick[i].up];
        index_d = d_hash[stick[i].down];
        temp_t = t_ans[index_t];
        t_ans[index_t] = max(t_ans[index_t], d_ans[index_d] + distance);
        d_ans[index_d] = max(d_ans[index_d], temp_t + distance);
        result = max(result, max(t_ans[index_t], d_ans[index_d]));
    }

    cout << result;
    return 0;
}
