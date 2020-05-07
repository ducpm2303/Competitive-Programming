/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,s;
vector < int > a;
void Input(){
    cin >> n >> s; a.resize(n+1);
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
}
void Solve(){
    vector < int > f(s+1,0); 
    f[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = s ; j >= a[i] ; j--){
            if( !f[j] && f[j-a[i]] ) f[j] = 1;
        }
    }
    cout << ((f[s] == 1)?"YES":"NO") << '\n';
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
