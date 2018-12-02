#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, const int left, const int mid, const int right, int &cnt)
{
    cnt++;
    int n1 = mid - left, n2 = right - mid;
    vector<int> l(n1 + 1), r(n2 + 1);
    for (int i = 0; i < n1; i++)
        l[i] = a[left + i];
    l[n1] = INT_MIN;
    for (int i = 0; i < n2; i++)
        r[i] = a[mid + i];
    r[n2] = INT_MIN;

    int i = 0, j = 0;

    for (int k = left; k < right; k++)
    {
        if (l[i] >= r[j])
            a[k] = l[i++];
        else
            a[k] = r[j++];
    }
}

int mergeSort(vector<int> &a, const int left, const int right, int &cnt)
{
    int mid;
    if (left + 1 < right)
    {
        mid = (left + right) / 2;
        mergeSort(a, left, mid, cnt);
        mergeSort(a, mid, right, cnt);
        merge(a, left, mid, right, cnt);
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
    cnt = mergeSort(a, 0, n, cnt);
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
