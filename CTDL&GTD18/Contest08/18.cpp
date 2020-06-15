/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[505][505];
int c[505][505];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            c[i][j] = -1;
        }
    }
}
bool inside(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m);
}
void Solve(){
    queue<pair<pair<int,int>,int>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 2) q.push({{i,j},0});
        }
    }
    while(!q.empty()){
        int u = q.front().first.first;
        int v = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if(inside(x,y) && a[x][y] == 1){
                a[x][y] = -1;
                c[x][y] = cost + 1;
                q.push({{x,y},cost+1});
            }
        }
    }
    int maxcost = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1){
                cout << -1 << '\n';
                return;
            }
            if(a[i][j] == -1){
                maxcost = max(maxcost,c[i][j]);
            }
        }
    }
    cout << maxcost << '\n';
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
