#include<iostream>
#include<algorithm>
using namespace std;
/*
*/
const int maxN = 1e7+5;
int a[maxN];
int n,x;
void input(){
	cin >> n >> x ;
    for ( int i = 0 ; i < n ; i ++)
        cin >> a[i];
}
void solve(){
	int res = 0;
	for(int i = 0 ; i < n ; i++)
		if (a[i] == x) res++;
	if (res == 0 ) cout << -1 << endl;
	else cout << res << endl;
}
int main(){
	int t = 1;
	cin >> t; 
	while(t--){
        input(); 
        solve();
    }
	return 0;
}