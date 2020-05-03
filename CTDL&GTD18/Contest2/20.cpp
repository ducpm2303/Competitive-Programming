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
vector < int > a;
vector < vector<int> > res;
int n;
void Try(vector < int > b){
    vector < int > c;
    res.push_back(b);
    for(int i = 0 ; i < b.size() - 1; i++)
        c.push_back(b[i]+b[i+1]);
    if( c.size() !=0 ) Try(c);
}
void Input(){
    cin >> n ; a.resize(n); res.clear();
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
}   
void Solve(){
    Try(a);
    for(int i = res.size() - 1 ; i >= 0 ; i--){
        cout << '[';
        for(int j = 0 ; j < res[i].size() - 1 ; j++){
            cout << res[i][j] << ' ';
        }
        cout << res[i].back() << ']' << ' ';
    }
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

 