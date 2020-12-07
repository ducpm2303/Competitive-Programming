/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a = "0000000000";
string f = "1238004765";
bool check = false;
map<string,int> startt;
map<string,int> endddd;
void Input(){
    for(int i = 0; i < 10; i++) cin >> a[i];
}
string turnLeft(string a){
    char tmp = a[0];
    a[0] = a[3], a[3] = a[7], a[7] = a[8];
    a[8] = a[5], a[5] = a[1], a[1] = tmp;
    return a;
}
string turnRight(string a){
    char tmp = a[1];
    a[1] = a[4], a[4] = a[8], a[8] = a[9];
    a[9] = a[6], a[6] = a[2], a[2] = tmp;
    return a;
}
string turnLeft2(string a){
    char tmp = a[0];
    a[0] = a[1]; a[1] = a[5]; a[5] = a[8];
    a[8] = a[7]; a[7] = a[3]; a[3] = tmp;
    return a;
}
string turnRight2(string a){
    char tmp = a[1];
    a[1] = a[2]; a[2] = a[6]; a[6] = a[9];
    a[9] = a[8]; a[8] = a[4]; a[4] = tmp;
    return a;
}
void BFS_1(){
    queue<string>q;
    q.push(a);
    while(!q.empty()){
        string u = q.front(); q.pop();
        int d = startt[u];
        //cout << u << '\n';
        if(u == f){
            cout << d;
            check = true;
            return;
        }
        if(d == 15) return;
        string x = turnLeft(u);
        string y = turnRight(u);
        if(startt.find(y) == startt.end()){ startt[y] = d + 1; q.push(y);}
        if(startt.find(x) == startt.end()){ startt[x] = d + 1; q.push(x);}
    }
    
}
void BFS_2(){
    queue<string>q;
    q.push(f); endddd[f] = 0;
    int res = 1e9;
    while(!q.empty()){
        string u = q.front(); q.pop();
        int d = endddd[u];
        //cout << u << '\n';
        if(d == 15) break;
        if(startt.find(u) != startt.end())
            res = min(res,startt[u] + endddd[u]);
        string x = turnLeft2(u);
        string y = turnRight2(u);
        if(endddd.find(y) == endddd.end()){ endddd[y] = d + 1; q.push(y);}
        if(endddd.find(x) == endddd.end()){ endddd[x] = d + 1; q.push(x);}
    }
    cout << res;
}
void Solve(){
    BFS_1();
    if(!check) BFS_2();
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