#include<bits/stdc++.h>

using namespace std;

int n, input[160];
int sumTable[160];
int i_to_j[160][160];

long long k;
bitset<2000000> table[155];//i번째문제까지 고려 점수 j가 가능하면 true아니면 false

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
		sumTable[i] = sumTable[i - 1] + input[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
			i_to_j[i][j] = i_to_j[i][j - 1] + sumTable[j] - sumTable[i - 1];
	}

	cin >> k;


	if (k > i_to_j[1][n])//최댓값보다 크면 패쓰 바로 k가 답
	{
		cout << k;
		return 0;
	}

	//table[i][j] = i번 문제까지 고려했을 때 점수 j를 만들 수 있으면 true, 없으면 false


	table[0].set(0);
	table[1].set(0);
	table[1].set(input[1]);//input[1]의 숫자는 가능하니까 true로 바꿔준다.//input[1]이 3이면 3번째자리가 1로바뀜
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i + 1; j++)
		{
			if (j <= 2)
				table[i].set(i_to_j[j][i]);
			else
				table[i] = table[i] | (table[j - 2] << i_to_j[j][i]);
		}
	}
	int ans = k;
	while (table[n].test(ans)) ans++;

	cout << ans;
	return 0;

}
