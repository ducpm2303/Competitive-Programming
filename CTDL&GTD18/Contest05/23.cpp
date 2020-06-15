/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Nmax = 2002;
int n,a[Nmax],dp[Nmax],res = 0;
void Input(){
    cin >> n ;
    res = 0;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
}
void Solve(){
    for(int i = 0; i < n ; i++){
        dp[i] = 1;
        for(int j = 0 ; j < i ; j++){
            if(a[j] <= a[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    res = *max_element(dp,dp + n);
    cout << n - res << '\n';
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
