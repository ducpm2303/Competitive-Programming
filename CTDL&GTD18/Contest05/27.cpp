/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,s;
vector<int> a,b;
void Input(){
    cin >> n >> s; 
    a.resize(n+1) , b.resize(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= n ; i++) cin >> b[i];
}
void Solve(){
    vector < vector<int> > dp(n+1,vector<int>(s+1,0));
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= s ; j++){
            if( i == 0 || j == 0) dp[i][j] = 0;
            else if( j < a[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],b[i] + dp[i-1][j-a[i]]);
        }
    }
    cout << dp[n][s] << '\n';
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
