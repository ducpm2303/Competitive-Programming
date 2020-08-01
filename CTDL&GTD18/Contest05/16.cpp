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
    int res =0;
    vector<int> dp(n,0);
    for(int i = 0 ; i < n ; i++){
        int tmp = 0;
        for(int j = i - 1 ; j >= 0 ; j--){
            if(a[i] > a[j]){
                tmp = max(tmp,dp[j]);
            }
        }
        dp[i] = tmp + a[i];
        res = max(res,dp[i]);
    }
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
