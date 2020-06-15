/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int n,sum;
ll dp[101][50001];
void Input(){
    cin >> n >> sum;
}
void Solve(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= sum ; j++){
            int x = 0, end = j-1;
				if (i == 1) { 
					x = 1;
					end = j;    
				}
				for (; x <= end && x <= 9; x++) 
					dp[i][j] += dp[i-1][j-x] , dp[i][j] %= mod;
		}
    }
    cout << dp[n][sum] << '\n';
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
