#include <bits/stdc++.h>

using namespace std;

struct bus {
    int start;
    int end;
    int num;

};

bool compare(bus x, bus y)
{
    if (x.start == y.start) return x.end > y.end;
    return x.start < y.start;
}

bool result_sorting(bus x, bus y)
{
    return x.num < y.num;
}

int main()
{
    int n, m;
    scanf_s("%d %d", &n, &m);
    vector<bus> input(m);

    int B_max_val = 0;

    for (int i = 0; i < m; i++)
    {
        scanf_s("%d %d",&input[i].start,&input[i].end);

        if (input[i].start > input[i].end)//B 유형
        {
            B_max_val = max(B_max_val, input[i].end);//B 유형의 가장 큰 end값을 저장
            input[i].end += n;
        }
        input[i].num = (i + 1);
    }
    sort(input.begin(), input.end(), compare);


    deque<bus> result;

    for (int i = 0; i < m; i++)
    {
        if (result.empty() || result.back().end < input[i].end)
        {
            result.push_back(input[i]);
        }

    }

    while (!result.empty() && result.front().end <= B_max_val)
    {
        result.pop_front();
    }
    sort(result.begin(), result.end(), result_sorting);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i].num);
    }

    return 0;
}
