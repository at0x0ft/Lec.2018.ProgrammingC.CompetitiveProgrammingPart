#include <bits/stdc++.h>

using namespace std;

inline pair<int, int> addVec(const pair<int, int> &v1, const pair<int, int> &v2)
{
    return pair<int, int>(v1.first + v2.first, v1.second + v2.second);
}

inline pair<int, int> subVec(const pair<int, int> &v1, const pair<int, int> &v2)
{
    return pair<int, int>(v1.first - v2.first, v1.second - v2.second);
}

inline pair<int, int> mulVec(const int k, const pair<int, int> &vec)
{
    return pair<int, int>(vec.first * k, vec.second * k);
}

inline int innerProduct(const pair<int, int> &v1, const pair<int, int> &v2)
{
    return v1.first * v2.first + v1.second * v2.second;
}

inline int det2(const int m11, const int m12, const int m21, const int m22)
{
    return m11 * m22 - m21 * m12;
}

inline int det2Vec(const pair<int, int> v1, const pair<int, int> v2)
{
    return det2(v1.first, v2.first, v1.second, v2.second);
}

inline bool isCross(const pair<int, int> &p0, const pair<int, int> &p1, const pair<int, int> &p2, const pair<int, int> &p3)
{
    pair<int, int> p1p3 = subVec(p3, p1), p2p3 = subVec(p3, p2), p1p0 = subVec(p0, p1);
    int det = det2Vec(p1p0, p2p3);
    double s = (1.0 * det2Vec(p1p3, p2p3)) / det;
    double t = (1.0 * det2Vec(p1p0, p1p3)) / det;
    return 0 <= s && s <= 1 && 0 <= t && t <= 1;
}

inline int calcDistanceSq(const pair<int, int> &p1, const pair<int, int> &p2)
{
    const int x = p1.first - p2.first, y = p1.second - p2.second;
    return x * x + y * y;
}

inline int getMinDistanceSq(const pair<int, int> &s1p1, const pair<int, int> &s1p2, const pair<int, int> &s2p1, const pair<int, int> &s2p2)
{
    return min(calcDistanceSq(s1p1, s2p1), min(calcDistanceSq(s1p1, s2p2), min(calcDistanceSq(s1p2, s2p1), calcDistanceSq(s1p2, s2p2))));
}

double getPMinDistance(const pair<int, int> &p, const pair<int, int> &lp1, const pair<int, int> &lp2)
{
    pair<int, int> lp2lp1 = subVec(lp2, lp1), lp1p = subVec(p, lp1);
    int d = innerProduct(lp2lp1, lp1p);
    double llenSq = innerProduct(lp2lp1, lp2lp1);
    if (d <= 0)
        return sqrt(1.0 * calcDistanceSq(p, lp1));
    else if (d < llenSq)
    {
        int det = det2Vec(lp2lp1, lp1p);
        return sqrt((1.0 * det * det) / llenSq);
    }
    else
        return sqrt(1.0 * calcDistanceSq(p, lp2));
}

double calcDistance(const pair<int, int> &p0, const pair<int, int> &p1, const pair<int, int> &p2, const pair<int, int> &p3)
{
    if (isCross(p0, p1, p2, p3))
        return 0.0;
    else
        return min(min(getPMinDistance(p0, p2, p3), getPMinDistance(p1, p2, p3)), min(getPMinDistance(p2, p0, p1), getPMinDistance(p3, p0, p1)));
}

int main()
{
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        pair<int, int> p0, p1, p2, p3;
        scanf("%d %d %d %d %d %d %d %d",
              &(p0.first),
              &(p0.second),
              &(p1.first),
              &(p1.second),
              &(p2.first),
              &(p2.second),
              &(p3.first),
              &(p3.second));

        printf("%.10f\n", calcDistance(p0, p1, p2, p3));
    }

    return 0;
}
