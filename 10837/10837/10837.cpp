#include <bits/stdc++.h>

using namespace std;

int main() {
    int K = 0;
    int C = 0;

    int result[100000];
    scanf_s("%d %d", &K, &C);
    int middle = K / 2;

    int x, y;
    for (int i = 0; i < C; i++)
    {
        scanf("%d %d", &x, &y);

        if (x <= middle && y <= middle)//예외 처리
        {
            result[i] = 1;
        }
        else
        {
            if (x >= y) //영희> 동수
            {
                if (y + (K - x) + 2 >= x)
                {
                    result[i] = 1;
                }
                else
                {
                    result[i] = 0;
                }
            }
            else //영희<= 동수
            {
                if (x + (K - y) + 1 >= y)
                {
                    result[i] = 1;
                }
                else
                {
                    result[i] = 0;
                }
            }
        }

    }

    for (int i = 0; i < C; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}
