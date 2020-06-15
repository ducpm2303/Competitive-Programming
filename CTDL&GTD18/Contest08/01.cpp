/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Input(){
   
}
void Solve(){
    queue <int> q;
    cin >> n;
    while(n--){
        int type; cin >> type;
        switch(type){
            case 1 : cout << q.size() << '\n'; break;
            case 2 : cout << (q.empty()?"YES":"NO") << '\n';break;
            case 3 : int x; cin >> x; q.push(x); break;
            case 4 : if(!q.empty()) q.pop(); break;
            case 5 : cout << (q.empty()?-1:q.front()) << '\n'; break;
            case 6 : cout << (q.empty()?-1:q.back()) << '\n'; break;
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
