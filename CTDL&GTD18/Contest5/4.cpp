/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = -1e9;
int n,k;
vector<int> a;
void Input(){
    cin >> n >> k; a.resize(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        a[i] %= k;
    }
}
void Solve(){
    vector<vector<int>> dp(n+1,vector<int>(k+1,inf));
    dp[0][0] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < k ; j++){
            dp[i][j] = max(dp[i-1][j] ,dp[i-1][(j-a[i]+k)%k]+1);
        }
    }
    cout << dp[n][0] << '\n';
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
