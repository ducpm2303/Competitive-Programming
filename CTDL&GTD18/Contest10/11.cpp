/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct dsu{
    vector <int> par,rank;
    int n;
    dsu(int m){n = m; par.resize(n+1) ; rank.resize(n+1);};
    void in(){
        for(int i = 1 ; i <= n ; i++)
            par[i] = i , rank[i] = 0;
    }
    int find(int u){
        if(par[u] != u) par[u] = find(par[u]);
        return par[u]; 
    }
    bool join(int u , int v){
        u = find(u);
        v = find(v);
        if( u == v ) return false;
        if ( rank[u] == rank[v]) rank[u]++;
        if ( rank[u] > rank[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};
int n,m;
vector<pair<pair<int,int>,int>> edge;
void Input(){
    cin >> n >> m; edge.resize(m);
    for(int i = 0; i < m; i++){
        cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second;
    }
}
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.second == b.second){
        if(a.first.first == b.first.first) 
            return a.first.second < b.first.second;
        return a.first.first < b.first.first;
    }
    return (a.second < b.second);    
}
void Solve(){
    dsu a = dsu(n); a.in();
    sort(edge.begin(),edge.end(),cmp);
    ll minwght = 0;
    for(int i = 0; i < m; i++){
        int u = edge[i].first.first;
        int v = edge[i].first.second;
        int w = edge[i].second;
        if(a.join(u,v) == true){
            minwght += w;
        }
    }
    cout << minwght << '\n';
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
