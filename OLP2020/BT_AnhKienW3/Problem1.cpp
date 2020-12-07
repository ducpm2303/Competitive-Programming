/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct matrix{
    ll p[2][2];
};
matrix mulMatrix(matrix a,matrix b){
    matrix res;
    for(int i = 0; i <= 1; i++){
        for(int j = 0; j <= 1; j++){
            res.p[i][j] = 0;
            for(int k = 0; k <= 1; k++){
                res.p[i][j] += (a.p[i][k]*b.p[k][j])%mod;
                res.p[i][j] %= mod;
            }
        }
    }
    return res;
}
matrix fastPow(matrix a, ll b){
    if(b == 1) return a;
    matrix tmp = fastPow(a, b/2);
    tmp = mulMatrix(tmp,tmp);
    if(b%2 == 1)
        return mulMatrix(tmp,a);
    else 
        return tmp;
}
ll n;
void Input(){
    cin >> n;
}

void Solve(){
    if(n == 0){
        cout << 0 << '\n';
        return;
    }
    if(n == 1 || n == 2){
        cout << 1 << '\n';
        return;
    }
    matrix A;
    A.p[0][0] = 0;
    A.p[0][1] = A.p[1][0] = A.p[1][1] = 1;
    matrix res = fastPow(A,n-1);
    cout << (res.p[0][0] + res.p[0][1]) % mod << '\n';
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
