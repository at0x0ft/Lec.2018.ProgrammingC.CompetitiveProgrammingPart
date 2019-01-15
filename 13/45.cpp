#include <bits/stdc++.h>

using namespace std;

#define MAX_FIB_NUM 30 + 1

long long int fibNum[MAX_FIB_NUM] = {[0] = 1, [1] = 1};

inline void calcFib(const int n)
{
    if (n >= 2)
        for (int i = 2; i <= n; i++)
            fibNum[i] = fibNum[i - 1] + fibNum[i - 2];
}

inline void printFibNum(const int n)
{
    printf("%lld", fibNum[0]);
    for (int i = 1; i <= n; i++)
    {
        printf(" %lld", fibNum[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    calcFib(n);
    printFibNum(n);

    return 0;
}
