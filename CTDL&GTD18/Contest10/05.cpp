//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
typedef pair < int , int > pii;
typedef tuple < int,int,int,int> ti4;
int n,m,k;
map < ti4 , bool > isFence;
int a[205][405] = {0};
int vis[205][205] = {0};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector < i64 > res;
vector < pii > sheep;
bool inside(int x , int y){
    return ( 1 <= x && x <= n && 1 <= y && y <= n);
}
void BFS(int r , int c){
    int cnt = 0;
    queue < pii > q;    
    q.push({r,c}); vis[r][c] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int u = x + dx[i];
            int v = y + dy[i];
            if ( inside(u,v)  && vis[u][v] == 0 && isFence[make_tuple(x,y,u,v)] == false ){
                q.push({u,v});
                vis[u][v] = 1;
                cnt += a[u][v];
            }
        }
    }
    res.push_back(cnt+1);
}
 
void input(){
    cin >> n >> k >> m;
    sheep.resize(k);
    for(int i = 1 ; i <= m; i++){
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        isFence[make_tuple(u,v,x,y)] = true;
        isFence[make_tuple(x,y,u,v)] = true;
    }
    for(auto &x : sheep){
        cin >> x.first >> x.second ;
        a[x.first][x.second] = 1;
    }
     
}
void solve(){
    for(auto x : sheep){
        if(vis[x.first][x.second] == 0)
            BFS(x.first,x.second);
    }
    //display();
    //cerr << "\nRunning is : " << 1.0*clock()/1000 ;
     vector < i64 > dp(res.size() + 1 , 0);
    for(int i = 1 ; i <= res.size() ; i++)
        dp[i] = dp[i-1] + res[i-1];
    i64 ans = 0;
    for(int i = 0 ; i < res.size() - 1 ; i++)
        ans += 1LL*res[i]*(dp[res.size()] - dp[i+1]);
        //cout << res[i] << ' ' << dp[res.size()] - dp[i+1] << endl;
    cout << ans ;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();int t=1; 
    //cin>>t; cin.ignore();
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD 