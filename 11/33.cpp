#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    Node *right, *left, *parent;
};

Node *root, *nullNode;

Node *createNode(const int key)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->left = nullNode;
    n->right = nullNode;
    return n;
}

void insert(const int k)
{
    Node *y = root, *z = createNode(k);
    for (Node *i = root; i != nullNode; z->key < i->key ? i = i->left : i = i->right)
    {
        y = i;
    }

    z->parent = y;
    if (y == nullNode)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

bool find(Node *n, const int k)
{
    if (n == nullNode)
        return false;
    if (k < n->key)
        return find(n->left, k);
    else if (k > n->key)
        return find(n->right, k);
    return true;
}

Node *findNode(Node *n, const int k)
{
    for (; n != nullNode; k < n->key ? n = n->left : n = n->right)
        if (n->key == k)
            return n;
    return nullNode;
}

Node *getMin(Node *n)
{
    while (n->left != nullNode)
        n = n->left;
    return n;
}

Node *getNext(Node *n)
{
    if (n->right != nullNode)
    {
        return getMin(n->right);
    }

    Node *np = n->parent;
    while (np != nullNode && n == np->right)
    {
        n = np;
        n = np->parent;
    }
    return n;
}

void deleteNode(Node *n)
{
    Node *loc, *locChild;

    loc = n->left == nullNode || n->right == nullNode ? n : getNext(n);

    locChild = loc->left != nullNode ? loc->left : loc->right;

    if (locChild != nullNode)
        locChild->parent = loc->parent;

    if (loc->parent == nullNode)
        root = locChild;
    else
        loc == loc->parent->left ? loc->parent->left : loc->parent->right = locChild;

    if (loc != n)
        n->key = loc->key;

    free(loc);
}

void inorder(const Node *n)
{
    if (n == nullNode)
        return;
    inorder(n->left);
    printf(" %d", n->key);
    inorder(n->right);
}

void preorder(const Node *n)
{
    if (n == nullNode)
        return;
    printf(" %d", n->key);
    preorder(n->left);
    preorder(n->right);
}

void finalizeNode(Node *n)
{
    if (n == nullNode)
        return;
    finalizeNode(n->left);
    finalizeNode(n->right);
    free(n);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string ord;
        cin >> ord;
        if (ord == "insert")
        {
            int k;
            cin >> k;
            insert(k);
        }
        else if (ord == "find")
        {
            int k;
            cin >> k;
            Node *tmp;
            printf("%s\n", find(root, k) ? "yes" : "no");
        }
        else if (ord == "delete")
        {
            int k;
            cin >> k;
            deleteNode(findNode(root, k));
        }
        else
        {
            inorder(root);
            printf("\n");

            preorder(root);
            printf("\n");
        }
    }

    finalizeNode(root);

    return 0;
}