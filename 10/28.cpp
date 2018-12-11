#include <bits/stdc++.h>

using namespace std;

struct node
{
    int parent;
    int left;
    int right;
    int sibling;
    int depth;
} Node;

int main()
{
    int n;
    scanf("%d\n", &n);
    vector<node> t(n);
    for (int i = 0; i < n; i++)
    {
        t[i].parent = -1;
        t[i].depth = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int id, chN;
        scanf("%d %d", &id, &chN);

        for (int j = 0; j < chN; j++)
        {
            int ch;
            scanf("%d", &ch);

            t[ch].parent = id;
            t[ch].depth = t[id].depth + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d", i, t[i].parent, t[i].depth);
        if (i != n - 1)
            printf("\n");
    }
    printf("\n");

    return 0;
}
