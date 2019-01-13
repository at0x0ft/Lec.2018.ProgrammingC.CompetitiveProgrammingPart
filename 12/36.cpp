#include <bits/stdc++.h>

using namespace std;

#define MAX_MN 20

pair<bool, long long int> dp[MAX_MN + 1][MAX_MN + 1];

long long int combi(const int n, const int r)
{
    if (dp[n][r].first)
        return dp[n][r].second;

    if (r == 0)
    {
        dp[n][r].first = true;
        dp[n][r].second = 1;
        return 1;
    }
    if (r > n - r)
        return combi(n, n - r);

    dp[n][r].first = true;
    dp[n][r].second = combi(n - 1, r - 1) + combi(n - 1, r);
    return dp[n][r].second;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%lld\n", combi(m + n - 1, m));

    return 0;
}
