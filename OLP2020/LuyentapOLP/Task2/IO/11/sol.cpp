#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<double,double>point;
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

const long double PI = 2*acos(0.0);
const long double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 100005



#define maxe 2000005
#define maxv 2005
struct Dinic {
    int n, s, t, E, adj[maxe], next[maxe], last[maxv], run[maxv], level[maxv],que[maxv];
    LL flow[maxe], cap[maxe];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t; E = 0;
        FOR(i, 0, n) last[i] = -1;
    }

    void add(int u, int v, LL c1, LL c2) {
        adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
        adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
    }

    bool bfs() {
        FOR(i, 0, n) level[i] = -1;
        level[s] = 0;

        int qsize = 0;
        que[qsize++] = s;

        FO(i, 0,qsize) {
            for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
                int v = adj[e];
                if (flow[e] < cap[e] && level[v] == -1) {
                    level[v] = level[u] + 1;
                    que[qsize++] = v;
                }
            }
        }

        return level[t] != -1;
    }

    LL dfs(int u, LL bot) {
        if (u == t) return bot;
        for (int &e = run[u]; e != -1; e = next[e]) {
            int v = adj[e];
            LL delta = 0;
            if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e] * 1ll))) > 0) {
                flow[e] += delta; flow[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }

    LL maxflow() {
        LL total = 0;
        while (bfs()) {
            FOR(i, 0, n) run[i] = last[i];
            for (int delta = dfs(s, Linfi); delta > 0; delta = dfs(s, Linfi))
        total += delta;
        }
        return total;
    }
} dinic;

int n, C, m;
int a[maxn], b[maxn], adj[1005][1005], nadj[1005][1005], out[1005];
int  st, en, u, v, c;

int modify(int mid){
    int cnt = 0;
    memset(out, 0, sizeof(out));

    FOR(i,1,n) FOR(j,1,C) if(adj[i][j]) {
        out[i] += adj[i][j];
    }
    FOR(i,1,n) FOR(j,1,C) nadj[i][j] = adj[i][j];

    FOR(u,1,n) if(out[u] > mid){
        vector<int> V;
        FOR(j,1,C) if(nadj[u][j]){
            FOR(k,1,nadj[u][j]) V.pb(j);
        }
        reverse(V.begin(), V.end());
        FOR(v,1,u-1){
            if(V.size() == 0) break;
            if(out[u] == mid) break;
            if(out[v] < mid) {
                int len = mid - out[v];
                FOR(k,1,len){
                    if(out[u] == mid) break;
                    if(V.size() == 0) break;
                    cnt++;
                    int tmp = V.back();
                    out[u]--;
                    nadj[u][tmp]--;
                    out[v]++;
                    nadj[v][tmp]++;
                    V.pop_back();
                }
            }
        }
    }
    return cnt;
}

int process(int mid, int &cnt){
    int st = 0, en = n+C+1;
    cnt = modify(mid);
    dinic.init(en+2, st, en);
    FOR(i,1,n) dinic.add(st, i, mid, 0);
    FOR(j,1,C) dinic.add(n+j, en, mid, 0);
    FOR(i,1,n) FOR(j,1,C) if(nadj[i][j]) {
        dinic.add(i, n+j, nadj[i][j], 0);
        //cout << i << " " << j << " " << nadj[i][j] << endl;
    }
    return dinic.maxflow();
    //cout << dinic.maxflow() << endl;
}

void solve(){
    int low = 0, high = 4000, mid, ans = -1;
//
    while(low <= high){
        mid = (low+high)/2;
        int tmp;
        if(process(mid, tmp) >= m){
            high = mid-1;
            ans = mid;
        }
        else low = mid+1;
    }
    int minn;
    process(ans, minn);
    cout << ans << " " << minn << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    FOR(test,1,sotest){
        memset(adj,0,sizeof(adj));
        cin >> n >> C >> m;
        FOR(i,1,m) {
            cin >> a[i] >> b[i];
            adj[a[i]][b[i]]++;
        }
//        if(test == 4){
//            cout << n << " " << C << " " << m << endl;
//            //FOR(i,1,m) cout << a[i] << " " << b[i] << endl;
//            FOR(i,1,n) FOR(j,1,C) cout << i << " " << j << " " << adj[i][j] << endl;
//        }
        //cout << "Case #" << test << ": ";
        solve();
    }



    return 0;
}
