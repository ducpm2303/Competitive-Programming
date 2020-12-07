/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a(6),b(6);
void Input(){
    for(int i = 0; i < 6; i++) cin >> a[i];
    for(int i = 0; i < 6; i++) cin >> b[i];
}
vector<int> leftSquare(vector<int> u){
    int tmp = u[0];
    u[0] = u[3]; u[3] = u[4];
    u[4] = u[1]; u[1] = tmp;
    return u;
}
vector<int> rightSquare(vector<int> u){
    int tmp = u[1];
    u[1] = u[4]; u[4] = u[5];
    u[5] = u[2]; u[2] = tmp;
    return u;
}
void Solve(){
    map<vector<int>,int> f;
    queue<vector<int>> q;
    q.push(a); f[a] = 0;
    while(!q.empty()){
        vector<int> u = q.front(); q.pop();
        if(u == b){
            cout << f[u] << '\n';
            break;
        }
        vector<int> uLeft = leftSquare(u);
        vector<int> uRight = rightSquare(u);
    
        if(f.find(uLeft) == f.end()){
            q.push(uLeft);
            f[uLeft] = f[u] + 1;
        }
        if(f.find(uRight) == f.end()){
            q.push(uRight);
            f[uRight] = f[u] + 1;
        }
    }
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
