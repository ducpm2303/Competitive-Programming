/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[501][501] , dp[501][501];
int n,m;
void Input(){
    cin >> n >> m ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j ++){
            cin >> a[i][j];
            if(i == 0 || j == 0) dp[i][j] = a[i][j];
        }
    }
}
void Solve(){
    int res = 0;
    for(int i = 1 ; i < n ; i++){
        for(int j = 1; j < m ; j++){
            if(a[i][j] == 1)
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            else dp[i][j] = 0;
            res = max(res,dp[i][j]);
        }
    }
    cout << res << '\n' ;
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
