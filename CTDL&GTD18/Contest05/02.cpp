/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n ;
vector <int> a;
void Input(){
    cin >> n ; a.resize(n+1);
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
}
void Solve(){
    int res = 1;
    vector<int> f(n+1,0);
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j < i ; j++){
            if(a[i] > a[j]) f[i] = max(f[i],f[j]);
        }
        f[i]++;
        res = max(res,f[i]);
    }
    cout << res << '\n';
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
