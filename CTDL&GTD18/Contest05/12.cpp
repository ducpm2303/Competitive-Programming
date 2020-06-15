/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n,k;
void Input(){
    cin >> n >> k;
}
void Solve(){
    if( n < k){
        cout << 0 << '\n';
        return;
    }
    ll res = 1;
    for(int i = n - k + 1 ; i <= n ; i++)
        res = res*i%mod;
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
