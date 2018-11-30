#include <bits/stdc++.h>

long long int factorial(long long int n)
{
    if (n == 0)
        return 1;
    else if (n >= 0)
        return n * factorial(n - 1);
}

int main()
{
    long long int n;
    scanf("%lld", &n);
    printf("%lld\n", factorial(n));
}