//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
typedef pair < double , double > pdd;
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
    int u,v;
    double w;
};
vector < pdd > a;
vector < edge > b;
int n;
dsu DSU = dsu(0); 
double range( pdd a , pdd b){
	double x = a.first - b.first;
	double y = a.second - b.second;
	return  sqrt(x*x + y*y) ;
}
void input(){
    cin >> n; a.resize(n);
    DSU = dsu(n);DSU.in(); b.clear();
    for(auto &x : a)
        cin >> x.first >> x.second ;
}
void solve(){
    for(int i = 0 ; i < n - 1; i++){
        for(int j  = i + 1 ; j < n ; j ++){
            edge tmp;
            tmp.u = i + 1 ; tmp.v = j + 1;
            tmp.w = range(a[i],a[j]);
            b.push_back(tmp);
        }
    }
    auto cmp = [](edge a , edge b){return a.w < b.w;};
    sort(b.begin(),b.end(),cmp);
    double res = 0;
    for(auto z : b){
        if ( DSU.join(z.u,z.v) )
            res += z.w;
    }
    printf("%.6lf\n",res);
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