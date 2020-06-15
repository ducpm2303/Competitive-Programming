#include<iostream>
using namespace std;
/*
*/
const int maxN = 1e7+5;
int a[maxN];
int n,x,res = -1;
void input(){
    cin >> n >> x ;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        if ( a[i] == x ) res = i ;
    }
}
void solve(){
    cout << res + 1 << endl;
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