/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adj[1005];
int n,m, vis[1005];
bool cycle;
void Input(){
    cin >> n >> m;
    cycle = false;
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }
}
void DFS(int u, int s){
    if(cycle == true) return;
    vis[u] = 1;
    for(auto v : adj[u]){
        if(v == s){
            cycle = true;
            return;
        }
        if(vis[v] == 0) DFS(v,s);
    }
}
void Solve(){
    int i = 1;
    while(cycle == false && i <= n){
        memset(vis,0,sizeof(vis));
        DFS(i,i);
        i++;
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
