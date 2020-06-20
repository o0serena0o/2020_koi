#include <bits/stdc++.h>

using namespace std;

int arr[8][8];
int col[8], row[8];
int tmpc[8], tmpr[8];
int newMap[8][8];
int newcol[8], newrow[8];
int ans[8][8];
int M, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> M >> K;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
			arr[i][j] -= M;
			row[i] += arr[i][j];
			col[j] += arr[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if ((row[i] + col[j] - arr[i][j]) % 2) {
				ans[i][j] = 1;
				tmpr[i]++;
				tmpc[j]++;
			}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			newMap[i][j] = tmpr[i] + tmpc[j] - ans[i][j];
			newrow[i] += newMap[i][j];
			newcol[j] += newMap[i][j];
		}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			int cur = newrow[i] + newcol[j] - newMap[i][j];
			if (ans[i][j] && abs(row[i] + col[j] - arr[i][j] - cur) % 4 == 2) ans[i][j] = -1;
		}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (ans[i][j] == 1) cout << "+ ";
			else if (ans[i][j] == 0) cout << ". ";
			else cout << "- ";
		}
		cout << '\n';
	}
	return 0;
}