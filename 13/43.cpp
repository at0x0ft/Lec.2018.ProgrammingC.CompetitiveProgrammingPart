#include <bits/stdc++.h>

using namespace std;

#define MAT_LEN_MAX 100

int mat[MAT_LEN_MAX][MAT_LEN_MAX];

int cnt;

stack<int> stk;
void dfs(const int n)
{
    int v = stk.top();
    cnt++;
    printf("%d", v + 1);
    for (int i = 0; i < n; i++)
    {
        if (mat[v][i] == 1 && cnt < n)
        {
            printf(" ");
            stk.push(i);
            dfs(n);
        }
    }
    stk.pop();
}

queue<int> que;
bool hasFlg[MAT_LEN_MAX];
void bfs(const int n)
{
    int v = que.front();
    que.pop();
    cnt++;
    if (cnt < n)
    {
        printf("%d ", v + 1);
        for (int i = 0; i < n; i++)
        {
            if (mat[v][i] && !hasFlg[i])
            {
                que.push(i);
                hasFlg[i] = true;
            }
        }

        bfs(n);
    }
    else
        printf("%d", v + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int buf;
        scanf("%d", &buf);
        // v num
        scanf("%d", &buf);
        for (int j = 0; j < buf; j++)
        {
            int loc;
            scanf("%d", &loc);
            mat[i][loc - 1] = 1;
        }
    }

    cnt = 0;
    que.push(0);
    hasFlg[0] = true;
    bfs(n);
    printf("\n");

    cnt = 0;
    stk.push(0);
    dfs(n);
    printf("\n");

    return 0;
}