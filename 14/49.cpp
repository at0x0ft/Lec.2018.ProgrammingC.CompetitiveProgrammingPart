#include <bits/stdc++.h>

using namespace std;

#define CO_NUM 4

int judge(const pair<int, int> cos[CO_NUM])
{
    if ((cos[0].first - cos[1].first) * (cos[2].second - cos[3].second) - (cos[2].first - cos[3].first) * (cos[0].second - cos[1].second) == 0)
        return 2;
    else if ((cos[0].first - cos[1].first) * (cos[2].first - cos[3].first) + (cos[0].second - cos[1].second) * (cos[2].second - cos[3].second) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    pair<int, int> cos[CO_NUM];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < CO_NUM; j++)
        {
            scanf("%d %d", &(cos[j].first), &(cos[j].second));
        }
        printf("%d\n", judge(cos));
    }

    return 0;
}
