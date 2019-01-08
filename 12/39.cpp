#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &a, const int left, const int mid, const int right, int &revNum)
{
    const int n1 = mid - left;
    const int n2 = right - mid;
    vector<int> l(n1 + 1), r(n2 + 1);

    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[left + i];
    }
    l[n1] = INT_MAX;

    for (int i = 0; i < n2; i++)
    {
        r[i] = a[mid + i];
    }
    r[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i++];
        }
        else
        {
            a[k] = r[j];
            revNum += j + mid - k;
            j++;
        }
    }

    return revNum;
}

void mergeSort(vector<int> &a, const int left, const int right, int &revNum)
{
    if (left + 1 < right)
    {
        const int mid = (left + right) / 2;
        mergeSort(a, left, mid, revNum);
        mergeSort(a, mid, right, revNum);
        revNum = merge(a, left, mid, right, revNum);
        printf("%d\n", revNum);
    }
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

    int revNum = 0;
    mergeSort(a, 0, n, revNum);

    return 0;
}
