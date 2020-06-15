/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a;
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}
void Solve(){

    vector<ll> dp(n+1,0);
    dp[0] = a[0] , dp[1] = a[1] , dp[2] = a[0] + a[2];
    for(int i = 3 ; i < n ; i++) dp[i] = max(dp[i-2],dp[i-3]) + a[i];
    ll res = 0;
    for(int i = 0 ; i < n ; i++) res = max(res,dp[i]);
    cout << res << '\n';
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
