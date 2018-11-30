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

void bubbleSort(int n, vector<int> &a, int &cnt)
{
    int flag = 1; // 逆の隣接要素が存在する
    cnt = 0;
    while (flag)
    {
        flag = 0;
        for (int j = n - 1; j >= 1; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                flag = 1;
                cnt++;
            }
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

    bubbleSort(n, r, cnt);
    printArray(n, r);
    printf("%d\n", cnt);

    return 0;
}
