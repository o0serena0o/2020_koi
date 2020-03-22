#include <bits/stdc++.h>

using namespace std;

int result = 0;
long long l;

struct xy
{
    int x;
    int y;
};
bool getDistanc(int gun_x, xy ani)
{
    int distance = 0;
    distance = abs(gun_x - ani.x) + ani.y;
    if (distance <= l) return true;
    else return false;
}
bool comp(xy x, xy y)
{
    return x.x <= y.x;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int n;

    cin >> m >> n >> l;

    vector<xy> guns(m);
    for (int i = 0; i < m; i++)
    {
        cin >> guns[i].x;
        guns[i].y = 0;
    }
    vector<xy> animals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> animals[i].x >> animals[i].y;
    }
    sort(guns.begin(), guns.end(), comp);
    sort(animals.begin(), animals.end(), comp);

    int leftside = 0;
    for (int j = 0; j < n; j++)//동물
    {

        while (leftside != m - 1 && guns[leftside + 1].x < animals[j].x)
        {
            leftside++;
        }
        if (getDistanc(guns[leftside].x, animals[j]))
        {
            result++;
            continue;
        }
        if (leftside != m - 1)
        {
            if (getDistanc(guns[leftside + 1].x, animals[j]))
            {
                result++;
                continue;
            }
        }
    }
    cout << result << endl;
    return 0;
}
