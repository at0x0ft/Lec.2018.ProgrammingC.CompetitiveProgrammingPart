#include <bits/stdc++.h>

using namespace std;

#define MAT_LEN 10

int mat[MAT_LEN][MAT_LEN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool isMatRange(const int i, const int j)
{
    return 0 <= i && i < MAT_LEN && 0 <= j && j < MAT_LEN;
}

queue<pair<pair<int, int>, int>> que;

int search(pair<int, int> &g)
{
    pair<pair<int, int>, int> cc = que.front();
    que.pop();

    if (cc.first == g)
        return cc.second;

    for (int i = 0; i < 4; i++)
    {
        if (isMatRange(cc.first.first + dx[i], cc.first.second + dy[i]) && mat[cc.first.first + dx[i]][cc.first.second + dy[i]] == 1)
        {
            mat[cc.first.first + dx[i]][cc.first.second + dy[i]] = 0;
            que.push(pair<pair<int, int>, int>(pair<int, int>(cc.first.first + dx[i], cc.first.second + dy[i]), cc.second + 1));
        }
    }
    return search(g);
}

int main()
{
    pair<int, int> start, goal;

    for (int j = 0; j < MAT_LEN; j++)
    {
        string line;
        cin >> line;
        for (int i = 0; i < MAT_LEN; i++)
        {

            switch (line[i])
            {
            case '#':
                mat[j][i] = 0;
                break;
            case '.':
                mat[j][i] = 1;
                break;
            case 'S':
                mat[j][i] = 1;
                start.first = j;
                start.second = i;
                break;
            case 'G':
                mat[j][i] = 1;
                goal.first = j;
                goal.second = i;
                break;
            default:
                break;
            }
        }
    }

    for (int i = 0; i < MAT_LEN; i++)
    {
        for (int j = 0; j < MAT_LEN; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }

    que.push(pair<pair<int, int>, int>(start, 0));

    printf("%d\n", search(goal));

    return 0;
}
