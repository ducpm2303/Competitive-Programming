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
int n,k,sum = 0;
vector < int > a;
vector < int > vis;
void Input(){
    cin >> n >> k;
    a.resize(n); vis.assign(n+1,0);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
}
void Try(int i , int s,vector<int> z){
    if( s > sum ) return;
    if (s == sum && z.size() != 0){
        k--;
        for(auto zz : z){
            vis[zz] = 1;
            //cout << a[zz] << ' ';
        }
        //cout << '\n';
        return;
    }
    for(int j = i + 1 ; j < n ; j++){
        if( vis[j] == 0){
            z.push_back(j); // luu id
            Try(j,s+a[j],z);
            z.pop_back();
        }
    }
    
}
void Solve(){
    sum = 0;
    for(int i = 0 ; i < n ; i++) sum += a[i];
    if( sum % k != 0){
        cout << 0 << '\n';
        return;
    }
    vector < int > tmp; // move
    sum /= k;
    if ( *max_element(all(a)) > sum){
        cout << 0 << '\n';
        return;
    }
    //cout << sum << endl;
    Try(-1,0,tmp);
    cout << ( k <= 0 ) << '\n';
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

 