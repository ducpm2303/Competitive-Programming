#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 123456;

int depth[N], ancestor[20][N], sub[N];
vector<int> adj[N];

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    sub[u] = 1;
    ancestor[0][u] = p;
    for (int i = 0; i < int(adj[u].size()); ++i) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u);
            sub[u] = sub[u] + sub[v];
        }
    }
}

int jump(int u, int d) {
    for (int i = 19; i >= 0; --i)
        if ((d >> i) & 1)
            u = ancestor[i][u];
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    u = jump(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int i = 19; i >= 0; --i)
        if (ancestor[i][u] != ancestor[i][v]) {
            u = ancestor[i][u];
            v = ancestor[i][v];
        }
    return ancestor[0][u];
}

int main() {
    //freopen("3.in", "r", stdin);
    //freopen("3.out","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int j = 1; 1 << j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            ancestor[j][i] = ancestor[j - 1][ancestor[j - 1][i]];
    int m;
    scanf("%d", &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);

        int t = lca(u, v);
        printf("%d\n", t);


    }
}

