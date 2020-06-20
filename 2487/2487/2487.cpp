#include <bits/stdc++.h>
using namespace std;

int input[20202];
int dptable[20202];
int n;

int calcuGCD(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

inline int lcm(int a, int b) {
    return a / calcuGCD(a, b) * b;
}

int cycle(int start)
{

    int cnt = 0;
    int result = start;
    int i = start;
    do
    {
        i = input[i];
        dptable[i] = 1;
        cnt++;

    } while (result != i);

    return cnt;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input[i];
    }

    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dptable[i]) continue;
        int now = cycle(i);
        result = lcm(result, now);
    }
    cout << result;
}