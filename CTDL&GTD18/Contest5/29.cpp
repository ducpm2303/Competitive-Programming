/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int dp[1000];
void Input(){
    cin >> s;
}
void Solve(){
    memset(dp,0,sizeof(dp));
    if(s[0] == '0'){
        cout << 0 << '\n';
        return;
    }
    dp[0] = dp[1] =  1;
    for(int i = 2; i <= s.length(); i++){
        if(s[i - 1] != '0') dp[i] = dp[i - 1];
        if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
            dp[i] = dp[i] + dp[i - 2];
    }
    cout << dp[s.length()] << '\n';
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
