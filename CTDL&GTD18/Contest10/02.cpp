/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
bool flag = false;
vector<int> a[100];
int vis[100];
void Input(){
    cin >> n >> m;
    flag = false;
    for(int i = 1; i <= 100; i++) a[i].clear();
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void DFS(int u, int cnt){
    if(cnt == n) flag = true;
    if(flag == true) return;
    
    for(auto v : a[u]){
        if(vis[v] == 0){
            vis[v] = 1;
            DFS(v,cnt+1);
            vis[v] = 0;
        }
    }
}
void Solve(){
    for(int i = 1; i <= n; i++){
        vis[i] = 1;
        DFS(i,1);
        vis[i] = 0;
    }
    cout << flag << '\n';
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
