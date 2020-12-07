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
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<LL,LL>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = (LL) 2e18;
const LL MOD = 1000000007;
const int c1 = 11;
const int c2 = 13;
#define maxn 100005


int n;
LL T;
II P[maxn];
int xet[maxn], parent[maxn];
LL len[maxn];
multiset<LL> S;
multiset<LL> ::iterator it;

void solve(){
    memset(parent, 0, sizeof(parent));
    memset(xet, 0, sizeof(xet));
    sort(P+1, P+n+1);
    FOR(i,1,n) len[i] = P[i].fi + P[i].se*T;

    int dem = n;
    FORD(i,n,1){
        int p;
        it = upper_bound(S.begin(), S.end(), len[i]);
        if(it == S.end()) {
            S.insert(len[i]);
        }
        else{
            dem--;
            S.erase(it);
            S.insert(len[i]);
        }
    }
    //FOR(i,1,n) cout << parent[i] << " "; cout << endl;
//    int ans = 0;
//    FOR(i,1,n) if(parent[i] == 0) ans++;
//    cout << ans << endl;
    cout << dem << endl;
}


int main() {
    ios::sync_with_stdio(false);
    freopen("lane.inp", "r", stdin);
    freopen("lane.out", "w", stdout);
    cin >> n >> T;
    FOR(i,1,n) cin >> P[i].fi >> P[i].se;

    solve();


    return 0;
}
/**
freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    */
