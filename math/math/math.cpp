#include <bits/stdc++.h>

int main()
{
	int n = 2;
	int cnt = 0;
	for (int n = 2; n <= 1024; n=n*2) {
		cnt++;
	}
	printf("%d", cnt);
}