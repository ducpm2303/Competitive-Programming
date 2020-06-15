/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Input(){
    cin >> s;
}
void Solve(){
    stack < char > st;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
            st.push(s[i]);
        }else{
            if(!st.empty() && ((s[i] == ')' && st.top() == '(')
                            || (s[i] == '}' && st.top() == '{')
                            || (s[i] == ']' && st.top() == '[')))
                st.pop();
            else st.push(s[i]);
        }
    }
    int sz = st.size();
    cout << ((sz==0)?"YES":"NO") << '\n';
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
