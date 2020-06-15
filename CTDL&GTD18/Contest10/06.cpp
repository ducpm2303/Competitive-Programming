#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long i64;
vector <int> grp[100005];
bool vis[100005];
int n , m;
void input(){
	cin >> n >> m;
	for(int i = 1; i <= 100005; i++){
		grp[i].clear();
		vis[i] = false;
	}
	for ( int i = 0 ; i < m ; i++){
		int u , v;
		cin >> u >> v;
		grp[u].push_back(v);
		grp[v].push_back(u);
	}
}
void DFS(int u , int &cnt ){
	vis[u] = true; cnt++;
	for (auto v : grp[u] ){
		if ( !vis[v] )
			DFS(v,cnt);
	}
}
void solve(){
	int res = 0;
	for( int i = 1; i <= n ; i++){
		if (vis[i] == false){
			int cnt = 0;
			DFS(i,cnt);
			res = max(res,cnt);
		}
	}
	cout << res << endl; 
}
int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	faster() ; int t = 1;
	cin >> t; cin.ignore();
	while(t--){input() ; solve();}
	cerr << "Running is : " << 1.0*clock()/1000 << "seconds" << endl;
	return 0;
} 