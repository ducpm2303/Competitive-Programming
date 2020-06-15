/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int n;
ll dp[1001][1001];
void Input(){
    cin >> n >> a ;
}
void Solve(){
    a = ' ' + a; 
    ll res = 0;
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(a[i] == a[j] && i != j) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout << dp[n][n] << '\n';
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
