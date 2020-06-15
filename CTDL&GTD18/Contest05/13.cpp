/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector < ll > res;
int n;
void Input(){
    cin >> n;
}
void Sieve(){
    for(int i = 0 ; i <= 60 ; i++){
        for(int j = 0 ; j <= 38 ; j++){
            for(int h = 0 ; h <= 25 ; h++){
                ll tmp = 1LL*pow(2,i)*pow(3,j)*pow(5,h);
                if(1 <= tmp && tmp<= LLONG_MAX) res.push_back(tmp);
            }
        }
    }
    sort(res.begin(),res.end());
}
void Solve(){

    cout << res[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    Sieve(); 
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
