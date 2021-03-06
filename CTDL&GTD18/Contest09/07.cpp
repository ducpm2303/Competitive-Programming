/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[1005];
vector<int> ke[1005];
int n,m,s;
void DFS(int u){
    cout << u << ' ';
    vis[u] = 1;
    for(int i = 0; i < ke[u].size(); i++){ // duyêt đỉnh kề của u.
        int v = ke[u][i];
        if(vis[v] == 0)
            DFS(v);
    }
}
void Input(){
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++){
        ke[i].clear();
    }
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        //ke[v].push_back(u);
    }
}
void Solve(){
    DFS(s);
    cout << '\n';
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
