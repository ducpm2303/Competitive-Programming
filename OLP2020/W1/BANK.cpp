/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
vector<ll> a,b;
void Input(){
    cin >> n >> q;
    a.resize(n);
    b.resize(q);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < q; i++){
        cin >> b[i];
    }
}

void Solve(){
    sort(a.begin(),a.end());
    vector<ll> dp(n+1,0);
    for(int i = 1; i <= n; i++)
        dp[i] = dp[i-1] + a[i-1];
    for(int i = 0; i < q; i++){
        int l = 0,r;
        int pos = upper_bound(dp.begin(),dp.end(),b[i]) - dp.begin();
        r = pos - 1;
        ll sum = dp[pos-1], ansmin = a[0];
        while(sum - a[l] + a[r] <= b[i] && r < n){
            sum = sum - a[l] + a[r];
            l++, r++;
            ansmin = a[l];
            //cout << sum << ' ' << ansmin << '\n';
        }
        //cout << sum << ' ' << ansmin << '\n';
        cout << pos - 1 << ' ' << ansmin << '\n';
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
