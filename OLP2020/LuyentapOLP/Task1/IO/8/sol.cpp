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
#define maxn 100005


int a[maxn],f[maxn][21],n, k;

void init_rmq(){
    FOR (i,1,n) f[i][0]=a[i];
    for (int j=1; (1<<j) <= n; j++)
        for (int i=1; i+(1<<j)-1<=n; i++)
            f[i][j] = gcd (f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int get_rmq(int i,int j){
    int k = log2(j-i+1); /// 31 - __builtin_clz(j-i+1)
    return gcd(f[i][k],f[j-(1<<k)+1][k]);
}

int findlen(int st){
    int low = st, high = n, mid, ans = st;
    if(a[st]%k != 0) return infi;
    if(a[st] == k) return 1;
    while(low <= high){
        //cout << mid << " " << get_rmq(st, mid) << endl;
        mid = (low+high)/2;
        if(get_rmq(st, mid) <= k){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;

        }
    }

    if(get_rmq(st, ans) == k) {
        //if(ans-st+1 == 2) cout << st << " " << ans << endl;
        return ans-st+1;
    }
    else return infi;
}

void solve(){
    init_rmq();
    int ans = infi;
    FOR(i,1,n){
        ans = min(ans, findlen(i));
    }
    if(ans == infi) ans = -1;
    cout << ans << endl;
    //findlen(1);
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    while(sotest--){
        cin >> n >> k;
        FOR(i,1,n) cin >> a[i];
        solve();
    }


    return 0;
}
