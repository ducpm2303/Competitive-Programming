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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
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
const LL MOD = 1000000007;
#define maxn 100005


int n, q, u, v, c;
vector<II> adj[maxn];
int parent[maxn]; /// parent of node i
int h[maxn];      /// height of node i
int f[maxn][17];  /// f[u][k]: cha thu 2^k cua dinh u
                  /// f[u][0]: cha truc tiep cua u
                  /// f[u][k] = f[v][k-1] voi v = f[u][k-1]
int d_min[maxn][17], d_max[maxn][17];

void BFS(int st){
    queue<int> Q;
    h[st] = 1;
    Q.push(st);
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        FO(i,0,adj[u].size()){
            v = adj[u][i].se;
            if(h[v] == 0){
                parent[v] = u;
                h[v] = h[u]+1;
                d_min[v][0] = adj[u][i].fi;
                d_max[v][0] = adj[u][i].fi;
                Q.push(v);
            }
        }
    }
}

void preLCA(){
    FOR(i,1,n) f[i][0] = parent[i];
    int m = log2(n);
    FOR(k,1,m){
        FOR(i,1,n){
            v = f[i][k-1];
            if(v != -1){ /// not ancestor
                f[i][k] = f[v][k-1];
                d_min[i][k] = min(d_min[i][k-1], d_min[v][k-1]);
                d_max[i][k] = max(d_max[i][k-1], d_max[v][k-1]);
            }
        }
    }
}

int LCA(int u, int v, int &minn, int &maxx){
    minn = infi; maxx = -infi;
    if(h[u]<h[v]) swap(u,v);
    int m = log2(h[u]);
    FORD(i,m,0){
        int tmp = f[u][i]; //cout << tmp << endl;
        if(h[u]-(1<<i) >= h[v]){ /// h[tmp] >= h[v]
            minn = min(minn, d_min[u][i]);
            maxx = max(maxx, d_max[u][i]);
            //cout << u << " " << i << endl;
            u = f[u][i];
        }
    }

    if(u == v) return u;
    FORD(i,m,0){
        int u1 = f[u][i];
        int v1 = f[v][i];
        if(u1 != -1 && u1 != v1){
            minn = min(minn, d_min[u][i]);
            minn = min(minn, d_min[v][i]);
            maxx = max(maxx, d_max[u][i]);
            maxx = max(maxx, d_max[v][i]);
            u = u1; v = v1;
        }
    }
    minn = min(minn, d_min[u][0]);
    minn = min(minn, d_min[v][0]);
    maxx = max(maxx, d_max[u][0]);
    maxx = max(maxx, d_max[v][0]);

    return f[u][0];
}

void solve(){
    BFS(1);//   FOR(i,1,n) cout << h[i] << " "; cout << endl;
    preLCA();
    cin >> q;
    FOR(i,1,q){
        scanf("%d %d", &u, &v);
        int minn, maxx;
        int x = LCA(u,v,minn,maxx); //cout << x << endl;
        printf("%d %d\n", minn, maxx);
    }
}

int main(){
    //ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n) {
        h[i] = 0;
        parent[i] = -1;
        FOR(j,0,16){
            f[i][j] = -1;
            d_min[i][j] = -1;
            d_max[i][j] = -1;
        }
    }
    FOR(i,1,n-1){
        scanf("%d %d %d", &u, &v, &c);

        adj[u].pb(mp(c,v));
        adj[v].pb(mp(c,u));
    }

    solve();


    return 0;
}
