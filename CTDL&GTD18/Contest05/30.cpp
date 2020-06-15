/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector < vector<int> > dp(101,vector<int>(10001,0));
void Sieve(){
    for(int i = 1; i <= 10000 ; i++) dp[1][i] = i;
    for(int i = 1; i <= 100 ; i++) dp[i][1] = 1;
    for(int i = 2 ; i <= 100 ; i++){
        for(int j = 2 ; j <= 10000 ; j++){
            if(j >= i*i) dp[i][j] = min(dp[i-1][j],dp[i][j-i*i]+1);
            else dp[i][j] = dp[i-1][j];
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }
}
void Input(){
    cin >> n;
}
void Solve(){
    cout << dp[100][n] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    Sieve();
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
