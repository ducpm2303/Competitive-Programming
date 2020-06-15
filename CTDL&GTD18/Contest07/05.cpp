/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Control(stack <pair<char,int>> st){
    vector<int> pos;
    while(!st.empty()){
        pos.push_back(st.top().second);
        st.pop();
    }
    reverse(pos.begin(),pos.end());
    int res = 0;
    for(int i = 0; i < pos.size() - 1; ++i){
        res = max(res,pos[i+1] - pos[i] - 1);
    }
    cout << res << '\n';
}
void Input(){
    cin >> s;
}
void Solve(){
    s = ')' + s + '(';
    stack <pair<char,int>> st;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '(') st.push({'(',i});
        else{
            if(!st.empty() && st.top().first == '(')
                st.pop();
            else st.push({')',i});
        }
    }
    Control(st);
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
