/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector < int > a;
void Input(){
	cin >> n ; a.resize(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
}
void Solve(){
	stable_sort(a.begin(),a.end());
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++){
		Input();
		Solve();
	}
	return 0;
}
