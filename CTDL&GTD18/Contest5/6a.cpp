/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Input(){
    cin >> s;
}
bool check(string a){
    int n = a.length();
    for(int i = 0 ; i < n/2 ; i++)
        if(a[i] != a[n-i-1]) return false;
    return true;
}
void Solve(){
    int n = s.length();
    for(int len = n ; len >= 1 ; len--){
        for(int i = 0 ; i <= n - len ; i++){
            string a = s.substr(i,len);
            if( check(a) == 1){
                cout << len << '\n';
                return;
            }
        }
    }
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
