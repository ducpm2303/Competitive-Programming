/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1001][1001];
string a,b;
void Input(){
    cin >> a >> b;
}
void Solve(){
    int n = a.size(), m = b.size();
    a = ' ' + a; b = ' ' + b;
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if( i == 0 ) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i-1][j],dp[i-1][j-1])); 
        }
    }
    cout << dp[n][m] << '\n';
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
