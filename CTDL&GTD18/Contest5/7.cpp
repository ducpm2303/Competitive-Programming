/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod =1e9+7;
int n,k;
void Input(){
    cin >> n >> k;
}
void Solve(){
    vector<ll> dp(n+1,0);
    dp[0] = 1; 
    for(int i = 1 ; i <= n ; i++){
        for(int j = i - 1 ; j >= max(i-k,0) ; j-- ){
            dp[i] = (dp[i] + dp[j])%mod;
        }
    }
    cout << dp[n] << '\n';
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
