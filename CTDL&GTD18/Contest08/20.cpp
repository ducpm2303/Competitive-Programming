/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a = "0000000000";
string f = "1238004765";
map<string,int> stp;
void Input(){
    stp.clear();
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
void Solve(){
    queue<string>q;
    q.push(a);
    while(!q.empty()){
        string u = q.front(); q.pop();
        int d = stp[u];
        //cout << u << '\n';
        if(u == f) break;
        string x = turnLeft(u);
        string y = turnRight(u);
        if(stp.find(x) == stp.end()){ stp[x] = d + 1; q.push(x);}
        if(stp.find(y) == stp.end()){ stp[y] = d + 1; q.push(y);}
    }
    cout << stp[f] << '\n';
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