#include <bits/stdc++.h>

using namespace std;

#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define orta (bas + son >> 1)
#define sag (k + k + 1)
#define sol (k + k)

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define endl '\n'

typedef pair < int ,int > pii;

typedef long long ll;

const long long linf = 1e18+5;
int mod = (int) 1e9 + 7;
const int logN = 17;
const int inf = 1e9 + 9;
const int N = 2e5 + 5;

int S[N], x, y, LOG[N], rmq[logN + 1][N], lca[logN + 1][N], n, m, L[N], G[N], P[N], root[N];
ll depth[N], dp[N], pre[N], need[N];
int t;

int get_min(int x, int y) {
    t = LOG[y - x + 1];
    return min(rmq[t][x], rmq[t][y - (1 << t) + 1]);
}

int get_up(int x, int y) {
    ROF(i, logN, 0)
        if(get_min(x, lca[i][x] - 1) >= y){

            x = lca[i][x];
        }

    return x;
}

int relax(int x, int y) {
    ROF(i, logN, 0){
        cout << i << " " << x << " " << lca[i][x] << endl;

        if(lca[i][x] <= y){

            x = lca[i][x];
        }
    }
    return x;
}

int main() {
    freopen("test.in", "r", stdin);
    FOR(i, 1, N - 1) LOG[i] = log2(i);

    scanf("%d %d", &n, &m);

    FOR(i, 1, n - 1) {
        scanf("%d", &L[i]);
    }

    FOR(i, 1, n) {
        scanf("%d %d", &G[i], &P[i]);
        rmq[0][i] = P[i];
    }

    FOR(i, 1, n - 1)
        pre[i] = G[i] - L[i] + pre[i - 1];

    pre[n] = linf;

    int s = 0;
    ROF(i, n - 1, 0) {
        while(s && pre[S[s]] >= pre[i]) --s;
        if(s) { root[i + 1] = S[s] + 1; need[i + 1] = pre[i] - pre[S[s]]; }
        else { root[i + 1] = n + 1; }
        depth[i + 1] = depth[root[i + 1]] + need[i + 1];
        lca[0][i + 1] = root[i + 1];
        S[++s] = i;
    }

    lca[0][n + 1] = n + 1;

    FOR(i, 1, logN) {
        lca[i][n + 1] = n + 1;
        FOR(j, 1, n) {
            lca[i][j] = lca[i - 1][lca[i - 1][j]];
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][min(n, j + (1 << i - 1))]);
        }
    }
    int u = 2238, v = 8072;
    cout << relax(u, v) << endl;

//    ROF(i, n, 1) {
//        int up = get_up(i, get_min(i, lca[0][i] - 1));
//        dp[i] = dp[up] + (depth[i] - depth[up]) * get_min(i, up - 1);
//    }

//    FOR(i, 1, m) {
//        scanf("%d %d", &x, &y); y = relax(x, y);
//        if(x == y) { printf("0\n"); continue; }
//        ll cur = dp[x], cm = get_min(x, y - 1);
//        int t = get_up(x, cm);
//        cur -= dp[t] + (depth[y] - depth[t]) * cm;
//        printf("%lld\n", cur);
//    }
}
