#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
/*
	sang nguyen to.
*/
const int  N = 1e6 + 5 ;
int n;
int isPrime[N];
void sieve(){
	for(int i = 0 ; i <= N ; i++) isPrime[i] = 0; // khoi tao cac phan tu ban dau bang 0
	isPrime[0] = isPrime[1] = 1;
	for ( int i = 2 ; i <= sqrt(N) ; i++){
		if ( isPrime[i] == 0){
			for(int j = i * i ; j <= N ; j +=i)
				isPrime[j] =1;
		}
	}
	// so nguyen to la cac so duoc danh dau bang 0.
}
void input(){
	cin >> n;
}
 
void solve(){
	int flag = 0;
	for( int i = 2 ; i <= n/2 ; i++){
        //cout <<  i << ' ' << n - i << endl;
		if ( isPrime[i] == 0 && isPrime[n-i] == 0 ){
			cout << i << ' ' << n - i << endl;
			flag = 1;
			break;
		}
	}
	if(!flag)
    cout << -1 << endl;
	//cout << endl;
}
int main(){
	int t = 1;
	sieve(); // sang nguyen to
	cin >> t; 
	while(t--){
        input() ; 
        solve();
    }
	return 0;
}