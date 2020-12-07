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
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 1000005


string s;
int n, gap;
int sa[maxn], pos[maxn], tmp[maxn], lcp[maxn];

bool sufCmp(int i, int j){
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < n && j < n) ? pos[i] < pos[j] : i > j;
}

void buildSA(){
    FO(i,0,n) sa[i] = i, pos[i] = s[i];
    for (gap = 1;; gap *= 2) {
        sort(sa, sa + n, sufCmp);
        FO(i, 0, n-1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        FO(i, 0, n) pos[sa[i]] = tmp[i];
        if (tmp[n - 1] == n - 1) break;
    }
}

void buildLCP(){
    for (int i = 0, k = 0; i < n; ++i)
        if (pos[i] != n - 1) {
            for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
            ++k;
            lcp[pos[i]] = k;
            if (k) --k;
        }
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("5.in","r",stdin);
    freopen("5.out","w",stdout);
    #endif
    cin >> s;
    s += '@'; n = s.size();
    buildSA();
    buildLCP();
//    FO(i,0,n) cout << sa[i] << endl; cout << endl;
//    FO(i,0,n) cout << lcp[i] << endl;
    LL ans = 0;
    FO(i,0,n) ans += (n - 1 - sa[i]) - lcp[i];
    cout << ans << endl;
}


