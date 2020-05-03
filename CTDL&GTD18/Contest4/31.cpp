
#include<bits/stdc++.h>
#define Faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long i64;
typedef long double lb ;
typedef pair<i64 , i64> pt;
const int N = 1e5+5;
const i64 mod = 1e9+7;
const i64 inf = 1e18+7;
i64 n,k;
struct matrix{
    i64 pos[20][20];
};
matrix multi(matrix a , matrix b ){    
    matrix res ;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            res.pos[i][j] = 0;
            //cout << a.pos[i][j] << ' ';
            for(int h =0 ; h < n; h++)
                res.pos[i][j] =( res.pos[i][j]+a.pos[i][h]*b.pos[h][j] % mod ) % mod ;
        }
        //cout << '\n';
    }
    return res;
}
matrix powermod(matrix a , i64 b){
    if ( b == 1) return a ;
    if ( b % 2 == 0) return powermod (multi(a,a),b/2);
    return multi(a,powermod(multi(a,a),b/2));
}
void Input(){
    
}
void Solve(){
    matrix a;
    cin >> n >> k;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a.pos[i][j];
        }
    }
    matrix b = powermod(a,k);
     for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout <<  b.pos[i][j] << ' ';
        }
        cout << '\n';
    }
      
}
 
main(){
	Faster();
	int test=1;
	cin>>test;
	while(test--){
		Input();
		Solve();
		//cout<<endl;
	}
}
