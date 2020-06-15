/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Input(){
    cin >> s;
}
void Solve(){
    stack <char> st;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '('){
            st.push(s[i]);
        }else{
            if(!st.empty() && st.top() == '(') st.pop();
            else st.push(s[i]);
        }
    }
    int cnt = 0 , sz = st.size();
    while(!st.empty()){
        cnt += (st.top() == ')');
        st.pop();
    }
    cout << cnt/2 + (sz-cnt)/2 + 2*(cnt%2==1) << '\n';
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
