#include <bits/stdc++.h>

using namespace std;

#define MAT_LEN_MAX 8

inline int loc(const int i, const int j)
{
    return i * MAT_LEN_MAX + j;
}

inline bool isMatRange(const int i, const int j)
{
    return 0 <= i && i < MAT_LEN_MAX && 0 <= j && j < MAT_LEN_MAX;
}

inline int getMatIJ(const long long int mat, const int i, const int j)
{
    return (mat >> loc(i, j)) & 1;
}

inline void setMatIJ(long long int &mat, long long int val, const int i, const int j)
{
    mat |= val << loc(i, j);
}

void refine(long long int &puttable, const int iloc, const int jloc)
{
    // row refine
    puttable |= ((long long int)(1 << MAT_LEN_MAX) - 1) << (MAT_LEN_MAX * iloc);

    for (int i = 0; i < MAT_LEN_MAX; i++)
    {
        // column refine
        puttable |= (long long int)1 << loc(i, jloc);

        // other refine (y = (x - i) + j, -(x - i) + j)
        if (isMatRange(i, i - iloc + jloc))
            puttable |= (long long int)1 << loc(i, i - iloc + jloc);
        if (isMatRange(i, -i + iloc + jloc))
            puttable |= (long long int)1 << loc(i, -i + iloc + jloc);
    }
}

bool solve(long long int mat, const int qcnt)
{
    if (qcnt == MAT_LEN_MAX)
        return true;

    bool res = false;
    for (int i = 0; i < MAT_LEN_MAX; i++)
    {
        for (int j = 0; j < MAT_LEN_MAX; j++)
        {
            if (getMatIJ(mat, i, j) == 0)
            {
                long long int prev = mat;
                setMatIJ(mat, 1, i, j);
                refine(mat, i, j);
                res |= solve(mat, qcnt + 1);
                mat = prev;
            }
        }
    }
    return res;
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
                setMatIJ(mat, 1, i, j);
                refine(mat, i, j);
                qcnt++;
            default:
                break;
            }
        }
    }

    printf("%s\n", solve(mat, qcnt) ? "Yes" : "No");

    return 0;
}
