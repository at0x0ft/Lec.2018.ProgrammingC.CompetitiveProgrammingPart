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

void refine(const vector<int> &s, vector<int> &t)
{
    int slen = s.size();
    for (int i = 0; i < slen; i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i] == t[j])
                t.erase(t.begin() + j);
        }
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
