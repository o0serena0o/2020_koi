#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e18;

int N, x[100000];

// 전봇대 간의 간격을 x0으로 할 때 필요한 이동거리 합
inline long long f(int x0)
{
    long long result = 0;
    for (int i = 1; i < N; ++i)
    {
        result += abs(1LL * x0 * i - x[i]);
    }
    return result;
}

int main() {
    // 입력받기
    scanf_s("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf_s("%d", x + i);
    }

    // 삼분 탐색
    int a = 0, b = x[N - 1];
    while (b - a >= 3)
    {
        int p = (a * 2 + b) / 3, q = (a + b * 2) / 3;
        if (f(p) <= f(q)) b = q;
        else a = p;
    }

    // 최종 구간 [lo, hi] 안에서 최솟값을 찾아냄
    long long result = INF;
    for (int i = a; i <= b; ++i)
    {
        result = min(f(i), result);
    }

    // 결과 출력
    printf("%lld\n", result);
}