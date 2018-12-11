#include <bits/stdc++.h>

using namespace std;

int cor2Idx(const int i, const int j, const int width)
{
    return i * width + j;
}

void idx2Cor(const int idx, int &i, int &j, const int width)
{
    i = idx / width;
    j = idx % width;
}

bool isRange(const int i, const int j, const int w, const int h)
{
    return i >= 0 && i < h && j >= 0 && j < w;
}

void refine(vector<char> &v, const int i, const int j, const int w, const int h, int &ans)
{
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++)
    {
        if (!isRange(i + dx[k], j + dy[k], w, h))
            continue;
        int idx = cor2Idx(i + dx[k], j + dy[k], w);
        if (v[idx] == '-' || v[idx] == '#')
            continue;
        else if (v[idx] == '.')
        {
            v[idx] = '-';
            ans++;
            refine(v, i + dx[k], j + dy[k], w, h, ans);
        }
    }
}

int main()
{
    while (true)
    {
        int w;
        scanf("%d", &w);
        int h;
        scanf("%d", &h);

        if (w == 0 && h == 0)
            break;

        int si, sj;
        vector<char> v(w * h);
        for (int i = 0; i < w * h; i++)
        {
            char buf;
            scanf("%c", &buf);
            if (buf == '\n')
                i--;
            else
            {
                v[i] = buf;
                if (buf == '@')
                    idx2Cor(i, si, sj, w);
            }
        }

        int ans = 1;
        refine(v, si, sj, w, h, ans);
        printf("%d\n", ans);
    }

    return 0;
}
