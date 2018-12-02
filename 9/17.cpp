#include <bits/stdc++.h>

using namespace std;

// create m bits sequence 1 numbers.
void createCheckNums(const int n, const int m, vector<int> &res)
{
    int mcn = (1 << m) - 1;
    res[0] = mcn;
    for (int i = 0; i < n - m; i++)
    {
        mcn = mcn << 1;
        res[i + 1] = mcn;
    }
}

int checkAll(const vector<int> &checks, const int n)
{
    int cnt = 0, cnum = checks.size();
    int allNums = 1 << n;
    for (int i = 0; i < allNums; i++)
    {
        for (int j = 0; j < cnum; j++)
        {
            if ((i & checks[j]) == checks[j])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);

    vector<int> checks(n - m + 1);
    createCheckNums(n, m, checks);
    printf("%d\n", checkAll(checks, n));

    return 0;
}
