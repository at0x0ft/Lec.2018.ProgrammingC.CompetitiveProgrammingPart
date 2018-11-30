#include <bits/stdc++.h>
#include "compTmp.cpp"

using namespace std;

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