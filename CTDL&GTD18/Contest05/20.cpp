/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll strtoNum(string a){
    ll s = 0;
    for(int i = 0 ; i < a.length() ; i++){
        s = s*10 + (a[i]-'0');
    }
    return s;
}
void Input(){
    cin >> s;
}
void Solve(){
    int n = s.length();
    ll res = 0;
    for(int len = 1 ; len <= n ; len++){
        for(int i = 0 ; i <= n - len ; i++){
            string a = s.substr(i,len);
            res += strtoNum(a);
        }
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
