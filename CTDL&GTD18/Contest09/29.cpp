/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005][1005];
int n,m , dle = 0;
void Input(){
    cin >> n >> m;
    dle = 0;
    memset(a,0,sizeof(a));
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
}
bool degU(int u){
    int cnt1 = 0 , cnt2 = 0;
    for(int i = 1 ; i <= n ; i++){
        cnt1 += a[u][i];
    }
    if(cnt1 % 2 == 1){
        dle ++;
        return false;
    } else return true;
}
void Solve(){
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(degU(i) == false){
            flag = 1;
        }
    }
    if(flag == 0) cout << 2 << '\n';
    else cout << ((dle == 2)?1:0) << '\n';
    
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

