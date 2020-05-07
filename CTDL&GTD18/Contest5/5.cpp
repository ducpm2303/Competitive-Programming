/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,k;
ll power(ll a , ll b){
    if( b == 1) return a%mod;
    ll tmp = power(a,b/2);
    tmp = tmp*tmp%mod;
    if (b % 2 == 1) return tmp*a%mod;
    return tmp%mod;
}
ll C(int n , int k){
    ll res = 1;
    for(int i = 1;  i <= k ; n-- , i++){
        res = res*n%mod*power(i,mod-2)%mod;
    }
    return res;
}
void Input(){
    cin >> n >> k;
}
void Solve(){
    cout << C(n,k) << '\n';
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
