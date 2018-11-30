#include <bits/stdc++.h>
#include "compTmp.cpp"

using namespace std;

/* Stack class definition. */

class Stack
{
  private:
    int *_data;
    int &_top;

  public:
    Stack(int n);
    ~Stack();
    int Pop();
    void Push(int v);
};

Stack::Stack(int n) : _data((int *)malloc(sizeof(int) * n))
{
    _top = 0;
}

Stack::~Stack()
{
    if (_data != NULL)
        free(_data);
}

int Stack::Pop()
{
    return _data[_top--];
}

void Stack::Push(int v)
{
    _data[_top++] = v;
}

/* End stack class definition. */

long long int add(Stack &s)
{
    return s.Pop() + s.Pop();
}

long long int sub(Stack &s)
{
    return s.Pop() - s.Pop();
}

long long int mul(Stack &s)
{
    return s.Pop() * s.Pop();
}

long long int div(Stack &s)
{
    return s.Pop() / s.Pop();
}

int parseExpression()
{
    char buf;
    scanf("%c", &buf);
}

int main()
{
    int n;
    cReadLn(n);
    vector<int> v(n);
    cReadLn(v);

    int cnt = selectionSort(v);

    cPrintLn(cnt);
    cPrintLn(v);

    return 0;
}