/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 123456789;
long long n,k;
long long power(long long a, long long b){
    if(b == 1) return a%mod;
    long long tmp = power(a,b/2);
    if(b % 2 == 1) return tmp*tmp%mod*a%mod;
    else return tmp*tmp%mod;
}
void Input(){
    cin >> n;
}

void Solve(){
    if(n == 1) cout << 1 << '\n';
    else cout << power(2,n-1) << '\n';
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
