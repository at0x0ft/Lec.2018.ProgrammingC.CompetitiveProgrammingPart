#include <bits/stdc++.h>

using namespace std;

void printArray(int n, vector<int> &a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            printf(" ");
        else
            printf("\n");
    }
}

void insertionSort(int n, vector<int> &a)
{
    int v;
    for (int i = 0; i < n; i++)
    {
        v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printArray(n, a);
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

    vector<int> &r = a;

    insertionSort(n, r);

    return 0;
}
