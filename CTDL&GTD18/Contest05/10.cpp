/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1501][1501] , dp[1501][1501];
int n,m;
void Input(){
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j ++){
            cin >> a[i][j];
        }
    }
}
void Solve(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){

            if(i == 1 && j == 1) dp[i][j] = a[i][j];
            else if(i == 1){
                dp[i][j] = dp[i][j-1] + a[i][j];
            }else if(j == 1){
                dp[i][j] = dp[i-1][j] + a[i][j];
            }
            else
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + a[i][j];
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
