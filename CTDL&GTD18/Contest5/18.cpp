/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int,int>> a;
bool cmp(pair<int,int> x , pair<int,int> y){
    return (x.first < y.first);
}
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i].first >> a[i].second;
}
void Solve(){
    int res =0;
    vector<int> dp(n,0);
    sort(a.begin(),a.end(),cmp);
    for(int i = 0 ; i < n ; i++){
        int tmp = 0;
        for(int j = i - 1 ; j >= 0 ; j--)
            if( a[i].first > a[j].second) dp[i] = max(dp[i],dp[j]);
        dp[i] += 1;
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
