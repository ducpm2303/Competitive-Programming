#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<double,double>point;
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

const long double PI = 2*acos(0.0);
const long double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = 1e18;

const int c1 = 31;
const int c2 = 37;
#define maxn 100005


string s, t, cmd;
int n, cnt = 1;
set<int> A[maxn], B[maxn];
set<int> ::iterator it;
map<string, int> M;

string toString(int a){
    string ans = "";
    if(a == 0) return ans;
    while(a){
        ans = char(a%10+48) + ans;
        a /= 10;
    }
    return ans;
}

int toNum(string s){
    int ans = 0;
    FO(i,0,s.size()) ans = ans*10 + s[i]-48;
    return ans;
}

void add(string t, string &ans){
    int val = 0;
    if(M[t] == 0) {
        M[t] = ++cnt;
        A[cnt].insert(0);
    }
    else{
        int id = M[t];
        if(B[id].size() == 0){
            it = A[id].end(); it--;
            val = *it+1;
            A[id].insert(val);
        }
        else{
            it = B[id].begin();
            val = *it;
            A[id].insert(val);
            B[id].erase(it);
        }
    }
    if(val == 0) ans = t;
    else ans = t + "(" + toString(val) + ")";
}

void del(string t){
    if(t[t.size()-1] == ')'){
        int pos = 0;
        FO(i,0,t.size()) if(t[i] == '(') { pos = i; break; }
        string a = t.substr(0, pos), b = "";
        FO(i,pos+1,t.size()-1) b += t[i];
        int num = toNum(b);
        int id = M[a];
        A[id].erase(num);
        B[id].insert(num);
        //cout << a << " " << id << " " << num << endl;
    }
    else{
        int id = M[t];
        A[id].erase(0);
        B[id].insert(0);
    }
}

void solve(){
    FOR(step,1,n){
        cin >> cmd;;
        if(cmd == "crt"){
            cin >> t;
            string ans = "";
            add(t, ans);
            cout << "+ " << ans << endl;
        }
        else if(cmd == "del"){
            cin >> t;
            del(t);
            cout << "- " << t << endl;
        }
        else{
            cin >> s >> t;
            string ans = "";
            del(s);
            add(t, ans);
            cout << "r " << s << " -> " << ans << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    #endif
    cin >> n;
    solve();


    return 0;
}