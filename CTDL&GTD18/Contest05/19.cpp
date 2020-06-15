/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,z;
ll dp[1000];
void Input(){
    cin >> n >> x >> y >> z;
}
void Solve(){
    if(n == 1){
        cout << x << '\n';
    }else{
        memset(dp,0,sizeof(dp));
        dp[1] = x; 
        for(int i = 2 ; i <= n ; i++){
            if (i % 2 == 0) 
                dp[i] = min(dp[i-1] + x, dp[i/2] + z); 
            else 
                dp[i] = min(dp[i-1] + x, dp[(i+1)/2] + y + z);
            //cout << dp[i] << ' ';  
        }
        cout << dp[n] << '\n';
    }
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
