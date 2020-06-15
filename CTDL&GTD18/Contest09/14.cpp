/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e3 + 5;
int cha[N], rankk[N];
void init() {
    for (int i=0; i<N; i++) {
        cha[i] = i;
        rankk[i] = 0;
    }
}
int Find(int u){
    if (cha[u] != u) cha[u] = Find(cha[u]);
    return cha[u];
}
void join(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (rankk[u] == rankk[v]) rankk[u]++;
    if (rankk[u] < rankk[v]) cha[u] = v;
    else cha[v] = u;
}
int n,m,q;
void Input(){
    init();
}
void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        join(u,v);
    }
    cin >> q;
    for(int i = 1;i <= q; i++){
        int u,v; cin >> u >> v;
        cout << ((Find(u) == Find(v))?"YES":"NO") << '\n';
    }
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
