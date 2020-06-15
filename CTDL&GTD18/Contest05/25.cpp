/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; 
vector < ll > dp(55,0);
void Input(){
    cin >> n;
}
void Solve(){
    cout << dp[n] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1] = dp[2] = dp[3] = 1 ; 
    for(int i = 2 ; i <= 50 ; i++){
        for(int j = i - 1 ; j >= max(1,i-3) ; j--)
            dp[i] += dp[j];
    }  
    int t = 1; 
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
