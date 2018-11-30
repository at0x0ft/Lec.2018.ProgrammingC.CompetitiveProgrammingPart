#include <bits/stdc++.h>

using namespace std;

/* MyStack class definition. */

class MyStack
{
  private:
    long long int *_data = NULL;
    int &_top;

  public:
    MyStack();
    MyStack(int n);
    ~MyStack();
    long long int pop();
    void push(long long int v);
};

/*
MyStack::MyStack()
{
    _top = 0;
    _data = NULL;
}
*/

MyStack::MyStack(int n) // : _data((long long int *)malloc(sizeof(long long int) * n))
{
    this->_top = 0;
    this->_data = (long long int *)malloc(sizeof(long long int) * n);
}

MyStack::~MyStack()
{
    if (_data != NULL)
        free(_data);
}

long long int MyStack::pop()
{
    return _data[_top--];
}

void MyStack::push(long long int v)
{
    _data[_top++] = v;
}

/* End MyStack class definition. */

void cReadLn(std::string &str)
{
    cin >> str;
}

void cPrintLn(long long int n)
{
    printf("%lld\n", n);
}

int parseNum(const string &exp, int &startIdx)
{
    int i;
    for (i = 0; exp[startIdx + i] != ' '; i++)
        ;

    int res = atoi(exp.substr(startIdx, i).c_str());
    startIdx = i + 1;
    return res;
}

long long int calcExp(const string &exp)
{
    int n = exp.size();
    MyStack s(201);
    for (int i = 0; i < n; i++)
    {
        if (0 <= exp[i] && exp[i] <= 9)
            s.push(parseNum(exp, i));
        else if (exp[i] == '+')
            s.push(s.pop() + s.pop());
        else if (exp[i] == '*')
            s.push(s.pop() * s.pop());
    }

    return s.pop();
}

int main()
{
    string buf;
    cReadLn(buf);

    cPrintLn(calcExp(buf));

    return 0;
}