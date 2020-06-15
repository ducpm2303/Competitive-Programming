/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int n,k;
vector<int> a;
void Input(){
    cin >> n >> k ; a.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
}
void Solve(){
    vector < ll > dp(k+1,0);
    dp[0] = 1;
    for(int i = 1 ; i <= k ; i++){
        for(int j = 0 ; j < n ; j++)
            if( i >= a[j]) dp[i] = (dp[i] + dp[i-a[j]])%mod;
    }
    cout << dp[k] << '\n';
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
