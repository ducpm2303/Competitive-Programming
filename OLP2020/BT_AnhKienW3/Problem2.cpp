/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n,k;
struct matrix{
   ll p[100][100];
};
matrix I,A;
matrix mulMatrix(matrix a,matrix b){
    matrix res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res.p[i][j] = 0;
            for(int k = 0; k < n; k++){
                res.p[i][j] += (a.p[i][k]*b.p[k][j])%mod;
                res.p[i][j] %= mod;
            }
        }
    }
    return res;
}
matrix sumMatrix(matrix a, matrix b){
    matrix res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res.p[i][j] = 0;    
            res.p[i][j] += (a.p[i][j] + b.p[i][j])%mod;
            res.p[i][j] %= mod;
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
matrix dfs(matrix a, ll b){
    if(b == 1) return a;
    matrix tmp = dfs(a,b/2);
    matrix powa = fastPow(a,b/2);
    matrix tmp2 = sumMatrix(I,powa);
    tmp = mulMatrix(tmp,tmp2);
    if(b%2 == 1){
        powa = mulMatrix(powa,powa);
        return sumMatrix(tmp,mulMatrix(a,powa));
    }
    else
        return tmp;
}

void Input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A.p[i][j];
            I.p[i][j] = (i == j);
        }
    }
}

void Solve(){
    matrix res = dfs(A,k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << res.p[i][j] << ' ';
        }
        cout << '\n';
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
