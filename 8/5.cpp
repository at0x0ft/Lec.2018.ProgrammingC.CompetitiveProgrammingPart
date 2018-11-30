#include <bits/stdc++.h>

using namespace std;

#define QUEUE_SIZE 500

/* Queue Definition */

pair<string, long long int> myQueue[QUEUE_SIZE + 1];
int head = 0, tail = head;

bool myQueueIsEmpty()
{
    return head == tail;
}

bool myQueueIsFull()
{
    return ((head - 1) + (QUEUE_SIZE + 1)) % (QUEUE_SIZE + 1) == tail;
}

int size()
{
    if (head < tail)
        return tail - head;
    else
        return tail + QUEUE_SIZE - head;
}

void enqueue(pair<string, long long int> &val)
{
    if (myQueueIsFull())
    {
        fprintf(stderr, "[Error] : myQueue overflow.\n");
        exit(EXIT_FAILURE);
    }

    myQueue[tail++] = val;
    tail %= (QUEUE_SIZE + 1);
}

pair<string, long long int> dequeue()
{
    if (myQueueIsEmpty())
    {
        fprintf(stderr, "[Error] : myQueue underflow.\n");
        exit(EXIT_FAILURE);
    }

    pair<string, long long int> val = myQueue[head++];
    head %= (QUEUE_SIZE + 1);
    return val;
}

void printQueue()
{
    for (int i = head; i != tail; ++i %= QUEUE_SIZE)
    {
        cout << myQueue[i].first;
        printf(" %lld", myQueue[i].second);
        if ((i + 1) % QUEUE_SIZE != tail)
            printf(" ");
    }
    printf("\n");
}

/* END Queue Definition */

void cReadLn(int &n)
{
    scanf("%d", &n);
}

void roundRobin(const long long int cycleTime, pair<string, long long int> *results)
{
    long long int now = 0;
    while (!myQueueIsEmpty())
    {
        pair<string, long long int> execProc = dequeue();

        if (execProc.second - cycleTime > 0)
        {
            execProc.second -= cycleTime;
            enqueue(execProc);
            now += cycleTime;
        }
        else
        {
            *results = execProc;
            results->second += now;
            now = results->second;
            results++;
        }
        if (!myQueueIsEmpty())
            printQueue();
    }
}

int main()
{
    int n;
    cReadLn(n);
    long long int cycleTime;
    scanf("%lld", &cycleTime);
    pair<string, long long int> results[QUEUE_SIZE];
    for (int i = 0; i < n; i++)
    {
        pair<string, long long int> proc;
        cin >> proc.first;
        scanf("%lld", &(proc.second));
        enqueue(proc);
    }

    roundRobin(cycleTime, results);
    for (int i = 0; i < n; i++)
    {
        cout << results[i].first;
        printf(" %lld", results[i].second);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
