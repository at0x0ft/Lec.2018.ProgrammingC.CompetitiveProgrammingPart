#include <bits/stdc++.h>

using namespace std;

long long int combi(const int n, const int r)
{
    if (n - r < r)
        return combi(n, n - r);

    long long int res = 1;
    for (int i = 1; i <= r; i++)
    {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main()
{
    int m;
    scanf("%d", &m);
    int n;
    scanf("%d", &n);

    printf("%lld\n", combi(m - 1, m - n));

    return 0;
}
