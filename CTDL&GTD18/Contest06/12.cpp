#include<iostream>
#include<algorithm>
using namespace std;
/*
    sap xep .
*/
const int maxN = 1e7+5;
int a[maxN];
int n,k;
void input(){
	cin >> n >> k ;
    for ( int i = 0 ; i < n ; i ++)
        cin >> a[i];
}
void solve(){
	sort(a,a+n);
    int id = n - 1;
    while(k != 0){
        cout << a[id] << ' ';
        id--;
        k--;
    }
    cout << endl;
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