#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200005;

set<pair<int,int>> ds[10];
int p[N], a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", p+i);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        ds[a[i]].insert({p[i],i});
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b+i);
        if (b[i] != a[i]) {
            ds[b[i]].insert({p[i],i});
        }
    }

    int m;
    scanf("%d", &m);

    while (m--) {
        int c;
        scanf("%d", &c);
        if (ds[c].empty()) printf("-1 ");
        else {
            int id = ds[c].begin()->second;
            printf("%d ", p[id]);
            ds[a[id]].erase({p[id],id});
            ds[b[id]].erase({p[id],id});
        }
    }


}
