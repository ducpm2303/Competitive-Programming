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
#define maxn 500005


string s;
int n, gap;
int sa[maxn], pos[maxn], tmp[maxn], lcp[maxn], sum[maxn], R[maxn];
vector<int> V[maxn*2];

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
            lcp[sa[pos[i]]] = k; ///***///
            if (k) --k;
        }
    /// normal : the i th suffix in lexicographically order
    /// lcp[i] = lcp[suffix start at i]
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("10.in","r",stdin);
    freopen("10.out","w",stdout);
    #endif

    cin >> n; n++;
    cin >> s;
    s += '%';
    buildSA();
    buildLCP();
//    FO(i,0,n) cout << sa[i] << endl; cout << endl;
//    FO(i,0,n) cout << lcp[i] << endl;

    memset(sum, 0, sizeof(sum));
    n--;
    FOR(i,1,n) sum[i] = sum[i-1] + (s[i-1] == '(' ? 1 : -1);
    stack<int> S;
    FOR(i,0,n){
        V[sum[i]+MOD].pb(i);
        while(!S.empty() && sum[S.top()] > sum[i]){
            R[S.top()] = i; S.pop();
        }
        S.push(i);
    }
    while(!S.empty()) {
        R[S.top()] = n+1;
        S.pop();
    }

    //FOR(i,1,n) cout << i << " " << sum[i] << "\n"; cout << endl;
    //FOR(i,1,n) cout << lcp[i] << endl;
    LL ans = 0;
    FOR(i,1,n){
        /// each substring start at i
        /// ans += query(i, N) - query(i. i + lcp[suffix at i] - 1)
        int high = R[i-1]-1;
        int low = i + lcp[i-1] - 1;
        int x = sum[i-1] + MOD;

        if(low >= high) continue;
        ans += upper_bound(V[x].begin(), V[x].end(), high) -
            upper_bound(V[x].begin(), V[x].end(), low);
        //cout << i << " " << sum[i-1] << "  " << low << " " << high << " : " << ans << endl;
    }
    cout << ans << endl;


    return 0;
}


