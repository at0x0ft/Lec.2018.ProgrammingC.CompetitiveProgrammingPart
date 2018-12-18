#include <bits/stdc++.h>

using namespace std;

int findMaxRec(const vector<int> &a, const int l, const int r)
{
    int res = INT_MIN;
    if (l == r - 1)
        res = a[l];
    else
    {
        int mid = (l + r) / 2;
        int lcnd = findMaxRec(a, l, mid);
        int rcnd = findMaxRec(a, mid, r);
        res = max(lcnd, rcnd);
    }
    printf("%d\n", res);

    return res;
}

int main()
{
    int m, nmin, nmax;
    scanf("%d %d %d", &m, &nmin, &nmax);
    vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p[i]);
    }

    sort(p.begin(), p.end());

    int gapMax = 0, n;

    for (int i = nmin; i <= nmax; i++)
    {
        int gap = p[m - i] - p[m - i - 1];
        if (gap > gapMax)
        {
            gapMax = gap;
            n = i;
        }
    }
    printf("%d\n", n);

    return 0;
}
