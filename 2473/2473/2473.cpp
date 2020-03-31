#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int n;
vector<ll> liquid(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> liquid[i];
	}
	sort(liquid.begin(), liquid.end());
	int idx1 = n - 2, idx2 = n - 1, idx3 = n;
	for (int i = 0; i < n; i++)
	{
		int left = i + 1;
		int right = n;
		while (left < right)
		{
			ll sum = liquid[i] + liquid[right] + liquid[left];
			if (abs(sum) < abs(liquid[idx1] + liquid[idx2] + liquid[idx3]))
			{
				idx1 = i;
				idx2 = left;
				idx3 = right;
			}
			if (sum < 0)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	cout << liquid[idx1] << ' ' << liquid[idx2] << ' ' << liquid[idx3] << '\n';
}