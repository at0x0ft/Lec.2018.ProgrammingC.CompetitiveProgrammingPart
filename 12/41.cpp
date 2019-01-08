#include <bits/stdc++.h>

using namespace std;

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
        else
        {
            inorder(root);
            printf("\n");

            preorder(root);
            printf("\n");
        }
    }

    deleteTree();

    return 0;
}
