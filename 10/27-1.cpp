#include <bits/stdc++.h>

using namespace std;

/* Q.: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A&lang=jp */

struct node
{
    int parent;
    int depth;
    string type;
    vector<int> children;
} Node;

void adjustDepth(vector<node> &v, int id, const int depth)
{
    v[id].depth = depth;
    int len = v[id].children.size();
    for (int i = 0; i < len; i++)
    {
        adjustDepth(v, v[id].children[i], depth + 1);
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    vector<node> t(n);
    vector<bool> isRoot(n);
    for (int i = 0; i < n; i++)
    {
        t[i].parent = -1;
        t[i].depth = 0;
        isRoot[i] = true;
    }

    for (int i = 0; i < n; i++)
    {
        int id, chN;
        scanf("%d %d", &id, &chN);

        t[id].children.resize(chN);
        if (chN > 0)
            t[id].type = "internal node";
        else
            t[id].type = "leaf";

        for (int j = 0; j < chN; j++)
        {
            int ch;
            scanf("%d", &ch);
            t[id].children[j] = ch;
            t[ch].parent = id;
            isRoot[ch] = false;
        }
    }

    int rootId = 0;
    for (int i = 0; i < n; i++)
    {
        if (isRoot[i])
        {
            rootId = i;
            break;
        }
    }

    adjustDepth(t, rootId, 0);

    for (int i = 0; i < n; i++)
    {
        printf("node %d: parent = %d, depth = %d, %s, [",
               i,
               t[i].parent,
               t[i].depth,
               t[i].parent == -1
                   ? "root"
                   : t[i].type.c_str());
        int chSize = t[i].children.size();
        for (int j = 0; j < chSize; j++)
        {
            printf("%d", t[i].children[j]);
            if (j != chSize - 1)
                printf(", ");
        }
        printf("]\n");
    }

    return 0;
}
