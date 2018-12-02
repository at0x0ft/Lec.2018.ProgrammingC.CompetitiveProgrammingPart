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

int selectionSort(vector<int> &a)
{
    int n = a.size(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] > a[minj])
                minj = j;
        }
        if (i < minj)
        {
            swap(a[i], a[minj]);
            cnt++;
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

    int cnt = selectionSort(v);

    cPrintLn(cnt);
    cPrintLn(v);

    return 0;
}