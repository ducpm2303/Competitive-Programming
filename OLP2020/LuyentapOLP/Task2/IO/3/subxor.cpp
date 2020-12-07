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

const long double PI = 2*acos(0.0);
const long double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 500005

int n;
int a[maxn];

struct trie{
    int value;     /// stored at leaves
    trie *arr[2];  /// 0 left   1 right
};

trie *newNode(){
    trie *tmp = new trie;
    tmp->value = 0;
    tmp->arr[0] = tmp->arr[1] = NULL;
    return tmp;
}

void insertNode(trie *root, int pre_xor){
    trie *tmp = root;
    FORD(i,31,0){
        int val = getbit(pre_xor, i);
        if(tmp->arr[val] == NULL)
            tmp->arr[val] = newNode();
        tmp = tmp->arr[val];
    }
    tmp->value = pre_xor;
}

int query(trie *root, int pre_xor){
    trie *tmp = root;
    FORD(i,31,0){
        int val = getbit(pre_xor, i);
        if(tmp->arr[1-val] != NULL)
            tmp = tmp->arr[1-val];
        else if(tmp->arr[val] != NULL)
            tmp = tmp->arr[val];
    }
    return pre_xor^(tmp->value);
}

void solve(){
    trie *root = newNode();
    insertNode(root, 0);

    int ans = 0, pre_xor = 0;
    FOR(i,1,n){
        pre_xor ^= a[i];
        insertNode(root, pre_xor);
        ans = max(ans, query(root, pre_xor));
    }

    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("subxor.inp","r",stdin);
    freopen("subxor.out","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    solve();

    return 0;
}
