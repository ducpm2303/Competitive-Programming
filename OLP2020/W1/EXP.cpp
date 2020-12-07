/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[5005];

int calc(int m){
    int res = m;
    for(int i = 2; i <= sqrt(m); i++){
        if(m%i == 0)
            res = min(res,f[i] + f[m/i] + 2);
    }
    return res;
}
void preProcess(){
    for(int i = 1; i <= 5000; i++){
        f[i] = calc(i); 
    }
    for(int i = 1; i <= 5000; i++){
        for(int j = 1; j < i; j ++){
            f[i] = min(f[i],f[i-j] + f[j] + 2);
        }
    }
}
void Input(){
    
}

void Solve(){
    //freopen("exp.inp","r",stdin);
    preProcess();
    int n;
    while(cin >> n){
        //cout << n << "->" << f[n] << '\n';
        cout << f[n] << '\n';
    }
    
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
