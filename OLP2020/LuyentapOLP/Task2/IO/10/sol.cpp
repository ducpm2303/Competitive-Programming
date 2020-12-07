#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <ctime>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(LL i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOD(i,a,b) for(int i=a;i>b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<int,int>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = (LL) 1e18;

#define maxn 2005

int n, m, s, t;
int u, v, c;
int cost[maxn][maxn], f[maxn][maxn], trace[maxn], visited[maxn];
vector<int> adj[maxn];
LL max_flow = 0;

inline void DFS(int u, int en){
    visited[u] = 1;
    FO(i,0,adj[u].size()){
        int v = adj[u][i];
        if(visited[v] == 0 && cost[u][v] - f[u][v] > 0){
            trace[v] = u;
            visited[v] = 1;
            DFS(v, en);
        }
    }
}

inline void augment(){
    int delta = infi;
    int v = t;
    while(v != s){
        int u = trace[v];
        delta = min(delta, cost[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while(v != s){
        int u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    }
    max_flow += delta;
}

void solve() {
    /// Ford-Fulkerson Algorithm
    while(1){
        FOR(i,0,n) trace[i] = visited[i] = 0;
        DFS(s,t);
        if(visited[t] == 0) break;
        augment(); /// tim duong tang luong
    }
    cout << max_flow << endl;
}

int main(){
	ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
    freopen("2.in","r",stdin);
    //freopen("test.out","w",stdout);
    #endif
    cin >> n >> m >> s >> t;
    FOR(i,1,m){
        cin >> u >> v >> c;
        cost[u][v] = c;
        adj[u].pb(v);
        adj[v].pb(u);

    }
    solve();

    return 0;
}


