#include <bits/stdc++.h>

using namespace std;

/* Q.: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_B&lang=jp */

struct node
{
    int parent;
    int sibling;
    int left, right;
    int chCnt;
    int depth;
    int height;
    string type;
} Node;

int adjustDepth(vector<node> &v, int id, const int depth)
{
    v[id].depth = depth;
    int len = v[id].chCnt;

    int lh = -1, rh = -1;
    if (v[id].left >= 0)
        lh = adjustDepth(v, v[id].left, depth + 1);
    if (v[id].right >= 0)
        rh = adjustDepth(v, v[id].right, depth + 1);

    v[id].height = max(lh, rh) + 1;

    return v[id].height;
}

int findRootId(const vector<node> &t, const int id)
{
    return t[id].parent < 0 ? id : findRootId(t, id + 1);
}

int main()
{
    int n;
    scanf("%d\n", &n);
    vector<node> t(n);
    for (int i = 0; i < n; i++)
    {
        t[i].parent = -1;
        t[i].sibling = -1;
        t[i].left = -1;
        t[i].right = -1;
        t[i].chCnt = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int id, chN;
        scanf("%d", &id);
        scanf("%d %d", &(t[id].left), &(t[id].right));

        if (t[id].left < 0 && t[id].right < 0)
            t[id].type = "leaf";
        else
        {
            t[id].type = "internal node";
            t[t[id].left].parent = id;
            t[t[id].right].parent = id;
            t[t[id].left].sibling = t[id].right;
            t[t[id].right].sibling = t[id].left;

            if (t[id].left >= 0 && t[id].right >= 0)
                t[id].chCnt = 2;
            else
                t[id].chCnt = 1;
        }
    }

    adjustDepth(t, findRootId(t, 0), 0);

    for (int i = 0; i < n; i++)
    {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
               i,
               t[i].parent,
               t[i].sibling,
               t[i].chCnt,
               t[i].depth,
               t[i].height,
               t[i].parent == -1
                   ? "root"
                   : t[i].type.c_str());
    }

    return 0;
}
