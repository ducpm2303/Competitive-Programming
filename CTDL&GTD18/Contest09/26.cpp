/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int cha[N], Rank[N];
map <pair<int,int>,int > cnt;
bool flag = 0;
void Init() {
    for (int i=0; i<N; i++) {
        cha[i] = i;
        Rank[i] = 0;
    }
}

int Find(int u) {
    if (cha[u] != u) cha[u] = Find(cha[u]);
    return cha[u];
}
void join(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (Rank[u] == Rank[v]) Rank[u]++;
    if (Rank[u] < Rank[v]) cha[u] = v;
    else cha[v] = u;
}
int n,m;
void Input(){
    cin >> n >> m;
    Init();
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        if(Find(u) == Find(v)){
            //cout << u << ' ' << v << '\n';
            flag = 1;
        }else join(u,v);
    }
}
void Solve(){
  
    cout << ((flag == 1)?"YES":"NO") << '\n';
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
