//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
typedef pair <i64,i64> pii;
const i64 N = 1e9+1;
i64 n,m;
vector < vector < pii > > ke; 
vector < i64 > d , c;
void input(){
    cin >> n >> m;
    ke.resize(n+1);d.assign(n+1,N);c.assign(n+1,0);
    while(m--){
        i64 k,u,v,l;
        cin >> k >> u >> v >> l;
        ke[u].push_back({v,l});
        if ( k == 2 ) ke[v].push_back({u,l});
    }
}
void dijkstra(i64 s){                      // xuat phat tu dinh s
	priority_queue < pii ,vector < pii > , greater<pii > > q;
	q.push({s,0});
	i64 u,v,du,uv;
	d[s] = 0; c[s] = 1;
	while(!q.empty()){
		u = q.top().first; // dinh u
		du = q.top().second;
		q.pop();
		if(du > d[u]) continue;
		for(auto x : ke[u]){ // duyet dinh ke cua u
			v = x.first ;
			uv = x.second;
			if (d[v] > d[u] + uv){
				d[v] = d[u] + uv;
				c[v] = c[u];       // mang quy hoach dong
				q.push({v,d[v]});
			}
            else if ( d[v] == (d[u] + uv) )
                c[v] += c[u];
		}
	}
}
void solve(){
    dijkstra(1);
    cout << d[n] << ' ' << c[n];
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