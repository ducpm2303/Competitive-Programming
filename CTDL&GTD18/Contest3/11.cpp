/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 0; 
int n;
const ll mod = 1e9+7;
vll a;
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}   
void Solve(){
    priority_queue < ll , vector<ll> , greater<ll> > q;
    for(int i = 0 ; i < n ; i++) q.push(a[i]);
    ll res = 0;
    while(q.size() > 1){
        ll x = q.top() ; q.pop();
        ll y = q.top() ; q.pop();
        q.push((x+y)%mod);
        res = (res + (x+y)%mod)%mod;
    }
    cout << res << '\n';
}
int main(){
    setIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 