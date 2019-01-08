#include <bits/stdc++.h>

using namespace std;

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

bool hasParent(int i, int n) { return parent(i) >= 1; }
bool hasLeft(int i, int n) { return left(i) <= n; }
bool hasRight(int i, int n) { return right(i) <= n; }

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("node %d: key = %d, ", i, a[i]);
        if (hasParent(i, n))
            printf("parent key = %d, ", a[parent(i)]);
        if (hasLeft(i, n))
            printf("left key = %d, ", a[left(i)]);
        if (hasRight(i, n))
            printf("right key = %d, ", a[right(i)]);
        printf("\n");
    }

    return 0;
}
