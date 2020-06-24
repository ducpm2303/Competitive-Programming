/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct dsu{
    vector < int > par,rank;
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
struct edge{
    int u,v,w;
};
vector<edge> a;
void Input(){
    cin >> n >> m; a.resize(m);
    for(int i = 0; i < m; i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
}
bool cmp(edge x , edge y){
    return x.w < y.w;
}

void Solve(){
    dsu b = dsu(n); b.in();
    sort(a.begin(),a.end(),cmp);
    int sum = 0;
    for(int i = 0; i < m; i++){
       if(b.join(a[i].u,a[i].v) == false){
            if(sum < 0){
                cout << 1 << '\n';
                return;
            }
       }
    }
   
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
