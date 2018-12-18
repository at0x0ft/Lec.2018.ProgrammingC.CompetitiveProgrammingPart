#include <bits/stdc++.h>

using namespace std;

int findMin(const vector<int> &v, const int l, const int r)
{
    if (l == r)
    {
        printf("%d\n", v[l]);
        return v[l];
    }
    int mid = (l + r) / 2, ret = min(findMin(v, mid + 1, r), findMin(v, l, mid));
    printf("%d\n", ret);
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    findMin(v, 0, n - 1);

    return 0;
}
