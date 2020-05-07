/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101][101][101];
int n,m,h;
string a,b,c;
void Input(){
    cin >> n >> m >> h;
    cin >> a >> b >> c;
}
void Solve(){
    memset(dp,0,sizeof(dp));
    a = ' ' + a , b = ' ' + b, c = ' ' + c;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            for(int k = 1 ; k <= h ; k++){
                if( a[i] == b[j] && b[j] == c[k])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else 
                    dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
            }
        }
    }
    cout << dp[n][m][h] << '\n';
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
