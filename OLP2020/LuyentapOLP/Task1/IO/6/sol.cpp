#include <bits/stdc++.h>
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
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }

const long double PI = 2*acos(0.0);
const long double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = (LL) 1e18;
const LL MOD = 1000000007;
#define maxn 200005

int n, m, u, v, c;
int it[maxn*4], lazy[maxn*4], a[maxn];

void add(int &a, int b){
    a += b;
}

void down(int i, int l, int r){ /// if(l != r)
    int mid = (l+r)/2, c1 = i*2, c2 = i*2+1;
    add(lazy[c1], lazy[i]);
    add(lazy[c2], lazy[i]);
    add(it[c1], lazy[i]);
    add(it[c2], lazy[i]);
    lazy[i] = 0;
}

void update(int i, int l, int r, int u, int v, int x){
    /// update(1, 1, n, u, v, x)
    if(l > v || r < u) return;
    if(u <= l && r <= v){
        add(it[i], x);
        add(lazy[i], x);
        return;
    }
    int mid = (l+r)/2, c1 = i*2, c2 = i*2+1;
    down(i, l, r);
    update(c1, l, mid, u, v, x);
    update(c2, mid+1, r, u, v, x);
    it[i] = max(it[c1], it[c2]);
}
int query(int i, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return it[i];
    int mid = (l + r)/2;
    down(i, l, r);
    return max(query(i*2, l, mid, u, v), query(i*2+1, mid+1, r, u, v));
}

void solve(){
    int q;
    cin >> q;
    while(q--){
        cin >> u >> v;
        cout << query(1, 1, n, u, v) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    cin >> n >> m;
    FOR(i,1,m) {
        cin >> u >> v >> c;
        update(1, 1, n, u, v, c);
    }

    solve();

    return 0;
}
