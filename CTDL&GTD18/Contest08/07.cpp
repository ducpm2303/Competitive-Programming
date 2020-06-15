/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> res;
ll n;
ll maxX = pow(2,64);
void Try(ll i){
    res.push_back(i);
    if(i < maxX/10){
        Try(i*10);
        Try(i*10+1);
    }
}
void Input(){
    cin >> n;
}
void Solve(){
    //for(int i = 0 ; i < 10 ; i++) cout << res[i] << ' ';
    int pos = upper_bound(res.begin(),res.end(),n) - res.begin();
    cout << pos << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    Try(1); sort(res.begin(),res.end());
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
