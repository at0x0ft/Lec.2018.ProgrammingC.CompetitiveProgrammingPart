#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<int> &a, const int n, const int idx, const int m)
{
    if (m == 0)
        return true;
    if (idx >= n)
        return false;
    return solve(a, n, idx + 1, m) || solve(a, n, idx + 1, m - a[idx]);
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int q, m;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &m);
        printf("%s\n", solve(a, n, 0, m) ? "true" : "false");
    }

    return 0;
}
