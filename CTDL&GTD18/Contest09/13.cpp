/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[1005];
int par[1005];
vector<int> ke[1005];
int n,m,s,t;
void BFS(int u){
    queue<int> q;
    q.push(u); vis[u] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i = 0; i < ke[x].size(); i++){
            int v = ke[x][i];
            if(vis[v] == 0){
                par[v] = x;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
void Input(){
    memset(par,0,sizeof(par));
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++){
        ke[i].clear();
    }
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        //ke[v].push_back(u);
    }
}
void Solve(){
    BFS(s);
    if(par[t] != 0){
        int x = t;
        vector<int> res;
        while(x != s){
            res.push_back(x);
            x = par[x];
        }
        reverse(res.begin(),res.end());
        cout << s << ' ';
        for(int i = 0; i < res.size() ; i++)
            cout << res[i] << ' ';
        cout << '\n';
    } else cout << -1 << '\n';
    
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
