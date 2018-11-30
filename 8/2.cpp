#include <bits/stdc++.h>
#include "compTmp.cpp"

using namespace std;

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