#include <bits/stdc++.h>

using namespace std;

#define MAX_FIB_NUM 100

int fibNum[MAX_FIB_NUM];

int fib(int n)
{
    if (n == 0)
    {
        fibNum[n] = 0;
        return 0;
    }
    else if (n == 1 ||)
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    buildMaxHeap(a);

    for (int i = 1; i <= n; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}
