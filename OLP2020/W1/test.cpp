/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char a[1005][1005];
int b[1005][1005];
vector<int> d;
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
vector<vector<pair<int,int>>> ke;
priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
int res = 1e9;
void Input(){
    cin >> n >> m;
    ke.assign(m*(n-2) + 3, vector<pair<int,int>>());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}

bool inside(int x,int y){
    return (2 <= x && x <= n - 1 && 0 <= y && y <= m);
}
void Dijsktra(int k){
    d.assign((n-2)*m + 5,1e8);
    int s = b[k][1];
    if(a[k][1] == '#'){
        q.push({0,s});
        d[s] = 0;
    }
    else{
        q.push({1,s});
        d[s] = 1;
    }
    while(!q.empty()){
        int u = q.top().second;
        int w = q.top().first;
        q.pop();
        // cout << u << "->" << w << '\n';
        if(w != d[u]) continue;
        for(auto z : ke[u]){
            int v = z.second;
            int uv = z.first;
            if(d[v] > uv + d[u]){
                d[v] = uv + d[u]; 
                q.push({d[v],v});  
            }
        }
    }
    for(int i = m; i <= m*(n-2); i += m){
        //cout << s << "->"  << i << ' ' << d[i] << '\n'; 
        res = min(res,d[i]);
    }

}
void Solve(){
    int cnt = 1;
    for(int i = 2; i <= n - 1; i++){
        for(int j = 1; j <= m; j++){
            b[i][j] = cnt;
            //cout << b[i][j] << ' ';
            cnt ++;
        }
        //cout << '\n';
    }
    for(int i = 2 ; i <= n - 1; i++){
        if(a[i][1] == '#')
            ke[0].push_back({0,b[i][1]});
        else 
            ke[0].push_back({1,b[i][1]});
    }

    for(int i = 2; i <= n - 1; i++){
        for(int j = 1; j <= m;   j++){
            for(int k = 0; k < 8; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(inside(nx,ny)){
                    if(a[nx][ny] == '#')
                        ke[b[i][j]].push_back({0,b[nx][ny]});
                    else 
                        ke[b[i][j]].push_back({1,b[nx][ny]});
                }
            }
        }
    }
    //cout << maxnm << '\n';
    Dijsktra(0);
    cout << res - 1 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}