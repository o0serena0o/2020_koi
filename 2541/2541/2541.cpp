#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int a, b, t, sign = 0;

    //scanf("%d%d", &a, &b);
    cin >> a >> b;
    t = b - a;

    if (t > 0) sign = 1;
    else if (t < 0) sign = -1, t = -t;

    while (t > 0 && (t % 2 == 0)) t = t / 2;

    int x, y;
    int subt;
    for (int i = 1; i <= 5; i++)
    {
        cin >> x >> y;

        subt = y - x;
        if (sign < 0) subt = -subt;

        if (sign == 0) //같을 때
        {
            if (subt == 0) cout << "Y\n";
            else cout << "N\n";
        }
        else {
            if (subt > 0 && subt % t == 0) cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}
