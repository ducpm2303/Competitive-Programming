/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Input(){

}
void Solve(){
    int n; cin >> n;
    queue <int> q;
    while(n--){
        string s; cin >> s;
        if(s == "PUSH"){
            int x; cin >> x;
            q.push(x);
        }else if(s == "PRINTFRONT"){
            if(!q.empty()) cout << q.front() << '\n';
            else cout << "NONE" << '\n';
        }else{
            if(!q.empty()) q.pop();
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
