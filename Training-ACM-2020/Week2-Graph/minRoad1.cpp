//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
typedef pair <int,int> pii;
const int N = 1e9+1;
int n,m,x;
vector < pii > ke[101];
vector < int > d(101) , trace(101) , res(101);
vector < bool > vis(101);
 
void input(){
	cin >> n >> m >> x;
	while(m--){
		int u,v,c;
		cin >> u >> v >> c;
		ke[u].push_back({v,c}) ; ke[v].push_back({u,c});
	}
}
void reset(){
	res[0] = 0;
	for(int i = 1 ; i <= n ; i++){
		d[i] = N;
		trace[i] = -1;
		vis[i] = false;
	}
}
void dijkstra(int s){                      // xuat phat tu dinh s
	priority_queue < pii ,vector < pii > , greater<pii > > q;
	q.push({s,0});
	int u,v,du,uv;
	d[s] = 0; trace[s] = -1;
	while(!q.empty()){
		u = q.top().first; // dinh u
		du = q.top().second;
		q.pop();
		if (du != d[u]) continue;
		for(auto x : ke[u]){ // duyet dinh ke cua u
			v = x.first ;
			uv = x.second;
			if (d[v] > d[u] + uv){
				d[v] = d[u] + uv;
				trace[v] = u;
				q.push({v,d[v]});
			}
 
		}
	}
}
 
void solve(){
	while(x--){
		int type,st,en;
		cin >> type >> st >> en;
		reset();
		dijkstra(st);
		if ( type == 0) cout << d[en] << endl;
		else{
			int id = 0;
			while(en != -1){
				res[++id] = en;
				en = trace[en];
			}
			cout << id << ' ' ;
			for(int i = id ; i > 0 ; i--)
				cout << res[i] << ' ';
			cout << endl;
			res.clear();
		}
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	faster();int t=1; 
	//cin>>t; cin.ignore();
	while(t--){ input();solve();}
	cerr << "\nRunning is : " << 1.0*clock()/1000 ;
	return 0;
}
//Code By PMD