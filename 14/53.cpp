#include <bits/stdc++.h>

using namespace std;

#define P_NUM 2

inline int det(const int a, const int b, const int c, const int d)
{
    return a * d - b * c;
}

inline double calcK(const int a, const int b)
{
    return (1.0 * b) / a;
}

string judge(const pair<int, int> ps[P_NUM], const pair<int, int> &sp)
{
    pair<int, int> p1(ps[1].first - ps[0].first, ps[1].second - ps[0].second),
        p2(sp.first - ps[0].first, sp.second - ps[0].second);
    int dt = det(p1.first, p1.second, p2.first, p2.second);
    if (dt > 0)
        return "COUNTER_CLOCKWISE";
    else if (dt < 0)
        return "CLOCKWISE";
    else
    {
        double k = calcK(p1.first, p2.first);
        if (k < 0)
            return "ONLINE_BACK";
        else if (k > 1)
            return "ONLINE_FRONT";
    }
    return "ON_SEGMENT";
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
        printf("%s\n", judge(ps, sp).c_str());
    }

    return 0;
}
