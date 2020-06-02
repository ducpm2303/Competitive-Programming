/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Input(){

}
void Solve(){
    int n; cin >> n;
    deque <int> q;
    while(n--){
        string s; cin >> s;
        if(s == "PUSHFRONT"){
            int x; cin >> x;
            q.push_front(x);
        }else if(s == "PRINTFRONT"){
            if(!q.empty()) cout << q.front() << '\n';
            else cout << "NONE" << '\n';
        }else if(s == "POPFRONT"){
            if(!q.empty()) q.pop_front();
        }else if(s =="PUSHBACK"){
            int x; cin >> x;
            q.push_back(x);
        }else if(s == "PRINTBACK"){
            if(!q.empty()) cout << q.back() << '\n';
            else cout << "NONE" << '\n';
        }else if(s == "POPBACK"){
            if(!q.empty()) q.pop_back();
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
