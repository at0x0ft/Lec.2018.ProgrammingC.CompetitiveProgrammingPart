#include <bits/stdc++.h>

using namespace std;

char convertKey2Char(const char key, const int cnt)
{
    switch (key)
    {
    case '1':
    {
        switch (cnt % 5)
        {
        case 0:
            return '.';
        case 1:
            return ',';
        case 2:
            return '!';
        case 3:
            return '?';
        case 4:
            return ' ';
        }
        break;
    }
    case '2':
        return 'a' + (cnt % 3);
    case '3':
        return 'd' + (cnt % 3);
    case '4':
        return 'g' + (cnt % 3);
    case '5':
        return 'j' + (cnt % 3);
    case '6':
        return 'm' + (cnt % 3);
    case '7':
        return 'p' + (cnt % 4);
    case '8':
        return 't' + (cnt % 3);
    case '9':
        return 'w' + (cnt % 4);
    }

    return '^';
}

char resetChar(const string s, int &idx, const int slen)
{
    while (s[idx] == '0' && idx < slen)
    {
        idx++;
    }
    return s[idx];
}

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        string buf;
        getline(cin, buf);
        int n = buf.size(), j = 0;
        string ans = "";
        char key = resetChar(buf, j, n);
        int cnt = 0;
        for (j = j + 1; j < n; j++)
        {
            if (buf[j] == '0')
            {
                ans.push_back(convertKey2Char(key, cnt));
                j++;
            }
            else if (buf[j] == key)
            {
                cnt++;
                continue;
            }
            key = resetChar(buf, j, n);
            cnt = 0;
        }

        cout << ans << "\n";
    }

    return 0;
}
