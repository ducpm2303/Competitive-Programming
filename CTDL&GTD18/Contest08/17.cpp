/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,xd,yd,xc,yc;
char a[101][101];
int vis[101][101];
void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            vis[i][j] = 0;
        }
    }
    cin >> xd >> yd >> xc >> yc;
    xd++ , yd++ , xc++ , yc++;
}
void Solve(){

    queue< pair<pair<int,int>,int> >q;
    q.push({{xd,yd},0}); vis[xd][yd] = 1;
    int mincost = 1e9;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        //cout << x << ' ' << y << '\n';
        if(x == xc && y == yc){
            //cout << 1 << '\n';
            mincost = min(mincost,cost);
            continue;
        }
        for(int i = x - 1; i >= 1 && a[i][y] != 'X'; i--){
            if(vis[i][y] == 0){
                vis[i][y] = 1;
                q.push({{i,y},cost+1});
            }
        }
        for(int i = x + 1; i <= n && a[i][y] != 'X'; i++){
            if(vis[i][y] == 0){
                vis[i][y] = 1;
                q.push({{i,y},cost+1});
            }
        }
        for(int i = y - 1; i >= 1 && a[x][i] != 'X'; i--){
            if(vis[x][i] == 0){
                vis[x][i] = 1;
                q.push({{x,i},cost+1});
            }
        }
        for(int i = y + 1; i <= n && a[x][i] != 'X'; i++){
            if(vis[x][i] == 0){
                vis[x][i] = 1;
                q.push({{x,i},cost+1});
            }
        }
    }
    if(mincost == 1e9) cout << -1 << '\n';
    else cout << mincost << '\n';
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