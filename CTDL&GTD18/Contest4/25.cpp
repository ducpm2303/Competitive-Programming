//Code By PMD
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define whatis(a) cout << #a " is " << (a) << endl;
using namespace std;
 
typedef long long i64;
const int N = 100005;
const i64 mod = 1e9+7;
const i64 inf = 1e18+7;
i64 F[93];
void Fibo(){
	F[1] = 1;
	F[2] = 1;
	for(int i=3;i<=92;i++){
		F[i] = F[i-1] + F[i-2];
	}
}
char xfibo(i64 n , i64 k){
	if( n == 1) return 'A';
	if( n == 2) return 'B';
	if( k <= F[n-2]) return xfibo(n-2, k);
	return xfibo(n-1, k-F[n-2]);
}
void solve() {
	i64 n ,k ;
	cin>>n>>k;
	cout << xfibo(n,k) <<endl;
}
main(){
	IOS;
	int t=1;
	Fibo();
	cin>>t;
	while(t--){
		solve();
	}
}
//Code By PMD