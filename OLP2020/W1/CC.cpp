/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
vector<long double> a;
void Input(){
    cin >> n >> k;
    a.resize(n);
    for(auto &x : a) cin >> x;
}

void Solve(){
    long double res = DBL_MAX;
    //cout << res << '\n';
    for(int i = 0; i < n; i++){
        long double cost = 0;
        for(int j = 0; j < n; j++){
            long double x = abs(a[j] - a[i]);
            long double y = x;
            for(int m = 2; m <= k; m++) x *= y;
            cost += x;
            
        }
        //cout << cost << '\n';
        res = min(res,cost);
    }
    
    cout << fixed << setprecision(2) << res << '\n';
    //printf("%.2lf",res);
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
