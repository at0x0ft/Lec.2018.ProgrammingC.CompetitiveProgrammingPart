#include <bits/stdc++.h>

using namespace std;

void cReadLn(int &n)
{
    scanf("%d", &n);
}

void cPrintLn(const int &a)
{
    printf("%d\n", a);
}

void cReadLn(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

int findMinDiff(vector<int> &v)
{
    sort(v.begin(), v.end());

    int minDiff = v[1] - v[0], n = v.size();
    for (int i = 1; i < n - 1; i++)
    {
        minDiff = min(minDiff, v[i + 1] - v[i]);
    }
    return minDiff;
}

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            break;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
        }

        printf("%d\n", findMinDiff(v));
    }

    return 0;
}
