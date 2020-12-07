#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
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

typedef pair<LL,int>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = (LL) 9e18;
const LL MOD = 1000000007;
#define maxn 100005

int n, m, x, y, z, val;
int a[maxn];
int tree[maxn*4], lazy[maxn*4];

void update_tree(int node, int u, int v, int l, int r, int value) {
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it
		if(l != r) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
   		lazy[node] = 0; // Reset it
  	}
	if(l > v || r < u) // Current segment is not within range [i, j]
		return;

  	if(l >= u && r <= v) { // Segment is fully within range
    		tree[node] += value;
		if(l != r) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
		return;
	}
	int mid = (l+r)>>1;
	update_tree(node*2, u, v, l, mid, value); // Updating left child
	update_tree(node*2+1, u, v, mid+1, r, value); // Updating right child
	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

int query_tree(int node, int u, int v, int l, int r) {
	if(r < u || l > v) return -infi; // Out of range
	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it
		if(l != r) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
		lazy[node] = 0; // Reset it
	}

	if(l >= u && r <= v) // Current segment is totally within range [i, j]
		return tree[node];
	int mid = (l+r)>>1;
	int q1 = query_tree(node*2, u, v, l, mid);
	int q2 = query_tree(node*2+1, u, v, mid+1, r);
	int res = max(q1, q2);
	return res;
}

void solve(){

}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
	cin >> n >> m;
	FOR(i,1,m){
		cin >> z;
		if(z == 1){
			cin >> x >> y >> val;
			update_tree(1,x,y,1,n,val);
		}
		else {
			cin >> x >> y;
			int ans = query_tree(1,x,y,1,n);
			cout << ans << endl;
		}
	}
	solve();

    return 0;
}
