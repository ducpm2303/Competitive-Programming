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
    long long res = LLONG_MAX;
    long long ans ;
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            long long tmp = a[i] + a[j];
            if(abs(tmp) < res){
                res = abs(tmp);
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
