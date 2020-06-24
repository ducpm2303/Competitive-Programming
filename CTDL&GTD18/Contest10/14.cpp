//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
typedef pair <i64,i64> pii;
const i64 N = LLONG_MAX;
i64 n,m,s;
vector <pii> ke[1005]; 
i64 d[1005];
void input(){
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        ke[i].clear();
        d[i] = N;
    }
    for(int i = 1; i <= m; i++){
        i64 u,v,l;
        cin >> u >> v >> l;
        ke[u].push_back({v,l});
        ke[v].push_back({u,l});
    }
}
void dijkstra(i64 s){                      // xuat phat tu dinh s
	priority_queue < pii ,vector <pii> , greater<pii > > q;
	q.push({s,0});
	i64 u,v,du,uv;
	d[s] = 0; 
	while(!q.empty()){
		u = q.top().first; // dinh u
		du = q.top().second;
		q.pop();
		if(du != d[u]) continue;
		for(auto x : ke[u]){ // duyet dinh ke cua u
			v = x.first ;
			uv = x.second;
			if (d[v] > d[u] + uv){
				d[v] = d[u] + uv;       
				q.push({v,d[v]});
			}
		}
	}
}
void solve(){
    dijkstra(s);
    for(int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
    cout << '\n';
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();int t=1; 
    cin>>t; cin.ignore();
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD
  