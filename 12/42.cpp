#include <bits/stdc++.h>

using namespace std;

#define MAT_LEN_MAX 100

int mat[MAT_LEN_MAX][MAT_LEN_MAX];

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", mat[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
