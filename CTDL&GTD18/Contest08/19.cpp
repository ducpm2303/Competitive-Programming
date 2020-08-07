/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char m[51][51][51];
int vis[51][51][51];
int a,b,c,xd,yd,zd,xc,yc,zc;
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
struct duc{
    int x,y,z,t;
};
duc make_duc(int x,int y,int z, int t){
    duc res;
    res.x = x;
    res.y = y;
    res.z = z;
    res.t = t;
    return res;
}

void Input(){
    cin >> a >> b >> c;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= c; k++){
                cin >> m[i][j][k];
                vis[i][j][k] = 0;
                if(m[i][j][k] == 'S'){
                    xd = i;
                    yd = j;
                    zd = k;
                }
                if(m[i][j][k] == 'E'){
                    xc = i;
                    yc = j;
                    zc = k;
                }
            }
        }
    }
}
bool inside(int x,int y,int z){
    return(1 <= x && x <= a && 1 <= y && y <= b && 1 <= z && z <= c);
}
void Solve(){
    queue<duc> q;
    q.push(make_duc(xd,yd,zd,0));
    vis[xd][yd][zd] = 1;
    //cout << xc << ' ' << yc << ' ' << zc;
    int mincost = 1e9;
    while(!q.empty()){
        duc topq = q.front();
        int u = topq.x;
        int v = topq.y;
        int w = topq.z;
        int c = topq.t;
        q.pop();
        //cout << u << ' ' << v << ' ' << w << ' ' << c << '\n';
        if(u == xc && v == yc && w == zc){
            mincost = min(mincost,c);
            continue;
        }
        for(int i = 0; i < 6; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            int z = w + dz[i];
            if(inside(x,y,z) && m[x][y][z] != '#' && vis[x][y][z] == 0){
                vis[x][y][z] = 1;
                q.push(make_duc(x,y,z,c+1));
            }
        }
    }
    cout << ((mincost == 1e9)?-1:mincost) << '\n';
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