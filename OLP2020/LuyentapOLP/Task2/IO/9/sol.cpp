#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<int,int>II;

const long double PI = 2*acos(0.0);
const long double eps = 1e-6;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 200005

int n, m, ST, EN, Q;
int w[maxn], gg[maxn], p[maxn], x[maxn], R[maxn];
int nex[maxn], xet[maxn], depth[maxn], ancestor[20][maxn], cost[maxn], f[maxn][20];
LL sum[maxn], dp[maxn];
vector<int> adj[maxn];

void init_rmq(){
    FOR (i,1,n) f[i][0] = p[i];
    for (int j = 1; (1<<j) <= n; j++)
    for (int i=1; i+(1<<j)-1 <= n; i++)
        f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
}

int get_minp(int i,int j){
    if(i>j) return 0;
    int k = log2(j-i+1); /// 31 - __builtin_clz(j-i+1)
    return min(f[i][k], f[j-(1<<k)+1][k]);
}

void dfs(int u, int p) {
    for (int i = 0; i < int(adj[u].size()); ++i) {
        int v = adj[u][i];
        if (v != p) {
            if(u == n)
                cost[v] = get_minp(v+1,n-1);
            else cost[v] = get_minp(v+1,u);
            dfs(v, u);
        }
    }
}

int findZ(int x, int val){
    /// first z such that cost[z] < cost[x]
    if(x == n-1) return n;
    FORD(i,19,0){
        if(get_minp(x+1, ancestor[i][x]) >= val){
            x = ancestor[i][x];
        }
    }
    return x;
}

int find_EN(int x, int y){
    FORD(i,19,0){
        if(ancestor[i][x] <= y) {
            x = ancestor[i][x];
        }
    }
    return x;
}

void Init(){
    FOR(i,1,n-1) w[i] -= gg[i];
    sum[0] = 0;
    FOR(i,1,n) sum[i] = sum[i-1] + w[i];
    p[n] = 0;
    init_rmq();

    /// right of sum - sum[i] < sum[R[i]]
    stack<int> S;
    sum[n] = -Linfi;
    S.push(n);
    FORD(i,n-1,0){
        while(!S.empty() && sum[S.top()] <= sum[i]) S.pop();
        if(!S.empty()) R[i] = S.top();
        else R[i] = n;
        S.push(i);
        adj[R[i]].pb(i);
        ancestor[0][i] = R[i];
    }

    //FOR(i,0,n-1) cout << sum[i] << " "; cout << endl;
    //FOR(i,0,n-1) cout << R[i] << " "; cout << endl;
    //FOR(i,1,n) cout << p[i] << " "; cout << endl;

    /// build graph
    memset(cost,0,sizeof(cost));

    dfs(n,0);
    ancestor[0][n] = n; cost[n] = 0;
    for (int j = 1; j <= 19; ++j){
        ancestor[j][n] = n;
        FOR(i,0,n-1)
            ancestor[j][i] = ancestor[j - 1][ancestor[j - 1][i]];
    }
    ///

    memset(dp,0,sizeof(dp));
    FORD(i,n-1,0){
        int z = findZ(i, cost[i]);
        dp[i] = dp[z] + (sum[z] - sum[i]) * cost[i];
        //cout << dp[i] << endl;
        //cout << i << " " << z << " " << dp[i] << endl;
    }
}



void solve(){
    while(m--){
        cin >> ST >> EN;
        int X = ST-1, Y = EN-1, Z;
        Y = find_EN(X, Y);
        if(X == Y) { cout << "0\n"; continue; }
        int min1 = get_minp(X+1,Y);
        Z = findZ(X, min1);
        LL ans = dp[X] - dp[Z] - 1LL*(sum[Z]-sum[Y])*min1;
        //cout << X << " " << Y << " " << Z << endl;
        //cout << dp[X] << " " << dp[Z] << endl;
        cout << ans << endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif

    cin >> n >> m;
    FOR(i,1,n-1) cin >> w[i];
    FOR(i,1,n) cin >> gg[i] >> p[i];

    Init();
    solve();

    return 0;
}
