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
int test = 1 , MULTI_TEST = 1; 
vi a,b;
int n,m;
void Input(){
    cin >> n >> m;
    a.resize(n) ; b.resize(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
}   
void Solve(){
    map < int , ll > res;
    for(int i = 0 ; i < n ; i++){
        for(int  j = 0 ; j < m ; j++){
            res[i+j] += 1ll*a[i]*b[j];
        }
    }
    for(auto z : res) cout << z.second << ' ';
    cout << '\n';
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

 