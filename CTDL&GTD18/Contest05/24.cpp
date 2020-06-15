/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100][100]; 
int n,m;
void Input(){
    cin >> n >> m;
}
void Solve(){
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= n + 1; i++){
        for(int j = 1 ; j <= m + 1 ; j++){
            if( i == 1 || j == 1) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << dp[n+1][m+1] << '\n';
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
