/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;
ll a,b;
vector<int> minPrime(maxn,0);
vector<int> Prime;
void sieve(){
    for (int i = 2; i * i <= maxn; i++) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= maxn; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= maxn; i++) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
            Prime.push_back(i);
        }
    }
}
void Input(){
    cin >> a >> b;
}

void Solve(){
    vector<ll> fac(b + 1, 0);
    for(int i = a; i <= b; i++){
        int n = i;
        while (n != 1){
            fac[minPrime[n]]++;
            n /= minPrime[n];
        }
    }
    ll res = 1;
    for(int i = 0; i < Prime.size() && Prime[i] <= b; i++)
        res = (res * (2*fac[Prime[i]] + 1)) % mod;
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    sieve ();
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
