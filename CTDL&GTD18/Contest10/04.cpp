//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
typedef pair < int,int > pii;
int n,m,r1,c1,r2,c2;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char a[505][505];
int f[505][505];
void input(){
    cin >> n >> m; 
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j ++){
            cin >> a[i][j];
            if ( a[i][j] == 'S') r1 = i , c1 = j;
            if ( a[i][j] == 'T') r2 = i , c2 = j;
        }
    }
}
bool move(){
    memset(f, -1, sizeof(f));
    queue< pii > q;
    auto enqueue = [&](int i, int j, int e) {
        if (f[i][j] == -1) {
        f[i][j] = e;
        q.push({i, j});
        }
    };
    enqueue(r1, c1, 0);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int r = u.first, c = u.second;
        if (f[r][c] > 3) return false;
        if (r == r2 && c == c2) return true;
        int e = f[r][c] + 1;
        for (int i = r; i <= n && a[i][c] != '*'; i++) enqueue(i, c, e);
        for (int i = r; i >= 1 && a[i][c] != '*'; i--) enqueue(i, c, e);
        for (int j = c; j <= m && a[r][j] != '*'; j++) enqueue(r, j, e);
        for (int j = c; j >= 1 && a[r][j] != '*'; j--) enqueue(r, j, e);
    }
    return false;
}
void solve(){
    cout <<  (move()? "YES" : "NO")  << endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();int t=1; 
    cin>>t; cin.ignore();
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD
  