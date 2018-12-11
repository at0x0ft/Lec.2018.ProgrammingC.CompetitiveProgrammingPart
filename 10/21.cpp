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
    cPrintLn(res);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    findMaxRec(v, 0, n);

    return 0;
}
