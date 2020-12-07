/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[105][105];
int dist[105][105];
int n;
int xd,yd,xc,yc;
void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            dist[i][j] = 1e9;
        }
    }
    cin >> xd >> yd >> xc >> yc;
    xd++, yd++, xc++, yc++;
    dist[xd][yd] = 0;
}

void Solve(){
    queue<pair<int,int>> q;
    q.push({xd,yd});
    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        // cout << u << ' ' << v << ' ' <<  dist[u][v] << '\n';
        for(int i = v + 1; i <= n && a[u][i] == '.'; i++){
            if(dist[u][v] + 1 < dist[u][i]){
                q.push({u,i});
                dist[u][i] = dist[u][v] + 1;
            }
        }
        for(int i = v - 1 ; i >= 1 && a[u][i] == '.'; i--){
            if(dist[u][v] + 1 < dist[u][i]){
                q.push({u,i});
                dist[u][i] = dist[u][v] + 1;
            }
        }
        for(int i = u + 1; i <= n && a[i][v] == '.'; i++){
            if(dist[u][v] + 1 < dist[i][v]){
                q.push({i,v});
                dist[i][v] = dist[u][v] + 1;
            }
        }
        for(int i = u - 1; i >= 1 && a[i][v] == '.'; i--){
            if(dist[u][v] + 1 < dist[i][v]){
                q.push({i,v});
                dist[i][v] = dist[u][v] + 1;
            }
        }
    }
    cout << dist[xc][yc];
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
