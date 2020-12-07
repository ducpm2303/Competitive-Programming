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
const double eps = 1e-6;
const int infi = 1e9;
const LL Linfi = (LL) 1e15;
const LL MOD = 1000000007;
const int c1 = 11;
const int c2 = 37;
#define maxn 100005

struct query{
	int i, j, k, id;
	inline friend bool operator < (query A, query B){
		if(A.k != B.k) return A.k < B.k;
		return A.id < B.id;
	}
};

struct ele{
	int val, pos;
	inline friend bool operator < (ele A, ele B){
		return A.val < B.val;
	}
};

int n, m;
ele a[maxn];
query Q[200005];
int bit[maxn+5], ans[200005];

void update(int x){
	while(x <= maxn){
		bit[x]++;
		x += (x&(-x));
	}
}

int get(int x){
	int ans = 0;
	if(x == 0) return 0;
	while(x){
		ans += bit[x];
		x -= (x&(-x));
	}
	return ans;
}

int cal(int x){ /// get(x): number of element <= a[x]
	return x - get(x);
}

void solve(){
	sort(a+1, a+n+1);
	sort(Q+1, Q+m+1);
	int i = 1;
	FOR(iq,1,m){
		while(i <= n && a[i].val <= Q[iq].k){
			update(a[i].pos);
			i++;
		}
		ans[Q[iq].id] = cal(Q[iq].j) - cal(Q[iq].i-1);
	}
	FOR(iq,1,m) printf("%d\n", ans[iq]);
}

int main(){
    //ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
	cin >> n;
	FOR(i,1,n){
		//cin >> a[i].val;
		scanf("%d", &a[i].val);
		a[i].pos = i;
	}
	cin >> m;
	FOR(i,1,m){
		//cin >> Q[i].i >> Q[i].j >> Q[i].k;
		scanf("%d %d %d", &Q[i].i, &Q[i].j, &Q[i].k);
		Q[i].id = i;
	}
	solve();


    return 0;
}
