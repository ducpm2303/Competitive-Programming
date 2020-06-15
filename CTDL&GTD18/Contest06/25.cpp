#include<iostream>
#include<algorithm>
using namespace std;
/*
    sap xep.
*/
const int maxN = 1e7+5;
int a[maxN];
int n;
void input(){
    cin >> n;
    for ( int i = 0 ; i < n ; i++)
        cin >> a[i];
}
 
void solve(){
    sort(a,a+n);
    int tmp = a[0];
    for ( int i = 1 ; i < n ; i ++){
        if ( a[i] != tmp){
            cout << tmp << ' ' << a[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main(){
    int t;
	cin >> t;
	while(t--){
        input() ; 
        solve();
    }
	return 0;
}