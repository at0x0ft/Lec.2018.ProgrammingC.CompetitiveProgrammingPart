#include <bits/stdc++.h>

using namespace std;

#define MAX_STR_LEN 1001

int mat[MAX_STR_LEN][MAX_STR_LEN];

int lcs(string x, string y)
{
    int xlen = x.length();
    int ylen = y.length();
    for (int i = 0; i < xlen; i++)
    {
        for (int j = 0; j < ylen; j++)
        {
            if (i != 0 && j != 0)
            {
                mat[i][j] = max(mat[i - 1][j - 1] + (x[i] == y[j]), max(mat[i - 1][j], mat[i][j - 1]));
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }

    // 4debug
    for (int i = 0; i < xlen; i++)
    {
        for (int j = 0; j < ylen; j++)
        {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    // 4debug

    return mat[xlen - 1][ylen - 1];
}

int main()
{
    string x, y;
    cin >> x >> y;
    printf("%d\n", lcs(x, y));

    return 0;
}
