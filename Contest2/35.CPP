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
int n,s,k,res = 0; 
void Try(int i , int k , int sum){
    if ( sum > s || k < 0) return;
    if( k == 0 && sum == s){
        res++;
        return;
    }
    for(int j = i + 1 ; j <= n ; j++)
        Try(j,k-1,sum+j);
}
void Input(){

}   
void Solve(){
    while(1){
        cin >> n >> k >> s;
        res = 0;
        if( n == 0 && s == 0 && k == 0){
            return;
        }
        Try(0,k,0);
        cout << res << '\n';
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

 