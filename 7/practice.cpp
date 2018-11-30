#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, min = INT_MAX, minIdx = -1;
    scanf("%d\n", &n);

    vector<long long int> r(n);
    long long int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &(r[i]));
        if (i > 0)
            ans = max(ans, r[i] - r[minIdx]);
        if (min > r[i])
        {
            min = r[i];
            minIdx = i;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
