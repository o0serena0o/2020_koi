#include <bits/stdc++.h>
#define INF 1e18;
typedef long long ll;

using namespace std;

int N, pole[1000000];

ll f(ll x)
{
    ll result = 0;
    for (int i = 1; i < N; ++i)  result += abs(x * i - pole[i]);
    return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)  cin >> pole[i];

    int low = 0, high = INF;
    while (high - low >= 3)
    {
        ll a = (low * 2 + high) / 3;
        ll b = (low + high * 2) / 3;
        if (f(a) <= f(b)) high = b;
        else low = a;
    }

    ll result = INF;
    for (int i = low; i <= high; ++i)  result = min(f(i), result);

    cout << result;

}