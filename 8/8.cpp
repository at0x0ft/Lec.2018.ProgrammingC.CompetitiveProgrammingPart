#include <bits/stdc++.h>

using namespace std;

void cReadLn(int &n)
{
    scanf("%d", &n);
}

void cReadLn(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

bool binSearch(const vector<int> &s, const int val)
{
    int high = 0, low = s.size() - 1;
    if (low < 0)
        return false;
    while (low >= high)
    {
        int mid = (low + high) / 2;
        if (s[mid] == val)
        {
            return true;
        }
        else if (s[mid] < val)
        {
            low = mid - 1;
        }
        else
        {
            high = mid + 1;
        }
    }
    return false;
}

void refine(const vector<int> &s, vector<int> &t)
{
    int slen = s.size();
    for (int j = 0; j < t.size(); j++)
    {
        if (binSearch(s, t[j]))
            t.erase(t.begin() + j);
    }
}

void cPrintLn(const std::vector<int> &v, char delimiter = ' ')
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i];
        if (i != n - 1)
            printf("%c", delimiter);
    }
    printf("\n");
}

void cPrintLn(const int &a)
{
    printf("%d\n", a);
}

int main()
{
    int n;
    cReadLn(n);
    vector<int> s(n);
    cReadLn(s);
    int q;
    cReadLn(q);
    vector<int> t(q);
    cReadLn(t);

    refine(s, t);

    cPrintLn(t);
    cPrintLn(t.size());

    return 0;
}
