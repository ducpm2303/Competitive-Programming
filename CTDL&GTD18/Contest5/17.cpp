/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
}
void Solve(){
    vector<int> dp(n,0) , dpr(n,0);
    for(int i = 0 ; i < n ; i++){
        int tmp = 0;
        for(int j = i - 1 ; j >= 0 ; j--){
            if( a[i] > a[j]) tmp = max(tmp,dp[j]);
        }
        dp[i] = tmp + a[i];
    }
    
    for(int i = n - 1 ; i >= 0 ; i--){
        int tmp = 0;
        for(int j = i + 1 ; j < n ; j++){
            if( a[i] > a[j]) tmp = max(tmp,dpr[j]);
        }
        dpr[i] = tmp + a[i];
    }
    int res = 0;
    for(int i = 0 ; i < n ; i++) res = max(dp[i] + dpr[i] - a[i],res);
    cout << res << '\n';
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
