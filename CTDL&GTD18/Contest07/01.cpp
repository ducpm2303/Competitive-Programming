/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void show(stack < int> s){
    vector<int> tmp;
    while(!s.empty()){
        tmp.push_back(s.top());
        s.pop();
    }
    if(tmp.size() == 0){
        cout << "empty" << '\n';
        return;
    }
    reverse(tmp.begin(),tmp.end());
    for(int i = 0 ; i < tmp.size() ; i++) cout << tmp[i] << ' ';
    cout << '\n';
}
void Input(){

}
void Solve(){
    string s;
    int x;
    stack < int > st;
    while(cin >> s){
        if(s == "push"){
            int x ; cin >> x;
            st.push(x);
        } else if(s == "pop"){
            if(!st.empty()) st.pop();
        } else show(st);
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
