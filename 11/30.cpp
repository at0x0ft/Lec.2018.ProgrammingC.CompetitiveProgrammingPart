#include <bits/stdc++.h>

using namespace std;

#define TREE_NUM 512
#define KEY_DEFAULT_VAL -1

struct Node
{
    int key, parent, left, right;
};

Node T[TREE_NUM];
int nodeNum = 0;

void preorder(int id)
{
    printf(" %d", T[id]);

    if (t[id].left != -1)
        preorder(t[id].left);

    if (t[id].right != -1)
        preorder(t[id].right);
}

void inorder(int id)
{
    if (t[id].left != -1)
        inorder(t[id].left);

    printf(" %d", id);

    if (t[id].right != -1)
        inorder(t[id].right);
}

Node createNode(int key)
{
    T[nodeNum].key = key;
    T[nodeNum].parent = -1;
    T[nodeNum].left = -1;
    T[nodeNum].right = -1;
    nodeNum++;
    return T[nodeNum];
}

void treeInit()
{
    for (int i = 0; i < TREE_NUM; i++)
    {
        T[i].key = KEY_DEFAULT_VAL;
        T[i].parent = -1;
        T[i].left = -1;
        T[i].right = -1;
    }
}

bool isNullNode(Node n)
{
    return n.key == KEY_DEFAULT_VAL;
}

void insert(Node *z)
{
    Node *p = NULL, *x = T;
    while (isNullNode(*x))
    {
        p = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
        z->parent = p;
        if (p == NULL)
            T[0] = *z;
        else if (z->key < p->key)
            p->left = z;
        else
            p->right = z;
    }
    nodeNum++;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    int cnt = 0;
    bool flg = true;
    cnt = 0;
    while (flg)
    {
        flg = false;
        for (int i = n - 1; i >= 1; i--)
        {
            if (v[i] > v[i - 1])
            {
                swap(v[i], v[i - 1]);
                flg = true;
                cnt++;
            }
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string ord;
        cin >> ord;
        if (ord == "print")
            printf("%d\n", extract(a));
        else // insert
        {
            int val;
            cin >> val;
            Node n = createNode(val);
            insert(&n);
        }
    }

    printf("%d\n", cnt);

    return 0;
}
