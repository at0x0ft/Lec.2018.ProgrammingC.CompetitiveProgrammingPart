#include <bits/stdc++.h>

using namespace std;

#define QUEUE_SIZE 500

/* Dual LinkedList Definition */

typedef struct Node
{
    int data;
    Node *next;
    Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

void listAddNode(Node *prevNode, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *nextNode = prevNode->next;
    prevNode->next = newNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    newNode->prev = prevNode;

    newNode->data = val;
}

void listDelNode(Node *p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

void listInit()
{
    head = (Node *)malloc(sizeof(Node));
    tail = (Node *)malloc(sizeof(Node));
    head->next = tail;
    head->prev = NULL;
    head->data = INT_MAX;
    tail->next = NULL;
    tail->prev = head;
    tail->data = INT_MIN;
}

void listAddHead(int val)
{
    listAddNode(head, val);
}

void listAddTail(int val)
{
    listAddNode(tail->prev, val);
}

void listRemove(int val)
{
    for (Node *p = head->next; p != tail;)
    {
        if (p->data == val)
        {
            listDelNode(p);
            return;
        }
    }
}

void listDelHead()
{
    listDelNode(head->next);
}

void listDelTail()
{
    listDelNode(tail->prev);
    tail->prev = tail->prev;
}

void listDelAll()
{
    for (Node *p = head->next; p != tail;)
    {
        p = p->next;
        listDelNode(p->prev);
    }
}

void listFin()
{
    listDelAll();
    free(head);
    free(tail);
}

void printListLn()
{
    for (Node *p = head->next; p != tail; p = p->next)
    {
        cout << p->data;
        if (p->next != tail)
            printf(" ");
    }
    printf("\n");
}

/* END Dual LinkedList Definition */

void cReadLn(int &n)
{
    scanf("%d", &n);
}

int main()
{
    int n;
    cReadLn(n);
    listInit();

    int val;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "insertFirst")
        {
            scanf("%d", &val);
            listAddHead(val);
        }
        else if (cmd == "insertLast")
        {
            scanf("%d", &val);
            listAddTail(val);
        }
        else if (cmd == "delete")
        {
            scanf("%d", &val);
            listRemove(val);
        }
        else if (cmd == "deleteFirst")
            listDelHead();
        else if (cmd == "deleteLast")
            listDelTail();
        else if (cmd == "deleteAll")
            listDelAll();
    }

    printListLn();

    listFin();

    return 0;
}
