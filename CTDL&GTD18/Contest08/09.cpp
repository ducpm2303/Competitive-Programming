/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,t;
void Input(){
    cin >> s >> t;
}
/*
    tại mỗi một số
    1 -> 2 -> 
        2 -> 4 -> 3 -> 6
            4 -> 8

*/          
void Solve(){
    int vis[200005] = {0};
    queue < pair<ll,int> > q;
    // pair first là giá trị , second là số bước biến đổi từ s đến giá trị đó
    q.push(make_pair(s,0)); 
    vis[s] = 1;
    // 2 -> 1
    while(!q.empty()){
        pair<ll,int> x = q.front(); q.pop();
        if(x.first == t){ // nếu giá trị đang xét bằng t
            cout << x.second << '\n';
            return;
        }
        if(vis[x.first-1] == 0){
            vis[x.first-1] = 1;
            q.push({x.first-1,x.second+1});
        }
        if(vis[x.first*2] == 0 && x.first < t){
            vis[x.first*2] = 1;
            q.push({x.first*2,x.second+1});
        }
    }
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
