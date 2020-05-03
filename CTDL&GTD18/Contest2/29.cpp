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
int n,m;
ll C(int n , int k){
    ll res = 1;
    for(int i = 1; i <= k ; i++ , n --){
        res = res*n/i;
    }
    return res;
}
void Input(){
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            int x ; cin >> x;
        }
    }
}   
void Solve(){
    if( n == 1 || m == 1 ) cout << 1 << '\n';
    else{
        cout << C(n+m-2,n-1) << '\n';
    }
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

 