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

int h = 0;

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

void insert(vector<int> &a, const int k)
{
    h++;
    a[h] = k;
    int i = h;
    while (i > 1 && a[parent(i)] < a[i])
    {
        swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}

int extract(vector<int> &a)
{
    if (h < 1)
        fprintf(stderr, "[ERROR]\n");
    int max = a[1];
    a[1] = a[h];
    h--;
    maxHeapify(a, 1);
    return max;
}

int main()
{
    vector<int> a(1000000);

    while (true)
    {
        string ord;
        cin >> ord;
        if (ord == "extract")
            printf("%d\n", extract(a));
        else if (ord == "end")
        {
            break;
        }
        else // insert
        {
            int val;
            cin >> val;
            insert(a, val);
        }
    }

    return 0;
}
