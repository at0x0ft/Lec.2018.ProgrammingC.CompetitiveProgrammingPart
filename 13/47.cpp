#include <bits/stdc++.h>

using namespace std;

#define MAT_MAX 100

int mat[MAT_MAX][MAT_MAX];

void matInit(const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = i == j ? 0 : -1;
        }
    }
}

int findMin(const int s, const int n, const vector<bool> &v)
{
    int min = INT_MAX, res = -1;
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && mat[s][i] >= 0 && mat[s][i] < min)
        {
            min = mat[s][i];
            res = i;
        }
    }
    return res;
}

void setTrue(const int i, vector<bool> &v, int &cnt)
{
    v[i] = true;
    cnt++;
}

int main()
{
    int n;
    scanf("%d", &n);
    matInit(n);

    for (int i = 0; i < n; i++)
    {
        int buf, nn;
        scanf("%d %d", &buf, &nn);
        for (int j = 0; j < nn; j++)
        {
            int d, c;
            scanf("%d %d", &d, &c);
            mat[i][d] = c;
        }
    }

    vector<bool> visited(n, false);
    int cnt = 0;
    setTrue(0, visited, cnt);
    while (cnt < n)
    {
        int nv = findMin(0, n, visited);
        for (int i = 0; i < n; i++)
        {
            if (mat[nv][i] >= 0)
            {
                int cnd = mat[0][nv] + mat[nv][i], prv = mat[0][i];
                mat[0][i] = prv >= 0 ? min(prv, cnd) : cnd;
            }
        }
        setTrue(nv, visited, cnt);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", i, mat[0][i]);
    }

    return 0;
}
