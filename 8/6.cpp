#include <bits/stdc++.h>

using namespace std;

#define QUEUE_SIZE 500

/* Dual LinkedList Definition */

typedef struct Node
{
    string data;
    Node *next;
    Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *hPtr = NULL;
Node *tPtr = NULL;

void listAddNode(Node *prevNode, string val)
{
    fprintf(stderr, "debug print, prevNode = %s\n", prevNode->data.c_str()); // 4debug
    Node *newNode = (Node *)malloc(sizeof(Node *));
    Node *nextNode = prevNode->next;
    prevNode->next = newNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    newNode->prev = prevNode;

    newNode->data = val;

    cout << newNode->next->data << " " << newNode->prev->data << endl; // 4debug
}

void listDelNode(Node *p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

void listInit()
{
    head = (Node *)malloc(sizeof(Node *));
    tail = (Node *)malloc(sizeof(Node *));
    head->next = tail;
    head->prev = NULL;
    head->data = "LIST_FIRST_NODE";
    hPtr = head->next;
    tail->next = NULL;                                                // this is the bug part;
    fprintf(stderr, "debug print : head = %s\n", head->data.c_str()); // 4debug
    tail->prev = head;
    tail->data = "LIST_LAST_NODE";
    tPtr = tail->prev;

    fprintf(stderr, "debug print : head = %s, tail = %s\n", head->data.c_str(), tail->data.c_str()); // 4debug
}

void listAddHead(string val)
{
    listAddNode(head, val);
}

void listAddTail(string val)
{
    listAddNode(tPtr, val);
}

void listRemove(string val)
{
    for (Node *p = hPtr; p != tail;)
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
    listDelNode(hPtr);
    hPtr = head->next;
}

void listDelTail()
{
    listDelNode(tPtr);
    tPtr = tail->prev;
}

void listDelAll()
{
    for (Node *p = hPtr; p != tail;)
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
    for (Node *p = hPtr; p != tail;)
    {
        p = p->next;
        cout << p->prev->data;
        if (p != tail)
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

    string cmd, val;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "insertFirst")
        {
            cin >> val;
            listAddHead(val);
        }
        else if (cmd == "insertLast")
        {
            cin >> val;
            listAddTail(val);
        }
        else if (cmd == "delete")
        {
            cin >> val;
            listRemove(val);
        }
        else if (cmd == "deleteFirst")
            listDelHead();
        else if (cmd == "deleteLast")
            listDelTail();
        else if (cmd == "deleteAll")
            listDelAll();
    }

    listFin();

    return 0;
}
