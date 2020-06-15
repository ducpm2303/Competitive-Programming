/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll f[1001][1001];
void Input(){
    cin >> a >> b;
}
void Solve(){
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    
    memset(f,0,sizeof(f));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << f[n][m] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t; 
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
