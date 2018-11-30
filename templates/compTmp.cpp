#include <bits/stdc++.h>

namespace cpt // cpt = Competitive Programming Templates.
{

#define __MAX_BUF_LEN__ 256

void printErrorExit(char *errmsg)
{
    fprintf(stderr, "[Error] : %s\n", errmsg);
    fprintf(stderr, "Exit.\n");
    exit(EXIT_FAILURE);
}

/*
#define DUMPOUT std::cerr
#define DEBUG_ON

#ifdef DEBUG_ON
#define DEB
#else
#define DEB / ## /
#endif

#define dump(...)                                                                                \
    DEB DUMPOUT << "\n";                                                                         \
    DUMPOUT << " === [Debug output : line = " << __LINE__ << " in " << __FUNCTION__ << "] === "; \
    DUMPOUT << "[Variables] : " << #__VA_ARGS__ << "\n";                                         \
    DUMPOUT << "[Values]    : ";                                                                 \
    dumpFunc(__VA_ARGS__);                                                                       \
    DUMPOUT << " === [END Debug output] === ";                                                   \
    DUMPOUT << "\n";

void dumpFunc()
{
    DUMPOUT << "\n";
}

template <class Head, class... Tail>
void dumpFunc(Head &&head, Tail &&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) == 0)
        DUMPOUT << " ";
    else
        DUMPOUT << ", ";
    dumpFunc(std::move(tail));
}

template <typename T>
ostream &operator<<(std::ostream &os, std::vector<T> &vec)
{
    os << "{";
    for (int i = 0; i < vec.size(); i++)
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    os << "}";
    return os;
}
*/

void cReadLn(int &n)
{
    scanf("%d", &n);
}

bool IsStringEnd(char *str, int idx)
{
    return str[idx] == '\0';
}

/*
void cReadLn(std::vector<int> &v, char deliminater = ' ')
{
    int n = v.size();
    char buf[__MAX_BUF_LEN__];
    int bufidx = 0;
    for (int i = 0; i < n; i++)
    {
        buf[bufidx++] = '%';
        if (IsStringEnd(buf, bufidx))
            printErrorExit("Buffet terminated in cReadLn.");

        buf[bufidx++] = 'd';
        if (IsStringEnd(buf, bufidx))
            printErrorExit("Buffet terminated in cReadLn.");

        if (i != n - 1)
            buf[bufidx++] = deliminater;
        if (IsStringEnd(buf, bufidx))
            printErrorExit("Buffet terminated in cReadLn.");
    }

    buf[bufidx] = '\0';

    scanf(bufidx);
}
*/

void cReadLn(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

void cReadLn(std::vector<char> &s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
        scanf("%c", &s[i]);
}

void cPrintLn(const int &a)
{
    printf("%d\n", a);
}

void cPrintLn(const long long int n)
{
    printf("%lld\n", n);
}

void cPrintLn(const int *array, const int arrayLength, const char delimiter = ' ')
{
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d", array[i]);
        if (i != arrayLength - 1)
            printf("%c", delimiter);
        else
            printf("\n");
    }
}

void cPrintLn(const long long int *array, const int arrayLength, const char delimiter = ' ')
{
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%lld", array[i]);
        if (i != arrayLength - 1)
            printf("%c", delimiter);
        else
            printf("\n");
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
        else
            printf("\n");
    }
}

/*
int main()
{
    int num = 2;
    double pi = 3.14;
    string str = "str";
    char *chararr = "chararr";
    std::vector<int> vec{1, 1, 2, 3};
    dump(num, pi, str, chararr, vec);

    return 0;
}
*/

} // namespace cpt
