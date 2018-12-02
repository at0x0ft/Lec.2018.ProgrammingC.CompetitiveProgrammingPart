#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            printf(" ");
        else
            printf("\n");
    }
}

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

    scanf("%d", &n);

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    int cnt = insertionSort(v);

    printf("%d\n", cnt);
    printArray(v);

    return 0;
}