#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll A, B;
ll gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	ll val = 1;
	ll f = B / A;
	for (ll i = 2; i * i < f; i++)
	{
		if (f % i == 0 && gcd(i, f / i) == 1)
		{
			val = i;
		}
	}
	cout << A * val << ' ' << A * (f / val);	
}