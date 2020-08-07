/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1005];
int vis[1005];
int n,m;
bool cycle = false;
 
void DFS(int u, int s) {
    vis[u] = 1;
    for(int i = 0 ; i <ke[u].size(); i++){
        int v = ke[u][i];
        if(v == s) cycle = true;
        if (vis[v] == 0) DFS(v,s);

    }
}
void Input(){
    cin >> n >> m;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++) ke[i].clear();
    cycle = false;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        ke[u].push_back(v);
        //ke[v].push_back(u);
    }
}
void Solve(){
    for(int i = 1; i <= n; i++)
        if(vis[i] == 0) DFS(i,i);
    
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
