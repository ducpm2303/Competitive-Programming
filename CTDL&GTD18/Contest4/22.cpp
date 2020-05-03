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
int n,k;
vi a;
void Input(){
    cin >> n >> k;
    a.resize(n);
    for(auto &x : a) cin >> x;
}   
void Solve(){
    int l = 0 , r = n - 1, mid;
    while( l <= r){
        mid = l+r >> 1;
        if(a[mid] == k){
            cout << mid + 1<< '\n';
            return;
        }
        else if ( a[mid] > k) r = mid - 1;
        else l = mid + 1;
    }
    cout << "NO" << '\n';
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

 