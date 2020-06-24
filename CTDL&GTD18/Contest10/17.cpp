/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][105];
int n,m,q;
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= 101 ; i++){
        for(int j = 1; j <= 101 ; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = 1e9;
        }
    }
    for(int i = 1;i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = w;
    }
}
void Solve(){
    for(int i = 1 ; i <= n; i++){
        for(int j = 1;  j <= n ; j++){
            for(int k = 1 ; k <= n ; k++){
                dp[j][k] = min(dp[j][k],dp[j][i] + dp[i][k]);
            }
        }
    }
    cin >> q;
    while(q--){
        int a,b; cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
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
