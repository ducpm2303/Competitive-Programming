/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector <vector<ii>> ke(200005);
int n,m;
void Dijkstra(int s , vector<ll> &d , vector <ll> &c){
    priority_queue< ii, vector<ii>, greater<ii> > q;
    q.push({s,0}); d[s] = 0 ; c[s] = 1; 
    while(q.empty() == false){
        int u = q.top().first;
        int du = q.top().second;
        q.pop();
        //cout << u << ' ';
        if( d[u] != du ) continue;
        for(auto x : ke[u]){ 
			int v = x.first ;
			int costuv = x.second;
			if (d[v] > d[u] + costuv){
				d[v] = d[u] + costuv;
                c[v] = c[u];
				q.push({v,d[v]});
			} else if(d[v] == d[u] + costuv){
                c[v] += c[u];
            }
		}
    }
}

void Input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        ke[u].push_back({v,w});
        ke[v].push_back({u,w});
    }
}
void Solve(){
    vector<ll> d(n+1,1e9) , c(n+1,0),d1(n+1,1e9) ,c1(n+1,0);
    Dijkstra(1,d,c); 
    Dijkstra(n,d1,c1);
    vector < int > res ;
    for(int i = 2 ; i <= n - 1 ; i++){
        if( d[i] + d1[i] > d[n] || c[i]*c1[i] < c[n])
            res.push_back(i);
    }
    cout << res.size() << '\n';
    for(auto z : res) cout << z << '\n';
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