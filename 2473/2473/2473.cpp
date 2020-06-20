#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define INF 0x3f3f3f;
int N;
vector<ll> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll result[3] = { 100001 ,100001 ,100001 };
    ll min = INF;

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll pivot;
    int left = 0;
    int right = N - 1;
    long long temp;
    for (int i = 0; i < N; ++i)
    {
        pivot = arr[i];
        left = i + 1;
        right = N - 1;
        while (true)
        {
            if (left >= right) break;

            temp = pivot + arr[left] + arr[right];
            if (llabs(temp) < min)
            {
                min = llabs(temp);
                result[0] = pivot;
                result[1] = arr[left];
                result[2] = arr[right];
            }
            if (temp < 0)
            {
                left++;

            }
            else if (temp > 0)
            {
                right--;
            }
            else
            {
                cout << result[0] << ' ' << result[1] << ' ' << result[2];
                return 0;
            }


        }

    }

    cout << result[0] << ' ' << result[1] << ' ' << result[2];

    return 0;
}
