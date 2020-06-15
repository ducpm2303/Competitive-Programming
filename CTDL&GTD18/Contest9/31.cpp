/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1001];
int vis[1001];
int n,m,cnt;
void DFS(int u){
    vis[u] = 1;
    cnt++;
    for(auto v : ke[u]){
        if(!vis[v]){
            DFS(v);
        }
    }
}
void Input(){
    cin >> n;
    cnt = 0;
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
        ke[i].clear();
    }
    for(int i = 1 ; i <= n - 1; i++){
        int u,v ; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}
void Solve(){
    DFS(1);
    cout << ((cnt == n)?"YES":"NO") << "\n";
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
