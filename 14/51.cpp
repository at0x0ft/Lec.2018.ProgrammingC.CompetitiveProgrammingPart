#include <bits/stdc++.h>

using namespace std;

#define P_NUM 2

// cmath.h

pair<double, double> calc(const pair<int, int> ps[P_NUM], const pair<int, int> &sp)
{
    int c1 = ps[0].first - ps[1].first, c2 = ps[1].second - ps[0].second;

    return pair<double, double>(
        (1.0 * (sp.first * c1 * c1 + 2 * ps[0].first * c2 * c2 + 2 * ps[0].second * c1 * c2 - sp.second * c1 * c2)) / (c1 * c1 + c2 * c2),
        (1.0 * (2 * ps[0].first * c1 * c2 + 2 * ps[0].second * c1 * c1 - sp.first * c1 * c2 + sp.second * c2 * c2)) / (c1 * c1 + c2 * c2));
}

int main()
{
    pair<int, int> ps[P_NUM], sp;
    pair<pair<int, int>, int> l1, l2;
    for (int i = 0; i < P_NUM; i++)
    {
        scanf("%d %d", &(ps[i].first), &(ps[i].second));
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &(sp.first), &(sp.second));
        pair<double, double> ans = calc(ps, sp);
        printf("%.10f %.10f\n", ans.first, ans.second);
    }

    return 0;
}
