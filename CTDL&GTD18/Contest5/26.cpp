/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,n;
vector<int> a;
void Input(){
    cin >> s >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}
void Solve(){
    vector<int> dp(s+1,0);
    dp[0] = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = s ; j >= a[i] ; j--){
            dp[j] = dp[j] | dp[j-a[i]];
        }
    }
    for(int i = s ; i >= 0 ; i--){
        if(dp[i] == 1){
            cout << i << '\n';
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
