/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <vector<ll>>f(101,vector<ll> (101));
vector <int> a(4);
int n,u,v,w;
void Input(){
    cin >> n;
    for(int i = 0 ; i < 4 ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            if(i == j) f[i][j] = 0;
            else f[i][j] = INT_MAX;
        }
    }
    while( cin >> u >> v >> w){
        if( u == 0) break;
        f[u][v] = f[v][u] = w;
    }
}
void Solve(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    ll res = INT_MAX;
    do{
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                  res=min(res,f[u][a[0]]+f[u][a[1]]+f[v][a[2]]+f[v][a[3]]+f[u][v]);
                  //cout << res << '\n';
            }
        }
    }while(next_permutation(a.begin(),a.end()));
    cout << res << '\n';
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
