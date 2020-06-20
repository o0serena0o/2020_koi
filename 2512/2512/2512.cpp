#include <bits/stdc++.h>
using namespace std;

int arr[10101];
int n, m;

bool chk(int h)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] > h ? h : arr[i];
    }
    return (m >= sum);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (m >= sum)
    {
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, arr[i]);
        cout << ans; return 0;
    }

    int l = 0, r = 1e9 + 7;
    int mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        bool now = chk(mid);
        bool nxt = chk(mid + 1);
        if (now && !nxt) break;
        if (!now) r = mid - 1;
        else l = mid + 1;
    }
    cout << mid;
}
