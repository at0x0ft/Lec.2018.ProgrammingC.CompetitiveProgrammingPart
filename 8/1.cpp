#include <bits/stdc++.h>

using namespace std;
using namespace cpt;

int insertionSort(vector<int> &a)
{
    int v, cnt = 0, n = a.size();
    for (int i = 0; i < n; i++)
    {
        v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < v)
        {
            a[j + 1] = a[j];
            cnt++;
            j--;
        }
        a[j + 1] = v;
    }

    return cnt;
}

int main()
{
    int n;

    cReadLn(n);
    vector<int> v(n);
    cReadLn(v);

    int cnt = insertionSort(v);

    printf("%d\n", cnt);
    cPrintLn(v);

    return 0;
}