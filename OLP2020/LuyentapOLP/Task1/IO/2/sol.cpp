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
#define maxn 200005

struct data{
    int price, a, b, id;
    friend bool operator < (data A, data B){
        if(A.price != B.price) return A.price < B.price;
        if(A.price == B.price) return 0;
    }
};

int n, m;
int x[maxn];
data P[maxn];
set<data> S[4];
set<data> ::iterator it;

void solve(){
    FOR(i,1,n){
        P[i].price *= 2;
        S[P[i].a].insert(P[i]);
        if(P[i].a != P[i].b)
        S[P[i].b].insert(P[i]);
    }
    vector<int> ans;

    FOR(i,1,m){
//        FOR(j,1,3) {
//            for(auto u : S[j]) cout << u.id << " "; cout << endl;
//        }

        int c = x[i];
        if(!S[c].empty()){
            data t = *S[c].begin(); //cout << t.id << " : " << t.a <<" " << t.b<< endl << endl;
            it = S[c].begin();
            S[c].erase(it);
            ans.pb(t.price/2);

            if(t.a == c && t.b != c && !S[t.b].empty()){
                data t1 = t; t1.price--;
                it = S[t.b].upper_bound(t1);
                if((*it).price == t.price) S[t.b].erase(it);
            }
            else if(t.a != c && t.b == c && !S[t.a].empty()){ //cout << i << endl; debug;
                data t1 = t; t1.price--;
                it = S[t.a].upper_bound(t1);
                //cout << t.price << " " << (*it).price << "  :: \n";
                if((*it).price == t.price) { S[t.a].erase(it);  }
            }

        }
        else ans.pb(-1);
    }
    //cout << m << endl;
    FO(i,0,ans.size()) cout << ans[i] << " "; cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    //freopen("10.in","r",stdin);
    //freopen("10.out","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n) cin >> P[i].price;
    FOR(i,1,n) cin >> P[i].a;
    FOR(i,1,n) cin >> P[i].b;
    FOR(i,1,n) P[i].id = i;
    cin >> m;
    FOR(i,1,m) cin >> x[i];


    solve();




    return 0;
}
