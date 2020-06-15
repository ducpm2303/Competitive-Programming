/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[1001][1001];
int vis[1001][1001];
bool inside(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m);
}
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            vis[i][j] = 0;
        }
    }
}
void Solve(){

    queue<pair<pair<int,int>,int>>q;
    q.push({{1,1},0}); vis[1][1] = 1;
    int minstep = 1e9;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        if(x == n && y == m){
            minstep = min(minstep,z);
            continue;
        }
        //cout << x << ' ' << y << '\n';
        if(inside(x,y+a[x][y]) && vis[x][y+a[x][y]] == 0){
            vis[x][y+a[x][y]] = 1;
            q.push({{x,y+a[x][y]},z+1});
        }
        if(inside(x+a[x][y],y) && vis[x+a[x][y]][y] == 0){
            vis[x+a[x][y]][y] = 1;
            q.push({{x+a[x][y],y},z+1});
        }
    }
    if(minstep == 1e9) cout << -1 << '\n';
    else cout << minstep << '\n';
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
