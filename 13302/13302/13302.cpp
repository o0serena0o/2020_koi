#include <iostream>
#include <cstdio>
#include <queue>
#define INF 0x7fffffff;

using namespace std;

int a_size, b_size, a_tar, b_tar;//bucket size and target value

int ae[100005];//DP table when a is empty
int af[100005];//DP table when a is full
int be[100005];//DP table when b is empty
int bf[100005];//DP table when b is full

typedef struct _node {
    int a;
    int b;
    int n;
}node;

int main()
{
    scanf_s("%d %d %d %d", &a_size, &b_size, &a_tar, &b_tar);
    queue<node> q;
    node cur;
    q.push(node { 0, 0, 0 });
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        //DP테이블 확인해보고 탐색한 곳이라면 넘어감
        if (cur.a == 0 && ae[cur.b] == 1) continue;
        if (cur.b == 0 && be[cur.a] == 1) continue;
        if (cur.a == a_size && af[cur.b] == 1) continue;
        if (cur.b == b_size && bf[cur.a] == 1) continue;

        //이 아래로 온 것은 처음 탐색하는 값을 의미
        //탐색한 값은 DP테이블 1로
        if (cur.a == 0) ae[cur.b] = 1;
        if (cur.b == 0) be[cur.a] = 1;
        if (cur.a == a_size) af[cur.b] = 1;
        if (cur.b == b_size) bf[cur.a] = 1;

        if (cur.a == a_tar && cur.b == b_tar) {//찾는 케이스
            printf("%d", cur.n);
            return 0;
        }


        if (cur.a != 0) q.push(node { 0, cur.b, cur.n + 1 });//E(A)
        if (cur.b != 0) q.push(node { cur.a, 0, cur.n + 1 });//E(B)
        if (cur.a != a_size) q.push(node { a_size, cur.b, cur.n + 1 });//F(A)
        if (cur.b != b_size) q.push(node { cur.a, b_size, cur.n + 1 });//F(B)
        if (cur.a < b_size - cur.b) q.push(node { 0, cur.a + cur.b, cur.n + 1 });//M(A,B)
        else q.push(node { cur.a - (b_size - cur.b), b_size, cur.n + 1 });//M(A,B)
        if (cur.b < a_size - cur.a) q.push(node { cur.a + cur.b, 0, cur.n + 1 });//M(B,A)
        else q.push(node { a_size, cur.b - (a_size - cur.a), cur.n + 1 });//M(B,A)
    }

    //큐가 다 비도록 못찾았으면 -1 프린트
    printf("-1");

    return 0;
}
