/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    ll u,v,w;
};
bool negativeCycle = false;
vector<edge> E;
ll dist[1005];
int n,m,s;
void Input(){
    cin >> n >> m >> s;
    E.resize(m+5);
    negativeCycle = false;
    for(int i = 1; i <= m; i++){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
}
void bellmanFord(int s){
    for(int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    dist[s] = 0;
    for (int i = 1; i <= n - 1; i++) { 
        for (int j = 1; j <= m; j++) { 
            int u = E[j].u;
            int v = E[j].v;
            ll weight = E[j].w; 
            if (dist[u] != LLONG_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    }
    for (int i = 1; i <= m; i++) { 
        int u = E[i].u;
        int v = E[i].v;
        int weight = E[i].w; 
        if (dist[u] != LLONG_MAX && dist[u] + weight < dist[v]){
            negativeCycle = true;
            return;
        }
            
    } 
}
void Solve(){
    bellmanFord(s);
    if(negativeCycle == true) cout << -1 << '\n';
    else{
        for(int i = 1; i <= n; i++){
            if(dist[i] != LLONG_MAX)
            cout << dist[i] << ' ';
            else cout << "INFI" << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
