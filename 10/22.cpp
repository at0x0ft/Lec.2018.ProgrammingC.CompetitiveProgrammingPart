#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    int cnt = 0;
    bool flg = true;
    cnt = 0;
    while (flg)
    {
        flg = false;
        for (int i = n - 1; i >= 1; i--)
        {
            if (v[i] > v[i - 1])
            {
                swap(v[i], v[i - 1]);
                flg = true;
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
