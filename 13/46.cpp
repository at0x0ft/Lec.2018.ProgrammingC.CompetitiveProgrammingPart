#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

int n;
int mat[MAX_N][MAX_N];

int prim()
{
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    set<int> vst;

    int cv = 0, nc, sum = 0;
    while (true)
    {
        vst.insert(cv);
        if (vst.size() == n)
            break;
        for (int i = 0; i < n; i++)
        {
            if (mat[cv][i] > 0)
                pq.push(pair<int, pair<int, int> >(mat[cv][i], pair<int, int>(cv, i)));
        }

        while (!pq.empty())
        {
            nc = pq.top().first;
            cv = pq.top().second.second;
            pq.pop();
            if (vst.count(cv) == 0)
                break;
        }

        if (pq.empty())
            break;

        sum += nc;
    }

    return sum;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int buf;
            scanf("%d", &buf);

            if (i == j)
                mat[i][j] = 0;
            else
                mat[i][j] = buf;
        }
    }

    printf("%d\n", prim());

    return 0;
}

