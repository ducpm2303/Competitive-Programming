/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a;
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}
/*
0 1 2 3 4 5  6   7
5 3 7 2 9 10 100 20
gọi dp[i] là dãy con có tổng lớn nhất 
mà các phần tử ko đứng cạnh nhau (bao gồm a[i])
từ vị trí 1 đến vị trí i.
dp[0] = 5 , dp[1] = 3 , dp[2] = 7 + 5 = 12.
dp[3] = max(dp[0],dp[1]) + a[3]
dp[4] = max(dp[1],dp[2]) + a[4]
*/
void Solve(){

    vector<ll> dp(n+1,0);
    dp[0] = a[0] , dp[1] = a[1] , dp[2] = a[0] + a[2];
    for(int i = 3 ; i < n ; i++) 
        dp[i] = max(dp[i-2],dp[i-3]) + a[i];
    ll res = 0;
    for(int i = 0 ; i < n ; i++) res = max(res,dp[i]);
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
