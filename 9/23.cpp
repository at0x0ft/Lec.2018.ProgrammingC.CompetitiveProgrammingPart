#include <bits/stdc++.h>

using namespace std;

#define A_MAX 10000

void countingSort(const vector<int> &a, vector<int> &b, const int k)
{
    vector<int> c(k + 1);
    for (int i = 0; i <= k; i++)
    {
        c[i] = 0;
    }

    int n = a.size();
    for (int j = 0; j < n; j++)
        c[a[j]]++;

    // Printing counting_array.
    int sum = 0;
    for (int i = 0; sum < n; i++)
    {
        sum += c[i];
        printf("%d", c[i]);
        if (sum < n)
            printf(" ");
    }
    printf("\n");
    // END printing counting_array.

    for (int i = 1; i <= k; i++)
        c[i] += c[i - 1];

    for (int j = n - 1; j >= 0; j--)
    {
        b[n - 1 - (c[a[j]] - 1)] = a[j];
        c[a[j]]--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    countingSort(a, b, A_MAX);
    for (int i = 0; i < n; i++)
    {
        printf("%d", b[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
