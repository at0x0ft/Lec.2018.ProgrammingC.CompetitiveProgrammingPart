#include <bits/stdc++.h>

using namespace std;

#define MAT_LEN_MAX 8

int HasQueen(const int mat, const int i, const int j)
{
    return (mat >> i * MAT_LEN_MAX + j) & 1;
}

void refine(bool **mat, const int iloc, const int jloc)
{
    for (int i = 0; i < MAT_LEN_MAX; i++)
    {
        mat[i][jloc] = false;
        mat[iloc][i] = false;
        if (iloc + jloc - i > 0 && iloc + jloc - i < MAT_LEN_MAX)
            mat[i][iloc + jloc - i] = false;
        if (iloc - jloc - i > 0 && iloc - jloc - i < MAT_LEN_MAX)
            mat[i][iloc - jloc - i] = false;
    }
}

bool solve(long long int mat)
{
    long long int prev = mat;
    for (int i = 0; i < MAT_LEN_MAX * MAT_LEN_MAX; i++)
    {
        ;
    }
}

int main()
{
    long long int mat = 0;
    int qcnt = 0;
    for (int i = 0; i < MAT_LEN_MAX; i++)
    {
        string buf;
        cin >> buf;
        for (int j = 0; j < MAT_LEN_MAX; j++)
        {

            switch (buf[j])
            {
            case 'Q':
                mat++;
            default:
                break;
            }
        }
        if (i != MAT_LEN_MAX - 1)
            mat = mat << 1;
    }

    printf("%s\n", solve(mat, ))

        return 0;
}
