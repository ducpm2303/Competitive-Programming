/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c;
bool flag = false;
vector<int> adj[15];
int color[15];
bool makeColor(int u, int c){
    for(auto v : adj[u]){
        if(c == color[v]) return false;
    }
    return true;
}
void Try(int u){
    if(u == m + 1 || flag == true){
        flag = true;
        return;
    }
    for(int i = 1 ; i <= min(c,u); i++){
        if(makeColor(u,i)){
            color[u] = i;
            Try(u+1);
            color[u] = 0;
        }
    }
}
void Input(){
    cin >> n >> m >> c;
    flag = false;
    memset(color,0,sizeof(color));
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void Solve(){
    Try(1);
    cout << ((flag == true)?"YES":"NO") << '\n';
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
