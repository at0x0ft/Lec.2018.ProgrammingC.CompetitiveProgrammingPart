#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> dsts(n);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int buf;
            scanf("%d", &buf);
            if (buf != 0)
                dsts[cnt++] = j;
        }

        printf("%d %d", i + 1, cnt);
        for (int j = 0; j < cnt; j++)
        {
            printf(" %d", dsts[j] + 1);
        }
        printf("\n");
    }

    return 0;
}
