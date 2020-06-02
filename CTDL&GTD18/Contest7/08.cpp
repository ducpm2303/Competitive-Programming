/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Input(){
    getline(cin,s);
}
void Solve(){
    stack <int> st;
    //cout << s << '\n';
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')'){
            int pos = st.top(); st.pop();
            //cout << pos << '\n';
            if(pos >= 1 && s[pos-1] == '-'){
                for(int j = pos; j < i; j++){
                    if(s[j] == '+') s[j] = '-';
                    else if(s[j] == '-') s[j] = '+';
                    //cout << s[i] << ' ';
                }
            }
        }
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ')' && s[i] != '(')
            cout << s[i] ;
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t; cin.ignore();
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
