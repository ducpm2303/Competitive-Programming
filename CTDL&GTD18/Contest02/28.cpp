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
int n,s, ok = 0;
vector < int > a;
void Try(int i , int sum , vector < ii > mv){
    if( sum == 0 && mv.size() != 0){
        cout << '[';
        ok = 1;
        vector<ii>::iterator pos;  
        for(pos = mv.begin() ; pos < mv.end() ; pos++){
            for(int zz = 1 ; zz <= pos->second ; zz++){
                cout << pos->first;
                if(zz == pos->second  && pos == (mv.end() - 1) ) cout << ']';
                else cout << ' ';
            }
        }
        return;
    }
    if( i == n ) return;
    for(int j = (sum/a[i]); j >= 0 ; j--){
        mv.push_back({a[i],j});
        Try(i+1,sum-j*a[i],mv);
        mv.pop_back();
    }
}
void Input(){
    cin >> n >> s; a.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

}   
void Solve(){
    ok = 0;
    sort(all(a));
    vector < ii> move;
    Try(0,s,move);
    if( ok == 0) cout << -1;
    cout << '\n';
}
int main(){
    setIO();
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 