#include <bits/stdc++.h>

using namespace std;

void cReadLn(int &n)
{
    scanf("%d", &n);
}

int main()
{
    int n;
    cReadLn(n);
    set<string> dict;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        string val;
        cin >> val;
        if (cmd == "add")
            dict.insert(val);
        else if (cmd == "remove")
            dict.erase(val);
        else if (cmd == "find")
            dict.count(val) > 0 ? printf("yes\n") : printf("no\n");
    }

    return 0;
}
