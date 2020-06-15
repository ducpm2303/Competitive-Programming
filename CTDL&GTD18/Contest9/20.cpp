#include <bits/stdc++.h>
using namespace std;
int n,m,vis[1001];
int a[1001][1001];
void LoadG(){
    cin >> n >> m; 
    memset(a,0,sizeof(a));
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
}
void reset(){
    for(int i = 1 ; i <= n ; i++) 
        vis[i] = 0;
}

int BFS(int u){
    queue<int> q; 
    int cnt = 0; 
    q.push(u); vis[u] = 1;
    while(!q.empty()){
        int u1 = q.front() ; q.pop();  
        cnt++;
        for(int v = 1 ; v <= n ; v++){
            if(a[u1][v] == 1 && vis[v] == 0){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return cnt;
}
void Dinh_tru_BFS(){
    int flag = 0;
    for(int i = 1 ; i <= n ; i++){
        int mark[n+1] = {0};
        for(int j = 1 ; j <= n ; j++){
            if(a[i][j] == 1){
                mark[j] = 1;
                a[i][j] = a[j][i] = 0;
            }
        }

        reset(); vis[i] = 1;
        int u = ((i == 1)?2:1);
        if( BFS(u) != n - 1){
             cout << i << ' ';
             flag = 1;
        }
        vis[i] = 0;
        for(int j = 1 ; j <= n ; j++){
            if(mark[j] == 1)
                a[i][j] = a[j][i] = 1;
        }
    }
    if(flag == 0) cout << -1 ;
}
int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        LoadG();
        reset() ; Dinh_tru_BFS();
        cout << '\n';
    }
    return 0;
}
