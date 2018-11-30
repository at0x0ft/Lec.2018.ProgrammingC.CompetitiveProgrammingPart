#include <bits/stdc++.h>

using namespace std;

void cReadLn(int &n)
{
    scanf("%d", &n);
}

void cReadLn(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

void cPrintLn(const int &a)
{
    printf("%d\n", a);
}

void cPrintLn(const std::vector<int> &v, char delimiter = ' ')
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i];
        if (i != n - 1)
            printf("%c", delimiter);
        else
            printf("\n");
    }
}

int bubbleSort(vector<int> &a)
{
    int flg = 1, n = a.size(), cnt = 0;
    while (flg)
    {
        flg = 0;
        for (int j = n - 1; j >= 1; j--)
        {
            if (a[j] > a[j - 1])
            {
                swap(a[j], a[j - 1]);
                flg = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    cReadLn(n);
    vector<int> v(n);
    cReadLn(v);

    int cnt = bubbleSort(v);

    cPrintLn(cnt);
    cPrintLn(v);

    return 0;
}