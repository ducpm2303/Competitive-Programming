/*author : mcost*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int cost[105][105];
int trace[105][105];
int vis[105];
map<int,vector<int>> ke;
int n,m,k, sum = 0;
vector<int> a;

void shortPath(){
    for(int i = 1; i <= n; i++){
        priority_queue<pii, vector<pii>, greater<pii> > q;
        q.push({0,i});
        while(!q.empty()){
            int u = q.top().second;
            int du = q.top().first;
            q.pop();
            if(du != cost[i][u]) continue;
            for(auto x : ke[u]){
                int v = x.second;
                int dv = x.first;
                if(cost[i][v] > cost[i][u] + dv){
                    cost[i][v] = cost[i][u] + dv;
                    q.push({cost[i][v],v});
                }
            }
        }
    }
}


void Input(){
    cin >> n >> k >> m;
    a.resize(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j =  1; j <= n; j++){
            if(i == j){cost[i][j] = 0; trace[i][j] = i;}
            else cost[i][j] = 1e9, trace[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        ke[u].push_back(v);
        ke[v].push_back(u);
        cost[u][v] = cost[v][u] = w;
        trace[u][v] = v;
        trace[v][u] = u;
    }
}   

void Solve(){
    Floy();
    int res = 1e9; 
    for(int i = 0; i < k; i++){

    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt","r",stdin);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}