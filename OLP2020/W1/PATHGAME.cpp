//Code By PMD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,u,v;
char a[1005][1005];
int cost[1005][1005];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
bool inside(int u,int v){
    return (1 <= u && u <= n && 1 <= v && v <= m);
}
void printCost(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}
vector<pair<int,int>> pos;
void BFS(){
    queue<pair<int,int>> q;
    for(int i = 0 ; i < pos.size(); i++)
        q.push(pos[i]);
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //cout << x << ' ' << y << '\n';
        //d[x][y]++;
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(!inside(nx,ny)) continue;
            if(a[x][y] == a[nx][ny]){
                if(cost[nx][ny] > cost[x][y] || cost[nx][ny] == INT_MAX){
                    cost[nx][ny] = cost[x][y];
                    q.push({nx,ny});
                }
            }else{
                if(cost[nx][ny] > cost[x][y] + 1){
                    cost[nx][ny] = cost[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    //printCost();
}
void Input(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cost[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == '*'){
                pos.push_back({i,j});
                cost[i][j] = 0;
            }
        }
    }

}
void Solve(){ 
    BFS();
    for(int i = 1; i <= q; i++){
        int x,y; cin >> x >> y;
        cout << cost[x][y] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    //freopen("test.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t = 1; 
    //cin>>t;  
    while(t--){ 
        Input();
        Solve();
    }
    return 0;
}
//Code By PMD