#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int parent, left, right;
} node;

void preorder(int id, vector<Node> &t)
{
    printf(" %d", id);

    if (t[id].left != -1)
        preorder(t[id].left, t);

    if (t[id].right != -1)
        preorder(t[id].right, t);
}

void inorder(int id, vector<Node> &t)
{
    if (t[id].left != -1)
        inorder(t[id].left, t);

    printf(" %d", id);

    if (t[id].right != -1)
        inorder(t[id].right, t);
}

void postorder(int id, vector<Node> &t)
{
    if (t[id].left != -1)
        postorder(t[id].left, t);
    if (t[id].right != -1)
        postorder(t[id].right, t);

    printf(" %d", id);
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Node> t(n);
    for (int i = 0; i < n; i++)
    {
        t[i].parent = -1;
        t[i].left = -1;
        t[i].right = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        scanf("%d %d", &t[id].left, &t[id].right);
    }

    printf("Preorder\n");
    preorder(0, t);
    printf("\n");

    printf("Inorder\n");
    inorder(0, t);
    printf("\n");

    printf("Postorder\n");
    postorder(0, t);
    printf("\n");

    return 0;
}
