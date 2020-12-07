/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e15 + 7;
struct matrix{
   ll p[5][5];
};
ll n = 3,m;
matrix I,A;
ll mulInt(ll a, ll b){
    if(b == 0) return 0LL;
    if(b == 1) return a;
    ll tmp = mulInt(a,b/2);
    tmp = (tmp+tmp)%mod;
    if(b % 2 == 1)
        return (tmp + a)%mod;
    else
        return tmp;
}
matrix mulMatrix(matrix a,matrix b){
    matrix res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res.p[i][j] = 0;
            for(int k = 0; k < n; k++){
                res.p[i][j] += mulInt(a.p[i][k],b.p[k][j]);
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
 
void init(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            A.p[i][j] = 0;
            I.p[i][j] = (i == j);
        }
    }
    A.p[0][0] = A.p[0][1] = A.p[0][2] = 1;
    A.p[1][0] = A.p[2][1] = 1;
}
void Input(){
    init();
    cin >> m;
}
 
void Solve(){
    if(m <= 3){
        if(m == 0) cout << 3 << '\n'; // test de sai
        if(m == 1) cout << 1 << '\n'; 
        if(m == 2) cout << 3 << '\n';
        if(m == 3) cout << 6 << '\n';
        return;
    }
    matrix B = dfs(A,m-3);
    ll res = 6;
    res += (3*B.p[0][0])%mod; res %= mod;
    res += (2*B.p[0][1])%mod; res %= mod;
    res += (1*B.p[0][2])%mod; res %= mod;
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "r", stdin);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
 