/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
char a[1005][1005];
int  cost[1005][1005];
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
int res = 1e9;

bool inside(int x,int y){
    return (2 <= x && x <= n - 1 && 1 <= y && y <= m);
}
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            cost[i][j] = 1e8;
        }
    }
}

void Solve(){
    deque<pii> q;
    q.push_front({0,0});
    cost[0][0] = 0;
    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second; 
        q.pop_front();
        if(u == 0 && v == 0){
            for(int i = 2; i <= n - 1; i++){
                if(a[i][1] == '#'){
                    cost[i][1] = cost[0][0];
                    q.push_front({i,1});
                }else{
                    cost[i][1] = cost[0][0] + 1;
                    q.push_back({i,1});
                }
            }
        }else{
            for(int i = 0; i < 8; i++){
                int x = u + dx[i];
                int y = v + dy[i];
                if(!inside(x,y)) continue;
                if (cost[x][y] < 1e8) continue;
                if(a[x][y] == '#'){
                    cost[x][y] = cost[u][v];
                    q.push_front({x,y});
                }else{
                    cost[x][y] = cost[u][v] + 1;
                    q.push_back({x,y});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        res = min(res,cost[i][m]);
    }
    cout << res << '\n';

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
