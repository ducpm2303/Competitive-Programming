/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[1001][1001];
void Input(){
    cin >> n >> m;
    memset(a,0,sizeof(a));
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
}
void Solve(){
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1) cout << j << ' ';
        }
        cout << '\n';
    }
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
