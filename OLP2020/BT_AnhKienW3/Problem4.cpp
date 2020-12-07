/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll m,n;
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
matrix fastPow(matrix a, ll b){
    if(b == 1) return a;
    matrix tmp = fastPow(a, b/2);
    tmp = mulMatrix(tmp,tmp);
    if(b%2 == 1)
        return mulMatrix(tmp,a);
    else 
        return tmp;
}
 
ll fastPowInt(ll a, ll b){
	if(b == 1) return a;
	ll tmp = fastPowInt(a,b/2);
	tmp = tmp*tmp%mod;
	if(b%2 == 1)
		return tmp*a%mod;
	else
		return tmp;
}
ll Ckn(ll n, ll k){
	ll res = 1;
	for(int i = 1; i <= k; i++,n--){
		res = res*n%mod;
		res = res*fastPowInt(i,mod-2)%mod;
	}
	return res;
}
void Input(){
    cin >> m >> n;
    for(int i = 0; i < n + 2; i++){
        for(int j = 0; j < n + 2; j++){
            A.p[i][j] = 0;
        }
    }
    A.p[0][0] = 1;
    for(int i = 1; i < n + 2; i++) A.p[0][i] = Ckn(n,i-1);
    for(int i = 1; i < n + 2; i++){
    	for(int j = 1; j <= i; j++){
    		A.p[i][j] = Ckn(i-1,j-1);
		}
	}
//	for(int i = 0; i < n + 2; i++){
//		for(int j = 0; j < n + 2; j++){
//			cout << A.p[i][j] << ' ';
//		}
//	}
	n += 2;
}
 
void Solve(){
	if(m == 1){
		cout << 1 << '\n';
		return;
	}
   	matrix res = fastPow(A,m-1);
   	ll sum = 0;
    for(int i = 0; i < n; i++){
    	sum += res.p[0][i];
    	sum %= mod;
	}
	cout << sum << '\n';
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