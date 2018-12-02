#include <bits/stdc++.h>

using namespace std;

void cReadLn(int &n)
{
    scanf("%d", &n);
}

void cReadLn(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

void cPrintLn(const int &a)
{
    printf("%d\n", a);
}

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
    cReadLn(n);
    vector<int> v(n);
    cReadLn(v);

    findMaxRec(v, 0, n);

    return 0;
}
