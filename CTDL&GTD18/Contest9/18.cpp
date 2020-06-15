#include <iostream>
#include<queue>
using namespace std;
int n , m,vis[1001];
vector<int> ke[1001];
void LoadG(){
    cin >> n >> m; 
    for(int i = 1; i <= n; i++)
        ke[i].clear();
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        ke[u].push_back(v);
    }
}
void reset(){
    for(int i = 1 ; i <= n ; i++) 
        vis[i] = 0;
}
int BFS(int u){
    int cnt = 0;
    queue<int> q;  
    q.push(u); vis[u] = 1;
    while(!q.empty()){
        cnt++;
        int u1 = q.front() ; q.pop(); 
        //cout << u1 << ' '; 
        for(auto v : ke[u1]){
            if(vis[v] == 0){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return cnt;
}
bool LT_manh_BFS(){
    int res = 0;
    for(int i = 1 ; i <= n ; i++){
        reset(); 
        if( BFS(i) != n ) return false; 
    }
    return true;  
}
int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        LoadG();
        reset() ; cout << ((LT_manh_BFS() == 1)?"YES":"NO") << '\n';
    }
    return 0;
}