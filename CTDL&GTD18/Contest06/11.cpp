#include<iostream>
#include<algorithm>
using namespace std;
/*
    sap xep + tham lam 
*/
const int maxN = 1e3+5;
int a[maxN];
int n;

void input(){
	cin >> n ;
    for ( int i = 0 ; i < n ; i ++)
        cin >> a[i];
}
/*
    -3 
    5
*/
void solve(){
    long long res = 1e18;
    long long ans ;
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            long long tmp = a[i] + a[j];
            long long tmp1 = tmp;
            if(tmp1 < 0) tmp1 *= -1;
            if(tmp1 < res){
                res = tmp1;
                ans = tmp;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
	int t = 1;
	cin >> t; 
	while(t--){
        input() ; 
        solve();
    }
	return 0;
}
