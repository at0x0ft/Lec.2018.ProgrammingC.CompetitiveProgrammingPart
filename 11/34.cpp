#include <bits/stdc++.h>

using namespace std;

int parent(int i)
{
    return i / 2;
}
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

bool hasParent(int i, int n) { return parent(i) >= 1; }
bool hasLeft(int i, int n) { return left(i) <= n; }
bool hasRight(int i, int n) { return right(i) <= n; }

void maxHeapify(vector<int> &a, const int i)
{
    int l = left(i);
    int r = right(i);
    int max = i, h = a.size();
    if (l <= h && a[l] > a[max])
        max = l;
    if (r <= h && a[r] > a[max])
        max = r;
    if (max != i)
    {
        swap(a[i], a[max]);
        maxHeapify(a, max);
    }
}

void buildMaxHeap(vector<int> &a)
{
    int h = a.size();
    for (int i = h / 2; i > 0; i--)
    {
        maxHeapify(a, i);
    }
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
