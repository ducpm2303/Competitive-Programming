/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long t,m;
void Input(){
    cin >> t >> m;
}

void Solve(){
    /*
        t/m 1/x;
    */
    ll gcd = __gcd(t,m);
    t = t/gcd;
    m = m/gcd;
    long long x = 2;
    while(t != 1){
        while(t*x <= m) x++;
        t = t*x - m;
        m = m*x;
        // rút gọn phân số
        ll gcd = __gcd(t,m);
        t = t/gcd;
        m = m/gcd;
        cout << 1 << '/' << x << " + ";
    }
    cout << 1 << '/' << m << '\n';
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
