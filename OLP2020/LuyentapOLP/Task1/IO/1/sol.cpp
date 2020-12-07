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

typedef pair<int,int>II;
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

int n, m, u, v, C, D;
int f[maxn][20];
string c;
vector<II> A, B;
int res = 0;

int get_rmq(int i,int j){
    int k = log2(j-i+1); /// 31 - __builtin_clz(j-i+1)
        return max(f[i][k], f[j-(1<<k)+1][k]);
}

void process(vector<II> V, int sum){
    int n = V.size()-1;
    memset(f, 0, sizeof(f));
    FOR (i,1,n) f[i][0] = V[i].se;
    for (int j = 1; (1<<j) <= n; j++)
        for (int i=1; i+(1<<j)-1 <= n; i++)
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);


    FOR(i,1,n){
        if(V[i].fi <= sum){
            int tmp = sum-V[i].fi;
            int low = 1, high = i-1, mid, ans = -1;
            while(low <= high){
                mid = (low+high)/2;
                if(V[mid].fi + V[i].fi <= sum){
                    low = mid+1;
                    ans = mid;
                }
                else high = mid-1;
            }
            if(ans != -1)
            res = max(res, V[i].se + get_rmq(1, ans));
        }
    }
}


void solve(){
    int cntA = A.size()-1, cntB = B.size()-1;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int max1 = 0, max2 = 0;
    FOR(i,1, cntA) if(A[i].fi <= C) max1 = max(max1, A[i].se);
    FOR(i,1, cntB) if(B[i].fi <= D) max2 = max(max2, B[i].se);
    if(max1 > 0 && max2 > 0) res = max1 + max2;
    process(A, C);
    process(B, D);

    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("10.in","r",stdin);
    freopen("10.out","w",stdout);
    #endif
    A.pb(II(-1,-1)); B.pb(II(-1,-1));
    cin >> m >> C >> D;
    FOR(i,1,m){
        cin >> v >> u >> c;
        if(c == "C") A.pb(II(u,v));
        else B.pb(II(u,v));
    }


    solve();




    return 0;
}
