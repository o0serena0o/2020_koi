#include<bits/stdc++.h>

using namespace std;

int n, l;
float absolut_result = 40000.0;
vector<vector<int>> snail;
vector<float> table;
vector<float> check;

float pp[1010][1010];
struct collision
{
    int a, b;
    int type;
    float time;

    collision()
    {
        a = 0;
        b = 0;
        type = 0;
        time = 0.0;
    }
    bool operator<(const collision& y)const
    {
        if (time < y.time) return true;
        return false;
    }
};

vector<collision> candidate;

float makelength(float x, float y, float x2, float y2)
{

    return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}
bool isThereColl(int A_x, int A_y, int A_x_final, int A_y_final, int B_x, int B_y, int B_x_final, int B_y_final, collision& cc, collision& cc2);
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> l;
    snail.resize(n);
    table.resize(n, 40000);
    check.resize(n, 40000);
    for (int i = 0; i < n; i++)
    {
        snail[i].resize(4);
        cin >> snail[i][0] >> snail[i][1] >> snail[i][2] >> snail[i][3];//시작점 / inf 점
        snail[i][2] = (snail[i][2] - snail[i][0]) * 4 * l + snail[i][0];
        snail[i][3] = (snail[i][3] - snail[i][1]) * 4 * l + snail[i][1];

    }

    collision temp;
    collision temp2;
    //collision detection
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {//i와 j의 충돌검사

            temp.a = i;
            temp.b = j;
            temp2.a = j;
            temp2.b = i;
            //TRUE면 벡터에 추가
            if (isThereColl(snail[i][0], snail[i][1], snail[i][2], snail[i][3],
                snail[j][0], snail[j][1], snail[j][2], snail[j][3], temp, temp2))
            {

                //if (temp.type != 1)            candidate.push_back(temp);
                //if (temp2.type != 1)            candidate.push_back(temp2);


                candidate.push_back(temp);
                candidate.push_back(temp2);


            }

        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isThereColl(snail[i][0], snail[i][1], snail[i][2], snail[i][3],
            0, 0, l, 0, temp, temp2))
        {
            candidate.push_back(temp);
            candidate.back().a = i;
            candidate.back().b = 1001;//울타리
            candidate.back().type = 3;//울타리 충돌
            continue;
        }
        if (isThereColl(snail[i][0], snail[i][1], snail[i][2], snail[i][3],
            l, 0, l, l, temp, temp2))
        {
            candidate.push_back(temp);
            candidate.back().a = i;
            candidate.back().b = 1001;//울타리
            candidate.back().type = 3;//울타리 충돌
            continue;
        }
        if (isThereColl(snail[i][0], snail[i][1], snail[i][2], snail[i][3],
            l, l, 0, l, temp, temp2))
        {
            candidate.push_back(temp);
            candidate.back().a = i;
            candidate.back().b = 1001;//울타리
            candidate.back().type = 3;//울타리 충돌
            continue;
        }
        if (isThereColl(snail[i][0], snail[i][1], snail[i][2], snail[i][3],
            0, l, 0, 0, temp, temp2))
        {
            candidate.push_back(temp);
            candidate.back().a = i;
            candidate.back().b = 1001;//울타리
            candidate.back().type = 3;//울타리 충돌
            continue;
        }
    }
    int cnt = 0;
    sort(candidate.begin(), candidate.end());

    for (int i = 0; i < candidate.size(); i++)
    {
        pp[candidate[i].a][candidate[i].b] = candidate[i].time;

    }

    for (int i = 0; i < candidate.size(); i++)
    {
        if (candidate[i].type == 1) continue;
        if (candidate[i].b != 1001)
        {
            if (pp[candidate[i].b][candidate[i].a] < candidate[i].time)
                table[candidate[i].a] = min(table[candidate[i].a], candidate[i].time);

        }
        else
        {
            table[candidate[i].a] = min(table[candidate[i].a], candidate[i].time);
        }



    }
    float maxval = 0;
    for (int i = 0; i < table.size(); i++)
        maxval = max(maxval, table[i]);

    //cout << "  "<<absolut_result << endl;
    for (int i = 0; i < candidate.size(); i++)
    {
        if (candidate[i].type == 1)
        {

            if (table[candidate[i].a] >= candidate[i].time && table[candidate[i].b] >= candidate[i].time)
            {
                absolut_result = min(absolut_result, candidate[i].time);

            }



        }

    }
    cout << maxval << endl;
    if (absolut_result < maxval) maxval = absolut_result;

    maxval = maxval * 100;
    maxval = floor(maxval + 0.5);
    maxval = maxval / 100.0;
    cout << fixed;
    cout.precision(2);
    cout << maxval;
    return 0;

}

bool isThereColl(int A_x, int A_y, int A_x_final, int A_y_final, int B_x, int B_y, int B_x_final, int B_y_final, collision& cc, collision& cc2)
{
    float t;
    float s;
    float under = (float)(B_y_final - B_y) * (A_x_final - A_x) - (float)(B_x_final - B_x) * (A_y_final - A_y);
    if (under == 0) return false;

    float _t = (float)(B_x_final - B_x) * (A_y - B_y) - (float)(B_y_final - B_y) * (A_x - B_x);
    float _s = (float)(A_x_final - A_x) * (A_y - B_y) - (float)(A_y_final - A_y) * (A_x - B_x);

    t = _t / under;
    s = _s / under;

    if (t < 0.0 || t>1.0 || s < 0.0 || s>1.0) return false;
    if (_t == 0 && _s == 0) return false;

    float colPos_x;
    float colPos_y;

    colPos_x = A_x + t * (float)(A_x_final - A_x);
    colPos_y = A_y + t * (float)(A_y_final - A_y);

    if (colPos_x<0 || colPos_x > l || colPos_y < 0 || colPos_y > l)
        //울타리에 충돌
        return false;


    float A_time = makelength(A_x, A_y, colPos_x, colPos_y);
    float B_time = makelength(B_x, B_y, colPos_x, colPos_y);
    if (A_time == B_time)
    {
        cc.type = 1;//동시충돌
        cc.time = A_time;
        cc2.type = 1;//동시충돌
        cc2.time = A_time;
        //absolut_result = min(absolut_result, A_time);
        //cout << "절대값 발생" << endl;
        return true;//업데이트 안해준다.culling 위해서
    }
    else if (A_time < B_time)
    {
        cc.type = 2;//A가 B 흔적에에충돌
        cc.time = A_time;
        cc2.type = 2;//B가 A 흔적에에충돌
        cc2.time = B_time;
        return true;
    }
    else
    {
        cc.type = 2;//A가 B 흔적에에충돌
        cc.time = A_time;
        cc2.type = 2;//B가 A 흔적에에충돌
        cc2.time = B_time;
        return true;
    }

    return true;
}
