/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void PRINT(stack < int > a){
    if(a.size() == 0){
        cout << "NONE" << '\n';
        return;
    }
    cout << a.top() << '\n';
}
void Input(){
   
}
void Solve(){
    int t;
    string s;
    stack<int> q;
    cin >> t;
    while(t--){
        cin >> s;
        if(s == "PUSH"){
            int x; cin >> x;
            q.push(x);
        }else if(s == "POP"){
            if(!q.empty()) q.pop();
        }else PRINT(q);
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
