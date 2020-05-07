/*author : mdp*/
/*https://codeforces.com/group/FLVn1Sc504/contest/274834/problem/K*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map < int,vector<int> > adj;
int n,m;
void Input(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }
}
void Solve(){
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
