#include<bits/stdc++.h>
using namespace std;

int test = 1 , MULTI_TEST = 1; 
int n, m,matrix[30][30],ans = -1;

void dfs(int u, int tmp){
    ans = max(ans,tmp);
    for (int v = 0; v < n; v++){
        if (matrix[u][v] == 1){
            matrix[u][v] = 0;
            matrix[v][u] = 0;
            dfs(v, tmp + 1);
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }
}
void Input(){
    cin >> n >> m; 
    int x,y;
    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
} 
void Solve(){
    ans = -1;
    for (int i = 0; i < n; i++) dfs(i,0);
    cout << ans << '\n';
}

int main(){
    
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}