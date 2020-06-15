/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 1; 
int n;
vector < int > a;
void Input(){
	cin >> n ; a.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
}   
void Solve(){
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += a[i];
	}
	if( sum % 2 == 1){
		cout << "NO" << '\n';
		return;
	}
	sum /= 2;
	vector < int > f(1e6);
	f[0] = 1;
	for(int i=0; i<n; i++){
		for(int t=sum; t>=a[i]; t--){
			if(f[t-a[i]]==1) 
				f[t]=1;
		}
	}
	if(f[sum]==1) cout << "YES";
	else cout << "NO";
	cout << '\n';

}
int main(){
	setIO();
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	if(MULTI_TEST == 1) cin >> test;
	for(int i = 1 ; i <= test ; i++){Input(); Solve();}
	return 0;
}

 