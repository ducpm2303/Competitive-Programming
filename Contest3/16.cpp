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
int s,d; 
void Input(){
    cin >> s >> d;
}   
void Solve(){
    int x = s/d;
    int y = s - x*d; 
    if( s > 9*d ) {
        cout << -1 << '\n';
        return;
    }
    //cout << x << ' ' << y << endl;
    int a[d+5] ;
    for(int i = 0 ; i < d ; i++) a[i] = x;
    if( x == 0 ) a[0] = 1 , y--;
    int pos = d - 1 ;
    for(int i = d - 1 ; i >= 0 , y > 0; i--){
        while(a[i] < 9 && y > 0) a[i]++ , y--;
        if( a[i] == 9) pos = i - 1;
    }
    while(a[0] > 1 && pos != 0 && a[pos] < 9){
        a[0]--; a[pos]++;
        if(a[pos] == 9) pos--;
    }
    for(int i = 1 ; i < d ; i++){
        if(i >= pos) break;
        while(a[i] != 0 && pos != i && a[pos] < 9){
            a[i]--; a[pos]++;
            if(a[pos] == 9) pos--;
        }
    }
    for(int i = 0 ; i < d ; i++)
        cout << a[i];
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

 