/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> res;
int n;
void Try(ll i){
    if( i >= 1e16 ) return;
    res.push_back(i);
    Try(i*10);
    Try(i*10+9);
}
void Input(){
    cin >> n;
}
void Solve(){
    for(int i = 0; i < res.size(); i++){
        if(res[i] % n == 0){
             cout << res[i] << '\n';
             return;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    Try(9); sort(res.begin(),res.end());
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
