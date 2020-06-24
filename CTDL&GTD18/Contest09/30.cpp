/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005][1005];
int n,m;
void Input(){
    cin >> n >> m;
    memset(a,0,sizeof(a));
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        a[u][v] = 1;
    }
}
bool degU(int u){
    int cnt1 = 0 , cnt2 = 0;
    for(int i = 1 ; i <= n ; i++){
        cnt2 += a[i][u];
        cnt1 += a[u][i];
    }
    return (cnt1 == cnt2);
}
void Solve(){
    for(int i = 1; i <= n; i++){
        if(degU(i) == false){
            cout << 0 << '\n';
            return;
        }
    }
    cout << 1 << '\n';
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

