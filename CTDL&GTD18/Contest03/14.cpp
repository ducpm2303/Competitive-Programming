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
string s;
vector < int > x;
int n;
ll res = 0;
void Input(){
    cin >> s;
    n = s.length() , res = 0;
    x.resize(n);
}
ll BS(ll sum){
    ll l = 0 , r = 1e6 + 5 , mid , ans = 0 ;
    while( l <= r){
        mid = l+ r >> 1;
        if( mid*mid*mid > sum) r = mid - 1;
        else{
            l = mid + 1;
            ans = max(ans,mid);
        }
    }
    return ans;
}
void update(){
    ll sum = 0;
    for(int i = 0 ; i < n ; i++){
        if( x[i] == 1) sum = sum*10 + (s[i]-'0');
    }
    ll z = BS(sum);
    //cout << sum << ' ' << z  << '\n';
    if( z * z * z == sum ) res = max(res,sum);
}
void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        x[i] = j;
        if( i == n - 1) update();
        else Try(i+1);
    }
}
void Solve(){
    Try(0);
    cout << ((res == 0)?-1:res )<< '\n';
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

 