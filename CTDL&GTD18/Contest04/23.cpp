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
ll n,k;
/*
1213121412131215121312141213121
v? trí :
1 -> 1 3  5  7  9  11 ...
2 -> 2 6  10 14 18 22 ...
3 -> 4 12 20 28 36 44 ...
4 -> 8 24 40 56 72  .....
5 -> 16 48 80 .......
    32
    64
    ...
ví d? k = 15 -> 1
k = 16
i = 1.
(k - 2^i) % 2^i.
*/

void Input(){
    cin >> n >> k;
}   
void Solve(){
    ll i = 1;
    while((k-i)%(i*2) != 0){
        i *= 2;
    }
    cout << log2(i) + 1 << '\n';
 
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
 
  