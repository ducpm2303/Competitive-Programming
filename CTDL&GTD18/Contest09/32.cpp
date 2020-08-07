/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[505][505];
int vis[505][505];
int dx[]= {1,-1,0,0,1,1,-1,-1};
int dy[]= {0,0,1,-1,1,-1,1,-1};
int n,m;
bool inside(int x,int y){
    return(1 <= x && x <= n && 1 <= y && y <= m);
}
void BFS(int x,int y){
    queue<pair<int,int> > q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int u1 = u + dx[i];
            int v1 = v + dy[i];
            if(inside(u1,v1) && vis[u1][v1] == 0 && a[u1][v1] == 1){
                q.push({u1,v1});
                vis[u1][v1] = 1;
            }
        }
    }
}
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            vis[i][j] = 0;
            cin >> a[i][j];
        }
    }
}
void Solve(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1 && vis[i][j] == 0){
                BFS(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
