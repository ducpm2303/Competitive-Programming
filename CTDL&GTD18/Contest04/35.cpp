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
int n;
vi a;
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}   
/*

*/
void Solve(){
    if(*max_element(all(a)) < 0){
        cout << *max_element(all(a)) << '\n';
        return;
    }
    /*
    -2 -5 6 -2 -3 1 5 -6 
    sum = -2 < 0 -> sum = 0;
    sum = -5 < 0 -> sum = 0; 
    sum = 6 > 0 , res = max(6,0) = 6;
    sum = 6 + -2 = 4 > 0 ... 

    */
    ll res = 0,sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if( sum < 0) sum = 0;
        else res = max(res,sum);
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

 