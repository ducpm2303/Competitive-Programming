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
#define maxn 200005

string s, pal;
int n, gap, old_n;
int sa[maxn], pos[maxn], tmp[maxn], lcp[maxn], id[maxn];
int f[19][maxn];  /// f[21][maxn] is better

void init_rmq(int n){
    FOR (i,1,n) f[0][i] = lcp[i];
    for (int j = 1; (1<<j) <= n; j++)
        for (int i=1; i+(1<<j)-1 <= n; i++)
            f[j][i] = min(f[j-1][i], f[j-1][i+(1<<(j-1))]);
}

int get_rmq(int i,int j){
    int k = 31 - __builtin_clz(j-i+1);
    return min(f[k][i], f[k][j-(1<<k)+1]);
}

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

void solve(){
    buildSA();
    buildLCP();
    FO(i,0,n) id[sa[i]] = i;
    //FO(i,0,n) cout << i << " : " << sa[i] << " " << lcp[i] << endl; cout << endl;
    //FO(i,0,n) cout << lcp[i] << endl;
    init_rmq(n);

    int longest_length = 0;
    /// odd length
    FO(i,1,old_n){
        int x = id[i], y = id[2*old_n-i];
        if(x > y) swap(x, y);
        int v = get_rmq(x, y-1);
//        cout << i << " " << 2*old_n-i << "  " << v << endl;
//        cout << x << " " << y << endl << endl;
        if(2*v-1 > longest_length) longest_length = 2*v-1;
            //pal = s.substr(i-v+1, 2*v-1);
    }
    /// even length
    FO(i,1,old_n){
        int x = id[i], y = id[2*old_n+1-i];
        if(x > y) swap(x, y);
        int v = get_rmq(x, y-1);
        //cout << i << " " << 2*old_n+1-i << "  " << v << endl;
        if(2*v > longest_length) longest_length = 2*v;
            //pal = s.substr(i-v, 2*v);
    }
    cout << longest_length << endl;

}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    //freopen("test.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    while(sotest--){
        cin >> s;
        old_n = s.size();
        string t = s; s += '@';
        FORD(i,t.size()-1,0) s += t[i];
        n = s.size();
        solve();

    }



    return 0;
}
