/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
int test = 1 , MULTI_TEST = 1;
int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[]= {1,1,0,-1,-1,-1,0,1};
char mp[100][100];
int vis[100][100] = {0};
int k,m,n;
vector < string > a;
vector < vector<char> > res;
bool inside(int u , int v){
    return ( 1 <= u && u <= n && 1 <= v && v <= m);
}
string toString(vector<char> s){
    string res = "";
    for(int i = 0; i < s.size(); i++){
        res += s[i];
    }
    return res;
}
void DFS(int x , int y , vector<char> s){
    vis[x][y] = 1;
    s.push_back(mp[x][y]);
    for(int i = 0 ; i < a.size() ; i++){
        if(toString(s) == a[i]){
            res.push_back(s);
            break;
        }
    }
    for(int i = 0 ; i < 8 ; i++){
        int u = x + dx[i];
        int v = y + dy[i];
        if( inside(u,v) && vis[u][v] == 0) 
            DFS(u,v,s);
    }
    s.pop_back();
    vis[x][y] = 0;
}
void Input(){
    cin >> k >> m >> n;
    a.resize(k); res.clear();
    for(int i = 0 ; i < k ; i++)
        cin >> a[i];

    for(int i =  1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            vis[i][j] = 0;
            cin >> mp[i][j];
        }
    }
}  
void Solve(){
    vector<char> tmp;  
    for(int i =  1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            DFS(i,j,tmp);   
        }
    }
    if ( res.size() == 0 ){
        cout << -1 << '\n';
        return;
    }
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size() ; j++){
            cout << res[i][j];
        }
        cout << ' ';
    }
    cout << '\n';
}
int main(){
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 