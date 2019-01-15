#include <bits/stdc++.h>

using namespace std;

#define MAX_STR_LEN 21

int mat[MAX_STR_LEN][MAX_STR_LEN];

int calc(vector<string> route, const int w, const int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i != 0 && j != 0)
            {
                mat[i][j] += route[i - 1][j] != 'X' ? mat[i - 1][j] : 0;
                mat[i][j] += route[i][j - 1] != 'X' ? mat[i][j - 1] : 0;
            }
            else
            {
                mat[i][j] = 1;
            }
        }
    }

    return mat[h - 1][w - 1];
}

int main()
{
    int w, h;
    scanf("%d %d", &w, &h);

    vector<string> route(h);
    for (int i = 0; i < h; i++)
    {
        cin >> route[i];
    }

    printf("%d\n", calc(route, w, h));

    return 0;
}
