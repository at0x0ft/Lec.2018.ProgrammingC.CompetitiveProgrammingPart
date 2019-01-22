#include <bits/stdc++.h>

using namespace std;

#define P_NUM 2

pair<double, double> calc(const pair<int, int> ps[P_NUM], const pair<int, int> &sp)
{
    int c1 = ps[0].second - ps[1].second, c2 = ps[0].first - ps[1].first, det = ps[0].second * ps[1].first - ps[0].first * ps[1].second;

    return pair<double, double>(
        (1.0 * (c1 * det + sp.first * c2 * c2 + sp.second * c1 * c2)) / (c1 * c1 + c2 * c2),
        (1.0 * (sp.first * c1 * c2 + sp.second * c1 * c1 - c2 * det)) / (c1 * c1 + c2 * c2));
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
