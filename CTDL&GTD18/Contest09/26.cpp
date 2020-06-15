/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int par[1005], ranK[1005];
int n,m;
int Find(int u) {
    if (par[u] != u) par[u] = Find(par[u]);
    return par[u];
}

void Join(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (ranK[u] == ranK[v]) ranK[u]++;
    if (ranK[u] < ranK[v]) par[u] = v;
    else par[v] = u;
}
void Input(){
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        ranK[i] = 0;
    }
}
void Solve(){
    cin >> n >> m;
    bool cycle = false;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        if(Find(u) == Find(v)) cycle = true;
        Join(u,v);
    }
    cout << ((cycle == true)?"YES":"NO") << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
