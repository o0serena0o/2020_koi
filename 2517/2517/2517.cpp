#include <bits/stdc++.h>
#define MAX_INT 1000000000
typedef long long ll;

using namespace std;


struct node
{
	int first, second, init;
};

node person[500002];
node temp[500002];
int N;
bool cmp(node a, node b)
{
	return a.init < b.init;
}
void mergesort(int start, int end)
{
	if (start == end)
	{
		return;
	}
	else if (end - start == 1)
	{
		if (person[end].first > person[start].first)
		{
			person[end].second--;
			swap(person[start], person[end]);
		}
	}
	else {
		int left = start;
		int mid = (start + end) / 2;
		int right = mid + 1;
		mergesort(left, mid);
		mergesort(right, end);
		for (int i = start; i <= end; i++)
		{
			if (left > mid)
			{
				temp[i] = person[right];
				right++;
			}
			else if (right > end)
			{
				temp[i] = person[left];
				left++;
			}
			else if (person[left].first < person[right].first)
			{
				temp[i] = person[right];
				right++;
				temp[i].second -= (mid - left + 1);
			}
			else
			{
				temp[i] = person[left];
				left++;
			}
		}
		for (int i = start; i <= end; i++) person[i] = temp[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> person[i].first; //평소 실력
		person[i].second = i;  //현재등수 - 가변(정렬 등수)
		person[i].init = i;  //현재등수 - 불변(초기 등수)
	}
	mergesort(0, N - 1);
	sort(person, person + N, cmp);

	for (int i = 0; i < N; i++)
		cout << person[i].second + 1 << '\n';
}