#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, const int p, const int r, int &cnt)
{
    cnt++;
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] >= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

int quickSort(vector<int> &a, const int p, const int r, int &cnt)
{
    if (p < r)
    {
        int q = partition(a, p, r, cnt);
        quickSort(a, p, q - 1, cnt);
        quickSort(a, q + 1, r, cnt);
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int cnt = 0;
    cnt = quickSort(a, 0, n - 1, cnt);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    printf("%d\n", cnt);

    return 0;
}
