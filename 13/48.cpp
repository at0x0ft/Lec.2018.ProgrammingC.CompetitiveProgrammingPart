#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
  private:
    vector<int> _parent;

  public:
    UnionFind(const int n) : _parent(n)
    {
        for (int i = 0; i < n; i++)
        {
            _parent[i] = i;
        }
    }

    int root(const int v)
    {
        if (_parent[v] != v)
            _parent[v] = root(_parent[v]);
        return _parent[v];
    }

    void unite(const int v1, const int v2)
    {
        int r1 = root(v1);
        int r2 = root(v2);
        if (r1 == r2)
            return;
        _parent[r2] = r1;
    }

    bool same(const int v1, const int v2)
    {
        return root(v1) == root(v2);
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    UnionFind uf(n);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        uf.unite(v1, v2);
    }

    int v1, v2;
    scanf("%d %d", &v1, &v2);
    printf("%s\n", uf.same(v1, v2) ? "true" : "false");
}
