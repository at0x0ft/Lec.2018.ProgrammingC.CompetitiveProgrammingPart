#include <bits/stdc++.h>

using namespace std;

#define STACK_SIZE 100 + 101

/* Stack Definition */
long long int myStack[STACK_SIZE];
int stackTop = 0;

void push(long long int val)
{
    myStack[stackTop++] = val;
}

long long int pop()
{
    return myStack[--stackTop];
}

/* END Stack Definition */

void cReadLn(std::string &str)
{
    getline(cin, str);
}

void cPrintLn(const long long int n)
{
    printf("%lld\n", n);
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

long long int parseNum(const char *exp, int &startIdx)
{
    long long int res = 0;
    for (; exp[startIdx] != ' '; startIdx++)
    {
        res *= 10;
        res += exp[startIdx] - '0';
    }

    return res;
}

void calcExp(const char *exp, int length)
{
    int n = length;
    for (int i = 0; i < n; i++)
    {
        if ('0' <= exp[i] && exp[i] <= '9')
        {
            push(parseNum(exp, i));
            cPrintLn(myStack, stackTop);
        }
        else if (exp[i] == '+')
        {
            push(pop() + pop());
            i++;
            cPrintLn(myStack, stackTop);
        }
        else if (exp[i] == '*')
        {
            push(pop() * pop());
            i++;
            cPrintLn(myStack, stackTop);
        }
        else if (exp[i] == '=')
            return; // 4debug
    }
}

int main()
{
    string buf;
    cReadLn(buf);

    calcExp(buf.c_str(), buf.length());

    return 0;
}
