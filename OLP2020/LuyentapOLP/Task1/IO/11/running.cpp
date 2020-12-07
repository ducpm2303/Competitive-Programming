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
#include <iomanip>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOD(i,a,b) for(int i=a;i>b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define x first
#define y second
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
const int c1 = 11;
const int c2 = 13;
#define maxn 100005

int n, Q;
II P[maxn];
LL bit[maxn+5], it[maxn*4];
int d[maxn], b[maxn], pos[maxn];

void build_it(int i, int l, int r){
	if(l == r){
		it[i] = b[l]; pos[l] = i; return;
	}
	int m = (l+r)>>1;
	build_it(i<<1, l, m);
	build_it(i<<1|1, m+1, r);
	it[i] = max(it[i<<1], it[i<<1|1]);
}

int get_max(int i, int u, int v, int l, int r){
	if(l > v || r < u) return -infi;
	if(l >= u && r <= v) return it[i];
	int mid = (l+r)>>1;
	return max( get_max(i*2,u,v,l,mid), get_max(i*2+1,u,v,mid+1,r) );
}

void updateIT(int u){
	int i = pos[u];
	it[i] = b[u];
	i >>= 1;
	while(i){
		it[i] = max(it[i<<1], it[i<<1|1]);
		i >>= 1;
	}
}


void update(int x, int val){
    x++;
    while(x <= maxn){
        bit[x] += val;
        x += (x&(-x));
    }
}

LL get(int x){
    x++;
    LL ans = 0;
    while(x){
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}

int dist(II A, II B){
    return abs(A.x-B.x) + abs(A.y-B.y);
}

void Init(){
    FOR(i,1,n-1) d[i] = dist(P[i], P[i+1]);
    FOR(i,1,n-1) update(i,d[i]);
    FOR(i,2,n-1) b[i] = d[i-1] + d[i] - dist(P[i-1], P[i+1]);
    build_it(1,1,n);

    P[0] = P[n+1] = P[n+2] = II(0,0);
}

void solve(){
    char c;
    int i, j, u, v;
    while(Q--){
        cin >> c;
        if(c == 'Q'){
            cin >> i >> j;
            LL sum = get(j-1) - get(i-1);
            LL maxx = 0;
            if(i + 2 <= j) maxx = get_max(1,i+1,j-1,1,n);
            //cout << sum << " " << maxx << endl;
            cout << sum - maxx << endl;
        }
        else if(c == 'U'){
            cin >> i >> u >> v;

            /// remove element
            update(i-1, -d[i-1]);
            update(i, -d[i]);
            b[i-1] = b[i] = b[i+1] = 0;
            updateIT(i-1); updateIT(i); updateIT(i+1);
            /// insert element
            P[i] = II(u,v);
            d[i-1] = dist(P[i-1], P[i]);
            d[i] = dist(P[i], P[i+1]);
            update(i-1, d[i-1]);
            update(i, d[i]);

            if(i >= 3){
                b[i-1] = d[i-2] + d[i-1] - dist(P[i-2], P[i]);
                updateIT(i-1);
            }
            if(i >= 2 && i <= n-1){
                b[i] = d[i-1] + d[i] - dist(P[i-1], P[i+1]);
                updateIT(i);
            }
            if(i <= n-2){
                b[i+1] = d[i] + d[i+1] - dist(P[i], P[i+2]);
                updateIT(i+1);
            }
        }
    }
    //cout << b[3] << endl;
    //cout << get_max(1,3,3,1,n) << endl;
    //FOR(i,1,n-1) cout << b[i] << " "; cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    freopen("running.inp", "r", stdin);
    freopen("running.out", "w", stdout);

    cin >> n >> Q;
    FOR(i,1,n){
        cin >> P[i].x >> P[i].y;
    }
    Init();
    solve();




    return 0;
}

