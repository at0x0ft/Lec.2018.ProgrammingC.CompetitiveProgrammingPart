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

void selectionSort(int n, vector<int> &a, int &cnt)
{
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minj])
                minj = j;
        }
        if (i < minj)
        {
            swap(a[i], a[minj]);
            cnt++;
        }
    }
}

int main()
{
    int n, cnt = 0;

    scanf("%d", &n);

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    vector<int> &r = a;

    selectionSort(n, r, cnt);
    printArray(n, r);
    printf("%d\n", cnt);

    return 0;
}
