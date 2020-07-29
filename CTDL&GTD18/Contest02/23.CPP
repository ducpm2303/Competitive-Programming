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
int m[20][20];
int vis[20][20] = {0};
int n;
vector < vector<char> > res;
void Try(int x , int y , vector<char> s){
    if(x == n && y == n){
        res.push_back(s);
        return;
    }
    if(m[x][y+1] == 1 && vis[x][y+1] == 0){ // ben phai
        s.push_back('R');
        vis[x][y+1] = 1;
        Try(x,y+1,s);
        s.pop_back();
        vis[x][y+1] = 0;
    }
    if(m[x+1][y] == 1 && vis[x+1][y] == 0){
        s.push_back('D');
        vis[x+1][y] = 1;
        Try(x+1,y,s);
        s.pop_back();
        vis[x+1][y] = 0;
    }
    if(m[x][y-1] == 1 && vis[x][y-1] == 0){
        s.push_back('L');
        vis[x][y-1] = 1;
        Try(x,y-1,s);
        s.pop_back();
        vis[x][y-1] = 0;
    }
    if(m[x-1][y] == 1 && vis[x-1][y] == 0){
        s.push_back('U');
        vis[x-1][y]  = 1;
        Try(x-1,y,s);
        s.pop_back();
        vis[x-1][y]  = 0;
    }
    
}
void Input(){
    memset(vis,0,sizeof(vis));
    cin >> n;  res.clear();
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> m[i][j];
        }
    }
}   
void Solve(){
    string tmp = "";
    if(m[1][1] == 1){
        vis[1][1] = 1;
        Try(1,1,tmp);
    }
    if( res.size() == 0 ){
        cout << -1 << '\n';
        return;
    }
    sort(all(res));
    for(int i = 0 ; i < res.size() ; i++){
        cout << res[i] << ' ';
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

 