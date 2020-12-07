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
const long double eps = 1e-12;
const int infi = 1e9;
const LL Linfi = (LL) 9e18;
const LL MOD = 1000000007;
#define maxn 100005

int n, ans;
string s[maxn];

struct node {
	bool is_end;
	int maxWord;
	node* child[26];
} *root;

void init() { //init root
	root = new node();
	root->is_end=0;
	root->maxWord=0;
}

void insert(string s) {//insert word
	node* current = root;
	int ok = 0;
	FO (i,0,s.size()) {
		if (current->child[s[i]-'a'] == NULL){
            current->child[s[i]-'a'] = new node();
            if(ok == 0) ans++;
            ok = 1;
		}
		//current->maxWord = max(current->maxWord
		current = current->child[s[i]-'a'];
               //di nhanh s[i]

        if(ok == 0) ans++;
	}
    current->is_end=1;
}


void solve(){
    ans = 0;
    init();
    FOR(i,1,n) insert(s[i]);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    FOR(test, 1, sotest){
        cin >> n;
        FOR(i,1,n) cin >> s[i];
        //cout << "Case #" << test << ": ";
        solve();
    }

    return 0;
}
