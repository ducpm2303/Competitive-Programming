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

typedef pair<double,int>II;
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = 1e18;
const int MOD = 500000;
const int c1 = 31;
const int c2 = 37;
#define maxn 100005

struct node{
    int cnt, L, R;
    node(){
        cnt = 0; L = R = -1;
    }
    node(int _cnt, int _L, int _R){
        cnt = _cnt; L = _L; R = _R;
    }
};

int n, m, u, v, k, idx = 0, cnt;
int a[maxn], pos[maxn], nA[maxn], root[maxn];
int depth[maxn], ancestor[20][maxn];
node tree[maxn*20]; /// n log n memory
vector<int> V, adj[maxn];


int build(int low, int high){
    ++idx;
    int i = idx;
    if(low == high) return i;
    int mid = (low+high)/2;
    tree[i].L = build(low, mid);
    tree[i].R = build(mid+1, high);
    return i;
}

int update(int low, int high, int root, int val){
    //cout << low << " " << high << " " << root << endl;
    if(high < val || low > val) return root; /// stop update
    ++idx;
    int i = idx;
    if(low == val && high == val){
        tree[i] = node(tree[root].cnt+1, -1, -1);
        return i;
    }
    int mid = (low+high)/2;
    int newL = update(low, mid, tree[root].L, val);
    int newR = update(mid+1, high, tree[root].R, val);
    tree[i] = node(tree[root].cnt+1, newL, newR);
    return i;
}

int query(int low, int high, int root1, int root2, int root3, int root4, int k){
    while(low < high){
        //cout << low << " " << high << " : " << tree[root2].cnt - tree[root1].cnt << endl;
        int left_sub_tree = tree[tree[root1].L].cnt + tree[tree[root2].L].cnt;
        left_sub_tree -= tree[tree[root3].L].cnt + tree[tree[root4].L].cnt;
        int mid = (low+high)/2;
        if(left_sub_tree >= k){
            /// go left
            high = mid;
            root1 = tree[root1].L;
            root2 = tree[root2].L;
            root3 = tree[root3].L;
            root4 = tree[root4].L;
        }
        else{
            low = mid+1;
            k -= left_sub_tree;
            root1 = tree[root1].R;
            root2 = tree[root2].R;
            root3 = tree[root3].R;
            root4 = tree[root4].R;
        }
    }
    return low;
}

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    ancestor[0][u] = p;
    root[u] = update(1, cnt, root[p], pos[u]);
    for (int i = 0; i < int(adj[u].size()); ++i) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u);
        }
    }
}

int jump(int u, int d) {
    for (int i = 19; i >= 0; --i)
        if ((d >> i) & 1)
            u = ancestor[i][u];
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    u = jump(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int i = 19; i >= 0; --i)
        if (ancestor[i][u] != ancestor[i][v]) {
            u = ancestor[i][u];
            v = ancestor[i][v];
        }
    return ancestor[0][u];
}


int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> n >> m;
    FOR(i,1,n) { cin >> a[i]; V.pb(a[i]); }
    FOR(i,1,n-1){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    FOR(i,1,n) {
        pos[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
        nA[pos[i]] = a[i];
    }
    cnt = V.size();
    //FOR(i,1,n) cout << pos[i] << " "; cout << endl;
    root[0] = build(1, cnt);
    dfs(1, 0);
    for (int j = 1; 1 << j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            ancestor[j][i] = ancestor[j - 1][ancestor[j - 1][i]];


    while(m--){
        cin >> u >> v >> k;
        int LCA = lca(u, v);
        int ans;
        ans = query(1, cnt, root[u], root[v], root[LCA], root[ancestor[0][LCA]], k);
        //else ans = query(1, cnt, root[u], root[v], root[LCA], root[0], k);
        cout << nA[ans] << "\n";
    }

    //cout << idx << endl;

    return 0;
}


